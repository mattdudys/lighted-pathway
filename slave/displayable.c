#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>
#include "displayable.h"

void initPattern(pattern_t *pattern, uint32_t rows, uint32_t cols, prog_uint8_t *data) {
	pattern->rows = rows;
	pattern->cols = cols;
	pattern->data = data;
}

void initFont(font_t *font, const uint32_t characterWidth, pattern_t* pattern) {
	font->characterWidth = characterWidth;
	font->pattern = pattern;
}

displayable_t* createDisplayableMessage(uint8_t id, const char *message, font_t *font, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop) {
	displayable_t *d = (displayable_t*) malloc(sizeof(displayable_t));
	message_t *m = (message_t*) malloc(sizeof(message_t));
	char *t = (char*) malloc((strlen(message) + 1) * sizeof(char));
	strcpy(t, message);
	d->id = id;
	d->type = MESSAGE;
	d->loop = loop;
	d->visible = true;
	d->invert = false;
	m->text = t;
	m->font = font;
	d->item = (void*) m;	
	d->startRowOffset = rStart;
	d->rowOffsetStep = rStep;
	d->endRowOffset = rStop;
	d->startColOffset = cStart;
	d->colOffsetStep = cStep;
	d->endColOffset = cStop;
	return d;
}

displayable_t* createDisplayableImage(uint8_t id, const pattern_t* pat, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop) {
	displayable_t *d = (displayable_t*) malloc(sizeof(displayable_t));
	d->id = id;
	d->type = IMAGE;
	d->item = (void*) pat;
	d->startRowOffset = rStart;
	d->rowOffsetStep = rStep;
	d->endRowOffset = rStop;
	d->startColOffset = cStart;
	d->colOffsetStep = cStep;
	d->endColOffset = cStop;
	d->loop = loop;
	d->visible = true;
	d->invert = false;
	return d;
}

void destroyDisplayable(displayable_t *d) {
	switch (d->type) {
	case MESSAGE: 	destroyDisplayableMessage(d); break;
	case IMAGE:	destroyDisplayableImage(d); break;
	default: break;
	}
}

void destroyDisplayableMessage(displayable_t *d) {
	message_t *m = (message_t*) d->item;
	free(m->text);
	free(m);
	free(d);
}

void destroyDisplayableImage(displayable_t *d) {
	// We wont free the pattern because most likely it wasn't dynamically allocated.
	free(d);
}

/* Reverse bit pattern. Operates on 8-bit chunks. */
uint8_t reversed(const uint8_t num) {
	uint8_t revved = 0;
	uint8_t bit = 0;
	for (uint8_t i = 0; i < 4; i++) {
		bit = (num & (0x01 << i)) << (7 - 2 * i);
		revved |= bit;
	}
	for (uint8_t i = 4; i < 8; i++) {
		bit = (num & (0x01 << i)) >> (2 * i - 7);
		revved |= bit;
	}
	return revved;
}

/* Get row, column of specified pattern. Pattern is shifted down and to the right by offsets. 
   row and col are bit positions in the whole grid. */
uint8_t getLine(const int32_t row, const int32_t col, const int32_t patternRowOffset, const int32_t patternColOffset, const pattern_t *pat)
{
	// Take into account offsets.
	int32_t r = row - patternRowOffset;
	int32_t c = col - patternColOffset;

	// r and c now reference coordinates of the pattern
	// check for lines fully outside of the pattern
	if ((r < 0) || (r >= (int32_t) pat->rows))
		return 0xff;
	if ((c <= -8) || (c >= (int32_t) pat->cols))
		return 0xff;

	// If edge boundary of the pattern falls in the line we have to pad with 0s by shifting.
	uint32_t first; 
	uint8_t lShift;
	uint8_t line;
	uint8_t rMask = 0;
	// Left padding
	if (c < 0) {
		lShift = -c;
		first = (r * pat->cols) / 8;
		for (uint32_t i = 0; i < lShift; i++)
			rMask |= (0x80 >> i);
		line = pgm_read_byte(pat->data + first);
		return (line >> lShift) | rMask;
	}
	// Right padding
	else if (c + 8 > pat->cols) {
		first = (r * pat->cols + c) / 8;
		lShift = c % 8;
		for (uint32_t i = 0; i < lShift; i++)
			rMask |= (0x01 << i);
		line = pgm_read_byte(pat->data + first);
		return (line << lShift) | rMask; 
	}
	else {
		// Line falls fully within the pattern
		// If we're word aligned, we only need one byte.
		first = (r * pat->cols + c) / 8;
		if (c % 8 == 0) {
			return pgm_read_byte(pat->data + first);
		}
		// Otherwise we need two bytes.
		else {
			uint32_t second = first + 1;
			uint8_t secondLine;
			lShift = c % 8;
			line = pgm_read_byte(pat->data + first);
			uint8_t leftBit = line << lShift;

			for (uint8_t i = 0; i < lShift; i++)
				rMask |= (0x01 << i);
			secondLine = pgm_read_byte(pat->data + second);
			uint8_t rightBit = (secondLine >> (8 - lShift)) & rMask;
			return leftBit | rightBit;
		}
	}

	// Shouldn't reach here.
	return 0b01010101;
}

