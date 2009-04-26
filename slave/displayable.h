#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <avr/pgmspace.h>

// Types of displayable things.
typedef enum {MESSAGE, IMAGE} display_t;

typedef struct {
	// in pixels(bits)
	uint32_t rows;
	uint32_t cols;
	prog_uint8_t *data;
} pattern_t;

void initPattern(pattern_t *pattern, uint32_t rows, uint32_t cols, prog_uint8_t *data);

typedef struct {
	uint32_t characterWidth;
	pattern_t *pattern;
} font_t;

void initFont(font_t *font, const uint32_t characterWidth, pattern_t* pattern);

typedef struct {
	uint8_t id;
	void *item;
	display_t type;
	volatile bool loop;
	volatile int32_t startRowOffset, rowOffsetStep, endRowOffset;
	volatile int32_t startColOffset, colOffsetStep, endColOffset;
	volatile int32_t rowOffset, colOffset;
	volatile bool visible;
	bool invert;
} displayable_t;

typedef struct {
	char *text;
	font_t *font;
} message_t;

displayable_t* createDisplayableMessage(uint8_t id, const char *message, font_t *font, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop);

displayable_t* createDisplayableImage(uint8_t id, const pattern_t* pat, int32_t rStart, int32_t rStep, int32_t rStop, int32_t cStart, int32_t cStep, int32_t cStop, bool loop);

void destroyDisplayable(displayable_t *d);

void destroyDisplayableMessage(displayable_t *d);

void destroyDisplayableImage(displayable_t *d);

/* Reverse bit pattern. Operates on 8-bit chunks. */
uint8_t reversed(const uint8_t num);

/* Get row, column of specified pattern. Pattern is shifted down and to the right by offsets. 
   row and col are bit positions in the whole grid. */
uint8_t getLine(const int32_t row, const int32_t col, const int32_t patternRowOffset, const int32_t patternColOffset, const pattern_t *pat);

/* Given a message, position of the line in the display (row, col), and offset of the 
   message (rowOffset, colOffset), returns the proper display line. 
   For simplification, assume character width is at least as big as the board width (8). */
uint8_t getFontLine(const char *message, const int32_t row, const int32_t col, const int32_t rowOffset, const int32_t colOffset, const font_t *f);

/* FIXME This handles the different types of displayables. */
uint8_t getDisplayableLine(const displayable_t *disp, const uint32_t row, const uint32_t col);
