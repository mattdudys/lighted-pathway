//SLAVE 1
#include "uart.h"
#include "rprintf.h"
#include <string.h>
#include "i2c.h"
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "patterns.h"
#include "displayable.h"
#include "../master/command.h"
#include <stdbool.h> 
#include <avr/pgmspace.h>
#include <inttypes.h>
#include <math.h>

#define MAXBUF 24
#define RETURN  0x0D
#define LOCAL_ADDR 0x45

int nB = 0;
//int i=0;
char uBuf[MAXBUF];

void i2cTest(void);
void i2cSlaveReceiveService(u08 receiveDataLength, u08* receiveData);
uint8_t i2cSlaveTransmitService(u08 transmitDataLengthMax, u08* transmitData);
void i2cMasterSendDiag(u08 deviceAddr, u08 length, u08* data);
void addMessage(uint8_t id, const char *message, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop); 
void addImage(uint8_t id, const pattern_t* pat, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop);
void changeVisibility(uint8_t id, bool visible);
void exclusivelyShow(uint8_t id);
void test(void);

// local data buffer
char *localBuffer;
uint8_t localBufferLength = 0xff;

#define WIDTH 32
#define HEIGHT 16
#define BOARDROWS 16
#define BOARDCOLS 8
#define ID 1 
#define ROW (ID-1) / 15
#define COL (ID-1) % 15
#define ROWOFFSET ROW * BOARDROWS
#define COLOFFSET COL * BOARDCOLS
#define LISTCAPACITY 16 
#define TOTALPATTERNS 13

pattern_t commencement;
pattern_t congrats;
pattern_t dearmichelle;
pattern_t gobobcats;
pattern_t hperror;
pattern_t ns;
pattern_t proggy;
pattern_t soe;
pattern_t ssha;
pattern_t ucmerced;
pattern_t ucmlogo;
pattern_t welcomemichelle;
pattern_t welcome;

font_t proggyFont;
displayable_t *displayList[LISTCAPACITY];
pattern_t* patternList[TOTALPATTERNS];
uint8_t listSize;

// This points to the pattern we want to display.
volatile pattern_t *displaying;
volatile double frameDelay;
volatile int32_t frame;

void printLine(const uint8_t line) {
	uint8_t mask;
	char bits[9];
	bits[9] = '\0';
	for (int i = 0; i < 8; i++) {
		mask = 0x01 << (7-i);
		if ((mask & line) == 0) {
			bits[i] = ' ';
		} else {
			bits[i] = '*';
		}
	}
	//printf("%s\n", bits);
}

void init(void) {
	// Clear screen
	PORTA = 0xff;
	for(uint8_t i=0;i<8;i++)
	{
		PORTB = (0x01 << i);
		PORTA = 0xff;
		_delay_ms(5);
		PORTB = 0x00;
	}
	for(uint8_t i=0;i<8;i++)
	{
		PORTD = (0x01<<i);
		PORTA = 0xff;
		_delay_ms(5);
		PORTD = 0x00;
	}
	// Clear out displayList
	for (uint8_t i = 0; i < 8; i++) {
		displayList[i] = NULL;
	}

	localBuffer = (char*) malloc(256 * sizeof(char));

	// Init patterns and fonts.
	// Pattern list contains all the patterns on the chip. Add image uses this to look up pattern memory locations.
	initPattern(&commencement, 32, 120, COMMENCEMENT);
	patternList[0] = &commencement;
	initPattern(&congrats, 32, 120, CONGRATS);
	patternList[1] = &congrats;
	initPattern(&dearmichelle, 32, 120, DEARMICHELLE);
	patternList[2] = &dearmichelle;
	initPattern(&gobobcats, 32, 120, GOBOBCATS);
	patternList[3] = &gobobcats;
	initPattern(&ns, 32, 120, NS);
	patternList[4] = &ns;
	initPattern(&soe, 32, 120, SOE);
	patternList[5] = &soe;
	initPattern(&ssha, 32, 120, SSHA);
	patternList[6] = &ssha;
	initPattern(&ucmlogo, 32, 120, UCMLOGO);
	patternList[7] = &ucmlogo;
	initPattern(&welcome, 32, 120, WELCOME);
	patternList[8] = &welcome;
	initPattern(&welcomemichelle, 32, 120, WELCOMEMICHELLE);
	patternList[9] = &welcomemichelle;
	initPattern(&ucmerced, 32, 192, UCMERCED);
	patternList[10] = &ucmerced;
	initPattern(&proggy, 22, 1144, PROGGY);
	patternList[11] = &proggy;
	initPattern(&hperror, 32, 392, HPERROR);
	patternList[12] = &hperror;
	initFont(&proggyFont, 12, &proggy);
	listSize = 0;

	pattern_t* p;
	// Add all the patterns to the display list, but make them invisible.
	for (int i = 0; i < 10; i++) {
		p = patternList[i];
		addImage(i, p, 0, 0, 0, 120, -1, -p->cols, true);
		changeVisibility(i, false);
	}
}