/* Given a message, position of the line in the display (row, col), and offset of the 
   message (rowOffset, colOffset), returns the proper display line. 
   For simplification, assume character width is at least as big as the board width (8). */
uint8_t getFontLine(const char *message, const int32_t row, const int32_t col, const int32_t rowOffset, const int32_t colOffset, const font_t *f) {
	int charHeight = f->pattern->rows;
	size_t messageLen = strlen(message); 
	int32_t messageWidth = messageLen * f->characterWidth;

	// Take into account offsets.
	int32_t r = row - rowOffset;
	int32_t c = col - colOffset;

	// r and c now reference coordinates of the pattern
	// check for lines fully outside of the pattern
	if ((r < 0) || (r >= charHeight))
		return 0xff;
	if ((c <= -8) || (c >= messageWidth))
		return 0xff;

	uint8_t line, mask;
	int32_t charPosition = c / f->characterWidth;
	int32_t charStartingCol = charPosition * f->characterWidth;
	int8_t characterOffset = c - charStartingCol;
	int32_t patternCharOffset;
	uint8_t shiftAmnt;

	// Left padding
	if (c < 0) {
		// we only need the first character.
		patternCharOffset = (message[0] - 32) * f->characterWidth;
		line = getLine(row, 0, rowOffset, -patternCharOffset - c, f->pattern);

		// chacter is already shifted, we just need to mask the left side.
		mask = 0;
		shiftAmnt = -c;
		for (uint8_t i = 0; i < shiftAmnt; i++)
			mask |= (0x80 >> i);
		return line | mask;
	}
	// Right padding
	else if (c + 8 > messageWidth) {
		// we only need the last character.
		patternCharOffset = (message[messageLen - 1] - 32) * f->characterWidth;
		characterOffset = c % f->characterWidth;
		line = getLine(row, 0, rowOffset, -patternCharOffset - characterOffset, f->pattern);
		
		// character is already shifted, we just need to mask the right side.
		
		shiftAmnt = 8 - (f->characterWidth - characterOffset); 
		mask = 0;
		for (uint8_t i = 0; i < shiftAmnt; i++)
			mask |= (0x01 << i);
		return line | mask; 
	}
	else {
		// Line falls fully within the pattern
		characterOffset = c % f->characterWidth;
		patternCharOffset = (message[charPosition] - 32) * f->characterWidth;
		line = getLine(row, 0, rowOffset, -patternCharOffset - characterOffset, f->pattern);

		if (f->characterWidth - characterOffset >= 8) {
			// All we need is one character and we don't need to mask.
			return line;
		}
		else {
			// We need to also display part of the next character.
			uint8_t lWidth = f->characterWidth - characterOffset;
			uint8_t rWidth = 8 - lWidth;
			
			// First mask the right side of the character we just retrieved.
			mask = 0;
			for (uint8_t i = 0; i < rWidth; i++)
				mask |= (0x01 << i);
			line |= mask;

			// Get the next character.
			patternCharOffset = (message[charPosition + 1] - 32) * f->characterWidth;
			uint8_t secondLine = getLine(row, 0, rowOffset, -patternCharOffset + lWidth, f->pattern);
			
			// Mask the second character by the complement of the shiftAmnt.
			mask = 0;
			for (uint8_t i = 0; i < lWidth; i++)
				mask |= (0x80 >> i);
			secondLine |= mask;

			// Then combine them.
			return line & secondLine;
		}
	}
	
	// Shouldn't reach here.
	return 0xee;
}

/* This handles the different types of displayables. Should be called by a more generic function
   that is aware of a global list of enabled displayables. */
uint8_t getDisplayableLine(const displayable_t *disp, const uint32_t row, const uint32_t col) {
	switch (disp->type) {
	case MESSAGE:
		return getFontLine(((message_t*) disp->item)->text, row, col, disp->rowOffset, disp->colOffset, ((message_t*) disp->item)->font);
	case IMAGE:
		return getLine(row, col, disp->rowOffset, disp->colOffset, ((pattern_t*) disp->item));
	default:
		return 0xff;
	}
}