void clear(void) {
	PORTA = 0xff;
	PORTD = 0xff;
	PORTB = 0xff;
	_delay_ms(15);
	PORTD = 0x00;
	PORTB = 0x00;
}

void allOn(void) {
	PORTA = 0x00;
	PORTD = 0xff;
	PORTB = 0xff;
	_delay_ms(15);
	PORTD = 0x00;
	PORTB = 0x00;
}

/* Should be called after setting frame. Calculates row and col offsets based on frame number. */
void updateOffsets(void) {
	// use frame to calculate offsets for all patterns in the display list.
	displayable_t *current;
	int32_t frameDiff;
	for (uint8_t i = 0; i < listSize; i++) {
		current = displayList[i];
		if (	(current->rowOffsetStep < 0 && current->rowOffset <= current->endRowOffset && !current->loop) ||
				(current->rowOffsetStep > 0 && current->rowOffset >= current->endRowOffset && !current->loop)	)
			continue;
		frameDiff = current->endRowOffset - current->startRowOffset;
		if (frameDiff < 0) frameDiff = -frameDiff;
		current->rowOffset = current->startRowOffset + (frame % frameDiff) * current->rowOffsetStep; 
	}	
	for (uint8_t i = 0; i < listSize; i++) {
		current = displayList[i];
		if (	(current->colOffsetStep < 0 && current->colOffset <= current->endColOffset && !current->loop) ||
				(current->colOffsetStep > 0 && current->colOffset >= current->endColOffset && !current->loop)	)
			continue;
		frameDiff = current->endColOffset - current->startColOffset;
		if (frameDiff < 0) frameDiff = -frameDiff;
		current->colOffset = current->startColOffset + (frame % frameDiff) * current->colOffsetStep; 
	}	
}

/* Combines the overlapping line patterns in the display list. */
uint8_t getCombinedLine(int32_t row, int32_t col) {
	uint8_t line = 0xff;
	uint8_t temp;
	for (uint8_t d = 0; d < listSize; d++) {
		if (!displayList[d]->visible) continue;
		temp = getDisplayableLine(displayList[d], row, col);
		if (displayList[d]->invert) temp = ~temp;
		line &= (uint8_t) temp;
	}
	return line;
}

/* Actually changes the LEDs on the board to reflect the displayables in the display list. */
void draw(void) {
	uint32_t row, col;
#if ROW == 0
	for (uint8_t i = 0; i < 8; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTB = 0x01 << i;
		PORTA = getCombinedLine(row, col);
		_delay_ms(0.1);
		PORTB = 0;
		//PORTA = 0xff;
		_delay_ms(0.1);
	}
	for (uint8_t i = 8; i < 16; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTD = 0x01 << (i - 8);
		PORTA = getCombinedLine(row, col);
		_delay_ms(0.1);
		PORTD = 0;
		//PORTA = 0xff;
		_delay_ms(0.1);
	}
#else
	// bottom
	for (uint8_t i = 0; i < 8; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTD = 0x01 << (7 - i);
		PORTA = reversed(getCombinedLine(row, col));
		_delay_ms(0.1);
		PORTD = 0;
		//PORTA = 0xff;
		_delay_ms(0.1);
	}
	for (uint8_t i = 8; i < 16; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTB = 0x01 << (15 - i);
		PORTA = reversed(getCombinedLine(row, col));
		_delay_ms(0.1);
		PORTB = 0;
		//PORTA = 0xff;
		_delay_ms(0.1);
	}
#endif				
}

void addDisplayable(displayable_t* d) {
	if (listSize >= LISTCAPACITY || d == NULL) return;
	displayList[listSize++] = d;
}

/* Adds display to next available NULL slot. */
void addMessage(uint8_t id, const char *message, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop) {
	addDisplayable(createDisplayableMessage(id, message, &proggyFont, rStart, rStep, rStop, cStart, cStep, cStop, loop));
}

void addImage(uint8_t id, const pattern_t* pat, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop) {
	addDisplayable(createDisplayableImage(id, pat, rStart, rStep, rStop, cStart, cStep, cStop, loop));
}

void removeDisplayable(uint8_t id) {
	// find the right displayable
	uint8_t temp;
	for (uint8_t i = 0; i < listSize; i++) {
		if (id == displayList[i]->id) {
			destroyDisplayable(displayList[i]);
			listSize--;
			// copy over following elements to fill the empty gap
			for (temp = i; temp < listSize; temp++) {
				displayList[temp] = displayList[temp + 1];
			}
		}
	}
}

/* Enable or disable a displayable. It remains in the display list but doesn't draw. */
void changeVisibility(uint8_t id, bool visible) {
	for (uint8_t i = 0; i < listSize; i++) {
		if (id == displayList[i]->id) {
			displayList[i]->visible = visible;
		}
	}
}

/* Make id visible and turn all others off. Good for switching between patterns. */
void exclusivelyShow(uint8_t id) {
	for (uint8_t i = 0; i < listSize; i++) {
		if (displayList[i]->id == id) {
			displayList[i]->visible = true;
		}
		else {
			displayList[i]->visible = false;
		}
	}
}

uint8_t getPongLine(const uint8_t row, const uint8_t col, const uint8_t paddle1_y, const uint8_t paddle2_y, const uint8_t ball_x, const uint8_t ball_y) {
	uint8_t line = 0xff;

	// special case for edge panels, draw paddle
	if (col == 0 && paddle1_y >= row - 2 && paddle1_y <= row + 2)
		line &= 0x7f;
	if ((ID == 15 || ID == 30)  && paddle2_y >= row - 2 && paddle2_y <= row + 2)
		line &= 0xfe;

	if (ball_y == row && ball_y - col >= 0 && ball_y - col < 8)
		line &= ~(0x01 << (7 - (ball_x % 8)));

	return line;
}

void drawPong(const uint8_t paddle1_y, const uint8_t paddle2_y, const uint8_t ball_x, const uint8_t ball_y) {
	// paddles are 3 pixels high
	uint8_t row, col;
#if ROW == 0
	for (uint8_t i = 0; i < 8; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTB = 0x01 << i;
		PORTA = getPongLine(row, col, paddle1_y, paddle2_y, ball_x, ball_y);
		_delay_ms(0.1);
		PORTB = 0;
		PORTA = 0xff;
		_delay_ms(0.1);
	}
	for (uint8_t i = 8; i < 16; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTD = 0x01 << (i - 8);
		PORTA = getPongLine(row, col, paddle1_y, paddle2_y, ball_x, ball_y);
		_delay_ms(0.1);
		PORTD = 0;
		PORTA = 0xff;
		_delay_ms(0.1);
	}
#else
	// bottom
	for (uint8_t i = 0; i < 8; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTD = 0x01 << (7 - i);
		PORTA = reversed(getPongLine(row, col, paddle1_y, paddle2_y, ball_x, ball_y));
		_delay_ms(0.1);
		PORTD = 0;
		PORTA = 0xff;
		_delay_ms(0.1);
	}
	for (uint8_t i = 8; i < 16; i++) {
		row = ROWOFFSET + i;
		col = COLOFFSET;
		PORTB = 0x01 << (15 - i);
		PORTA = reversed(getPongLine(row, col, paddle1_y, paddle2_y, ball_x, ball_y));
		_delay_ms(0.1);
		PORTB = 0;
		PORTA = 0xff;
		_delay_ms(0.1);
	}
#endif				
}

int main(void) {
	DDRD = 0xff;
	DDRB = 0xff;
	DDRA = 0xff;
	clear();
	init();
	frame = 0;

	i2cInit();
	i2cSetBitrate(10);
	i2cSetLocalDeviceAddr(LOCAL_ADDR, TRUE);
	i2cSetSlaveReceiveHandler( i2cSlaveReceiveService );
	i2cSetSlaveTransmitHandler( i2cSlaveTransmitService );

	frameDelay = 100;

	// continuously loop
	while(1) {
//		draw();
//		updateOffsets();
//		frame++;
//		_delay_ms(frameDelay);
	}
}

/* Test pattern */
void test(void) {
	// turn all lights on - 10s
	allOn();
	_delay_ms(10000);
	clear();
	// cycle through a test pattern
	for (int i = 0; i < 5; i++) {
		for (int column = 0; column < 16; column++) {
			clear();
			if (column < 8)	{
				PORTB = 0x01 << column;
				PORTD = 0x00;
			}
			else {
				PORTD = 0x01 << (column - 8);
				PORTB = 0x00;
			}
			PORTA = 0x00;
			_delay_ms(50);
		}
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 8; j++) {
			clear();
			for (int column = 0; column < 16; column++) {
				if (column < 8)	{
					PORTB = 0x01<<column;
					PORTD = 0x00;
				}
				else {
					PORTD = 0x01 << (column - 8);
					PORTB = 0x00;
				}
				PORTA = ~(0x01 << j);
				_delay_ms(1);
			}
			_delay_ms(200);
		}
	}
	// turn all on again - 10s
	allOn();
	_delay_ms(10000);
	clear();
}

// slave operations
void i2cSlaveReceiveService(uint8_t receiveDataLength, uint8_t* receiveData)
{
	uint8_t i;
	// this function will run when a master somewhere else on the bus
	// addresses us and wishes to write data to us
	
	cbi(PORTB, PB6);

	// copy the received data to a local buffer
	for(i=0; i<receiveDataLength; i++)
		localBuffer[i] = *receiveData++;

	add_message_cmd *am;
	add_image_cmd *ai;
	pong_cmd *p;

	switch (localBuffer[0]) {
	case FRAME_CMD:
		frame = ((frame_cmd*) localBuffer)->frame;
		updateOffsets();
		draw();
		break;
	case SHOW_CMD:
		exclusivelyShow(((id_cmd*) localBuffer)->id);
		updateOffsets();
		draw();
		break;
	case ADD_MESSAGE_CMD:
		am = (add_message_cmd*) localBuffer;
		addMessage(am->id, am->message, am->rStart, am->rStep, am->rStop, am->cStart, am->cStep, am->cStop, am->loop); 
		updateOffsets();
		draw();
		break;
	case DELETE_CMD:
		removeDisplayable(((id_cmd*) localBuffer)->id);
		updateOffsets();
		draw();
		break;
	case ENABLE_CMD:
		changeVisibility(((id_cmd*) localBuffer)->id, true);
		updateOffsets();
		draw();
		break;
	case DISABLE_CMD:
		changeVisibility(((id_cmd*) localBuffer)->id, false);
		updateOffsets();
		draw();
		break;
	case ADD_IMAGE_CMD:
		ai = (add_image_cmd*) localBuffer;
		// only process valid pattern image ids
		if (ai->imageID >= TOTALPATTERNS || ai->imageID < 0) break; 
		addImage(ai->id, patternList[ai->imageID], ai->rStart, ai->rStep, ai->rStop, ai->cStart, ai->cStep, ai->cStop, ai->loop);
		updateOffsets();
		draw();
		break;
	case PONG_CMD:
		p = (pong_cmd*) localBuffer;
		drawPong(p->paddle1_y, p->paddle2_y, p->ball_x, p->ball_y);
		break;
	case TEST_CMD:
		test();
		break;
	default:
		PORTB = 0x00;
		PORTD = 0x00;
		PORTA = 0x00;
		break;
	}

	localBufferLength = receiveDataLength;
}

uint8_t i2cSlaveTransmitService(uint8_t transmitDataLengthMax, uint8_t* transmitData)
{
	uint8_t i;

	// this function will run when a master somewhere else on the bus
	// addresses us and wishes to read data from us

	cbi(PORTB, PB7);

	// copy the local buffer to the transmit buffer
	for(i=0; i<localBufferLength; i++)
	{
		*transmitData++ = localBuffer[i];
	}

	localBuffer[0]++;

	return localBufferLength;
}
