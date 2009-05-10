#ifndef PATTERNS_H
#define PATTERNS_H

#include <inttypes.h>
#include <stdbool.h>
#include <avr/pgmspace.h>

uint8_t ASME[] PROGMEM = {
0b00000000, 0b00000000, 0b00000000, 0b00000000,
0b00000000, 0b00000000, 0b00000000, 0b00000000,
0b01111111, 0b11111111, 0b11111111, 0b11111110,
0b01111111, 0b11111111, 0b11111111, 0b11111110,
0b01110111, 0b11000111, 0b01111101, 0b10000010,
0b01101011, 0b10111011, 0b00111001, 0b10111110,
0b01101011, 0b10111111, 0b00111001, 0b10111110,
0b01011101, 0b11000111, 0b01010101, 0b10000010,
0b01000001, 0b11111011, 0b01010101, 0b10111110,
0b01011101, 0b10111011, 0b01101101, 0b10111110,
0b01011101, 0b11000111, 0b01101101, 0b10000010,
0b01111111, 0b11111111, 0b11111111, 0b11111110,
0b01111111, 0b11111111, 0b11111111, 0b11111110,
0b01111111, 0b11111111, 0b11111111, 0b11111110,
0b00000000, 0b00000000, 0b00000000, 0b00000000,
0b00000000, 0b00000000, 0b00000000, 0b00000000 };

uint8_t name[] PROGMEM = { 
0b00000000,
0b11110110,
0b11100110,
0b11010110,
0b10111001,
0b01111111,
0b11111111,
0b10001111,
0b01110111,
0b01110111,
0b10001111,
0b11111111,
0b00000000,
0b01110111,
0b01110111,
0b10001111,
};


uint8_t PROGGY[] PROGMEM = {
0xff, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x3f, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 
0x3f, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 
0xff, 0xff, 0xff, 0x3f, 0xff, 0xf0, 0x3f, 0xff, 0x3f, 0xff, 
0xff, 0xff, 0xfc, 0xff, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf3, 0xfc, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0xfc, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0x0f, 0x3f, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xf0, 0x3f, 
0xff, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xc3, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xcf, 0xf3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xcc, 
0xff, 0xff, 0xf3, 0xff, 0xff, 0xc3, 0xff, 0x3f, 0xf3, 0xff, 
0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 
0xc0, 0xff, 0x3f, 0xc0, 0xfc, 0x0f, 0xfc, 0xf0, 0x03, 0xf0, 
0xf0, 0x03, 0xc0, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xfc, 0x0f, 0xc0, 0x3f, 0x3f, 0x00, 0xfc, 0x0f, 
0x03, 0xf0, 0x03, 0x00, 0x3c, 0x0f, 0x3f, 0x3c, 0x0f, 0xf0, 
0x33, 0xf3, 0x3f, 0xf3, 0xf3, 0x0f, 0x3c, 0x0f, 0x00, 0xfc, 
0x0f, 0x00, 0xfc, 0x0f, 0x00, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0x00, 0x3c, 0xff, 0x3f, 0xff, 0xcf, 0xf3, 
0xff, 0xff, 0xf3, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 
0xff, 0xcf, 0xff, 0xff, 0x3f, 0xff, 0x3f, 0xfc, 0xfc, 0xff, 
0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0x3f, 0xcc, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xc3, 0xff, 
0x3f, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xf3, 0xc0, 0xff, 0x3f, 0xc0, 0xfc, 0x0f, 0xfc, 
0xf0, 0x03, 0xf0, 0xf0, 0x03, 0xc0, 0xfc, 0x0f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xc0, 0x3f, 0x3f, 
0x00, 0xfc, 0x0f, 0x03, 0xf0, 0x03, 0x00, 0x3c, 0x0f, 0x3f, 
0x3c, 0x0f, 0xf0, 0x33, 0xf3, 0x3f, 0xf3, 0xf3, 0x0f, 0x3c, 
0x0f, 0x00, 0xfc, 0x0f, 0x00, 0xfc, 0x0f, 0x00, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x00, 0x3c, 0xff, 0x3f, 
0xff, 0xcf, 0xf3, 0xff, 0xff, 0xf3, 0xff, 0xff, 0x3f, 0xff, 
0xff, 0xff, 0x3f, 0xff, 0xcf, 0xff, 0xff, 0x3f, 0xff, 0x3f, 
0xfc, 0xfc, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0xcc, 0xfc, 0xcf, 0xc0, 0x3c, 
0xfc, 0x3c, 0xff, 0x3f, 0xcf, 0xff, 0xcf, 0xf3, 0xff, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x3f, 0x3c, 0x3f, 0x3f, 
0x33, 0xf3, 0xf0, 0xf3, 0xff, 0xcf, 0xff, 0xf3, 0x3f, 0x33, 
0xf3, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x3f, 0xf3, 0xf3, 
0x3f, 0xcf, 0x3f, 0x3f, 0x33, 0xf3, 0x3c, 0xf3, 0xff, 0x3f, 
0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xff, 0x33, 0xcf, 0x3f, 0xf3, 
0xf3, 0x0f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 
0xf3, 0xf3, 0xf3, 0x3f, 0x33, 0x33, 0x3f, 0x33, 0xf3, 0xff, 
0x3c, 0xff, 0xcf, 0xff, 0xcf, 0xcc, 0xff, 0xff, 0xfc, 0xff, 
0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xcf, 0xff, 0xff, 
0x3f, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xf3, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 
0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xcc, 0xfc, 
0xcf, 0xc0, 0x3c, 0xfc, 0x3c, 0xff, 0x3f, 0xcf, 0xff, 0xcf, 
0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x3f, 
0x3c, 0x3f, 0x3f, 0x33, 0xf3, 0xf0, 0xf3, 0xff, 0xcf, 0xff, 
0xf3, 0x3f, 0x33, 0xf3, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 
0x3f, 0xf3, 0xf3, 0x3f, 0xcf, 0x3f, 0x3f, 0x33, 0xf3, 0x3c, 
0xf3, 0xff, 0x3f, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xff, 0x33, 
0xcf, 0x3f, 0xf3, 0xf3, 0x0f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0xf3, 0xf3, 0xf3, 0x3f, 0x33, 0x33, 0x3f, 
0x33, 0xf3, 0xff, 0x3c, 0xff, 0xcf, 0xff, 0xcf, 0xcc, 0xff, 
0xff, 0xfc, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0xff, 
0xcf, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xf3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 
0x3f, 0xff, 0xf0, 0x03, 0x33, 0xf3, 0x33, 0x3c, 0xff, 0xff, 
0xcf, 0xff, 0xcf, 0x33, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xcf, 0x3f, 0x3f, 0x3f, 0xff, 0x3f, 0xf3, 0xcc, 0xf3, 
0xff, 0x3f, 0xff, 0xcf, 0x3f, 0x33, 0xf3, 0xf3, 0xff, 0x3f, 
0xf0, 0xf0, 0x03, 0xc3, 0xff, 0xf3, 0x30, 0xcc, 0xcf, 0x3f, 
0x33, 0xff, 0x3f, 0x33, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 0x3f, 
0x3f, 0xff, 0x33, 0x3f, 0x3f, 0xf0, 0xc3, 0x33, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xff, 0xf3, 0xf3, 0xf3, 0x3f, 
0x33, 0x33, 0xcc, 0xf3, 0xf3, 0xfc, 0xfc, 0xff, 0xcf, 0xff, 
0xcf, 0x3f, 0x3f, 0xff, 0xff, 0xfc, 0x0f, 0x00, 0xfc, 0x03, 
0xc0, 0x3c, 0x0f, 0x00, 0xfc, 0x0f, 0x00, 0xfc, 0x3f, 0xf0, 
0xfc, 0xf3, 0xf3, 0xf0, 0xcf, 0x00, 0xfc, 0x0f, 0x00, 0xfc, 
0x03, 0x30, 0xfc, 0x03, 0xc0, 0xf3, 0xf3, 0x3f, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0x00, 0x3f, 0x3f, 0xf3, 0xff, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0xff, 0xf0, 0x03, 0x33, 0xf3, 0x33, 
0x3c, 0xff, 0xff, 0xcf, 0xff, 0xcf, 0x33, 0x3f, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xcf, 0x3f, 0x3f, 0x3f, 0xff, 0x3f, 
0xf3, 0xcc, 0xf3, 0xff, 0x3f, 0xff, 0xcf, 0x3f, 0x33, 0xf3, 
0xf3, 0xff, 0x3f, 0xf0, 0xf0, 0x03, 0xc3, 0xff, 0xf3, 0x30, 
0xcc, 0xcf, 0x3f, 0x33, 0xff, 0x3f, 0x33, 0xff, 0x3f, 0xf3, 
0xff, 0x3f, 0x3f, 0x3f, 0xff, 0x33, 0x3f, 0x3f, 0xf0, 0xc3, 
0x33, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xff, 0xf3, 
0xf3, 0xf3, 0x3f, 0x33, 0x33, 0xcc, 0xf3, 0xf3, 0xfc, 0xfc, 
0xff, 0xcf, 0xff, 0xcf, 0x3f, 0x3f, 0xff, 0xff, 0xfc, 0x0f, 
0x00, 0xfc, 0x03, 0xc0, 0x3c, 0x0f, 0x00, 0xfc, 0x0f, 0x00, 
0xfc, 0x3f, 0xf0, 0xfc, 0xf3, 0xf3, 0xf0, 0xcf, 0x00, 0xfc, 
0x0f, 0x00, 0xfc, 0x03, 0x30, 0xfc, 0x03, 0xc0, 0xf3, 0xf3, 
0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x00, 0x3f, 0x3f, 0xf3, 
0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xfc, 0xcf, 
0xc0, 0xfc, 0xcf, 0xc3, 0xff, 0xff, 0xcf, 0xff, 0xcf, 0xc0, 
0xf0, 0x03, 0xff, 0xf0, 0x03, 0xff, 0xff, 0x3f, 0x33, 0x3f, 
0x3f, 0xf0, 0xff, 0x0f, 0x3c, 0xf0, 0x0f, 0x00, 0xff, 0xcf, 
0xc0, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xfc, 
0x3f, 0xcf, 0x30, 0xcc, 0xcf, 0x00, 0xf3, 0xff, 0x3f, 0x30, 
0x0f, 0x00, 0xf3, 0xc3, 0x00, 0x3f, 0x3f, 0xff, 0x30, 0xff, 
0x3f, 0xf0, 0xc3, 0x33, 0x33, 0xf3, 0x00, 0xf3, 0xf3, 0x00, 
0xfc, 0x0f, 0xf3, 0xf3, 0xf3, 0xcc, 0xf3, 0x33, 0xf3, 0xfc, 
0x0f, 0xf3, 0xfc, 0xff, 0xf3, 0xff, 0xcf, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xf3, 0x3f, 0x33, 0xff, 0x3f, 0x33, 0xf3, 0xcf, 
0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 0xcf, 0xf3, 0xf3, 
0x33, 0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x0f, 0x33, 0xff, 
0xcf, 0xf3, 0xf3, 0x3f, 0x33, 0x33, 0xcc, 0xf3, 0xf3, 0xfc, 
0xfc, 0xff, 0xf3, 0xff, 0xcf, 0xc3, 0xcf, 0xff, 0xff, 0x3f, 
0xff, 0xfc, 0xcf, 0xc0, 0xfc, 0xcf, 0xc3, 0xff, 0xff, 0xcf, 
0xff, 0xcf, 0xc0, 0xf0, 0x03, 0xff, 0xf0, 0x03, 0xff, 0xff, 
0x3f, 0x33, 0x3f, 0x3f, 0xf0, 0xff, 0x0f, 0x3c, 0xf0, 0x0f, 
0x00, 0xff, 0xcf, 0xc0, 0xfc, 0x03, 0xff, 0xff, 0xff, 0x0f, 
0xff, 0xff, 0xfc, 0x3f, 0xcf, 0x30, 0xcc, 0xcf, 0x00, 0xf3, 
0xff, 0x3f, 0x30, 0x0f, 0x00, 0xf3, 0xc3, 0x00, 0x3f, 0x3f, 
0xff, 0x30, 0xff, 0x3f, 0xf0, 0xc3, 0x33, 0x33, 0xf3, 0x00, 
0xf3, 0xf3, 0x00, 0xfc, 0x0f, 0xf3, 0xf3, 0xf3, 0xcc, 0xf3, 
0x33, 0xf3, 0xfc, 0x0f, 0xf3, 0xfc, 0xff, 0xf3, 0xff, 0xcf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x3f, 0x33, 0xff, 0x3f, 
0x33, 0xf3, 0xcf, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 
0xcf, 0xf3, 0xf3, 0x33, 0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 
0x0f, 0x33, 0xff, 0xcf, 0xf3, 0xf3, 0x3f, 0x33, 0x33, 0xcc, 
0xf3, 0xf3, 0xfc, 0xfc, 0xff, 0xf3, 0xff, 0xcf, 0xc3, 0xcf, 
0xff, 0xff, 0x3f, 0xff, 0xfc, 0xcf, 0xf3, 0x3f, 0x33, 0x3c, 
0xcf, 0xff, 0xcf, 0xff, 0xcf, 0x33, 0x3f, 0x3f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0xcf, 0xff, 0xf3, 
0x00, 0x3f, 0xf3, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xf3, 0xff, 
0xff, 0xff, 0xf0, 0xf0, 0x03, 0xc3, 0xff, 0x3f, 0x30, 0x0c, 
0x0f, 0x3f, 0x33, 0xff, 0x3f, 0x33, 0xff, 0x3f, 0xf3, 0xf3, 
0x3f, 0x3f, 0x3f, 0xff, 0x33, 0x3f, 0x3f, 0xf3, 0x33, 0x33, 
0x33, 0xf3, 0x3f, 0xf3, 0xf3, 0x3f, 0x3f, 0xf3, 0xf3, 0xf3, 
0xf3, 0xcc, 0xfc, 0xcf, 0xcc, 0xff, 0x3f, 0xcf, 0xfc, 0xff, 
0xf3, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x03, 0x3f, 
0x33, 0xff, 0x3f, 0x30, 0x03, 0xcf, 0xf3, 0xf3, 0x3f, 0x3f, 
0x3f, 0xfc, 0xfc, 0x3f, 0xf3, 0xf3, 0x33, 0x3f, 0x33, 0xf3, 
0x3f, 0x33, 0xf3, 0x3f, 0xfc, 0x0f, 0xcf, 0xf3, 0xf3, 0xcc, 
0xf3, 0x33, 0xf3, 0xf3, 0xf3, 0xf3, 0xff, 0x3f, 0xf3, 0xff, 
0x3f, 0x3c, 0x3f, 0xff, 0xff, 0x3f, 0xff, 0xfc, 0xcf, 0xf3, 
0x3f, 0x33, 0x3c, 0xcf, 0xff, 0xcf, 0xff, 0xcf, 0x33, 0x3f, 
0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 
0xcf, 0xff, 0xf3, 0x00, 0x3f, 0xf3, 0x3f, 0x3f, 0x3f, 0x3f, 
0x3f, 0xf3, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0x03, 0xc3, 0xff, 
0x3f, 0x30, 0x0c, 0x0f, 0x3f, 0x33, 0xff, 0x3f, 0x33, 0xff, 
0x3f, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xff, 0x33, 0x3f, 0x3f, 
0xf3, 0x33, 0x33, 0x33, 0xf3, 0x3f, 0xf3, 0xf3, 0x3f, 0x3f, 
0xf3, 0xf3, 0xf3, 0xf3, 0xcc, 0xfc, 0xcf, 0xcc, 0xff, 0x3f, 
0xcf, 0xfc, 0xff, 0xf3, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0x03, 0x3f, 0x33, 0xff, 0x3f, 0x30, 0x03, 0xcf, 0xf3, 
0xf3, 0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 0x3f, 0xf3, 0xf3, 0x33, 
0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x3f, 0xfc, 0x0f, 0xcf, 
0xf3, 0xf3, 0xcc, 0xf3, 0x33, 0xf3, 0xf3, 0xf3, 0xf3, 0xff, 
0x3f, 0xf3, 0xff, 0x3f, 0x3c, 0x3f, 0xff, 0xff, 0xff, 0xff, 
0xf0, 0x03, 0x00, 0xfc, 0xcc, 0x3f, 0x3f, 0xff, 0xcf, 0xff, 
0xcf, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 
0x3f, 0x3f, 0x3f, 0x3f, 0xf3, 0xf3, 0xfc, 0xf3, 0xf3, 0x3f, 
0x3f, 0x3f, 0x3f, 0x3f, 0xcf, 0xf3, 0xff, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0xff, 0x3f, 0xf3, 0xf3, 0x3f, 0x33, 0xf3, 
0x3c, 0xf3, 0xff, 0x3f, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xff, 
0x33, 0xcf, 0x3f, 0xf3, 0x33, 0x3c, 0x33, 0xf3, 0x3f, 0xf3, 
0xc3, 0x3f, 0x33, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xfc, 0xcf, 
0x3f, 0x3f, 0x3f, 0x3f, 0xfc, 0xff, 0xfc, 0xff, 0xcf, 0xff, 
0xff, 0xff, 0xff, 0xf3, 0xf3, 0x3f, 0x33, 0xff, 0x3f, 0x33, 
0xff, 0xcf, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 0xcf, 
0xf3, 0xf3, 0x33, 0x3f, 0x33, 0xf3, 0x3f, 0x33, 0xf3, 0x3f, 
0xff, 0xf3, 0xcf, 0xf3, 0xf3, 0xcc, 0xfc, 0xcf, 0xcc, 0xf3, 
0xf3, 0xcf, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf0, 0x03, 0x00, 0xfc, 0xcc, 0x3f, 0x3f, 
0xff, 0xcf, 0xff, 0xcf, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0xf3, 0xf3, 0xfc, 
0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xcf, 0xf3, 0xff, 
0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0xff, 0x3f, 0xf3, 0xf3, 
0x3f, 0x33, 0xf3, 0x3c, 0xf3, 0xff, 0x3f, 0xf3, 0xf3, 0x3f, 
0x3f, 0x3f, 0xff, 0x33, 0xcf, 0x3f, 0xf3, 0x33, 0x3c, 0x33, 
0xf3, 0x3f, 0xf3, 0xc3, 0x3f, 0x33, 0xf3, 0xf3, 0xf3, 0xf3, 
0xf3, 0xfc, 0xcf, 0x3f, 0x3f, 0x3f, 0x3f, 0xfc, 0xff, 0xfc, 
0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0x3f, 0x33, 
0xff, 0x3f, 0x33, 0xff, 0xcf, 0xf3, 0xf3, 0x3f, 0x3f, 0x3f, 
0xfc, 0xfc, 0xcf, 0xf3, 0xf3, 0x33, 0x3f, 0x33, 0xf3, 0x3f, 
0x33, 0xf3, 0x3f, 0xff, 0xf3, 0xcf, 0xf3, 0xf3, 0xcc, 0xfc, 
0xcf, 0xcc, 0xf3, 0xf3, 0xcf, 0xff, 0x3f, 0xf3, 0xff, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xfc, 0xcf, 0xf3, 0xf3, 
0xf3, 0xc0, 0xcf, 0xff, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 
0xf3, 0xff, 0xff, 0xf3, 0xfc, 0xff, 0xc0, 0xfc, 0x0f, 0x00, 
0x3c, 0x0f, 0xfc, 0xfc, 0x0f, 0xc0, 0xfc, 0xff, 0xc0, 0xfc, 
0x3f, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 
0xc0, 0x03, 0xf3, 0x00, 0xfc, 0x0f, 0x03, 0xf0, 0x03, 0x3f, 
0xfc, 0x03, 0x3f, 0x3c, 0x0f, 0x00, 0xf3, 0xf3, 0x00, 0x33, 
0xf3, 0x3c, 0x3c, 0x0f, 0x3f, 0xfc, 0x03, 0x3f, 0x3c, 0x0f, 
0xf3, 0xfc, 0x0f, 0xf3, 0xfc, 0xcf, 0x3f, 0x3f, 0x3f, 0x00, 
0x3c, 0xff, 0xfc, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xfc, 
0x03, 0x00, 0xfc, 0x03, 0xc0, 0x3c, 0x03, 0xcf, 0xfc, 0x03, 
0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 0xf3, 0xf3, 0xf3, 0x33, 0x3f, 
0x3c, 0x0f, 0x00, 0xfc, 0x03, 0x3f, 0xf0, 0x0f, 0xf0, 0x3c, 
0x03, 0xf3, 0xfc, 0xcf, 0x3f, 0x3c, 0x03, 0x00, 0x3f, 0x3f, 
0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xfc, 
0xcf, 0xf3, 0xf3, 0xf3, 0xc0, 0xcf, 0xff, 0xf3, 0xff, 0x3f, 
0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xf3, 0xfc, 0xff, 0xc0, 
0xfc, 0x0f, 0x00, 0x3c, 0x0f, 0xfc, 0xfc, 0x0f, 0xc0, 0xfc, 
0xff, 0xc0, 0xfc, 0x3f, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0xc0, 0x03, 0xf3, 0x00, 0xfc, 0x0f, 0x03, 
0xf0, 0x03, 0x3f, 0xfc, 0x03, 0x3f, 0x3c, 0x0f, 0x00, 0xf3, 
0xf3, 0x00, 0x33, 0xf3, 0x3c, 0x3c, 0x0f, 0x3f, 0xfc, 0x03, 
0x3f, 0x3c, 0x0f, 0xf3, 0xfc, 0x0f, 0xf3, 0xfc, 0xcf, 0x3f, 
0x3f, 0x3f, 0x00, 0x3c, 0xff, 0xfc, 0xff, 0xcf, 0xff, 0xff, 
0xff, 0xff, 0xfc, 0x03, 0x00, 0xfc, 0x03, 0xc0, 0x3c, 0x03, 
0xcf, 0xfc, 0x03, 0x3f, 0x3f, 0x3f, 0xfc, 0xfc, 0xf3, 0xf3, 
0xf3, 0x33, 0x3f, 0x3c, 0x0f, 0x00, 0xfc, 0x03, 0x3f, 0xf0, 
0x0f, 0xf0, 0x3c, 0x03, 0xf3, 0xfc, 0xcf, 0x3f, 0x3c, 0x03, 
0x00, 0x3f, 0x3f, 0xf3, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 
0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0x3c, 
0x0f, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xfc, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 
0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xf3, 0xff, 0xff, 0xcf, 0xf3, 0xfc, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xcf, 
0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
0x0f, 0xff, 0x3c, 0x0f, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 
0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x3f, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xcf, 0xf3, 
0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0x0f, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xf3, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0x03, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xf3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

uint8_t UCMERCED[] PROGMEM = {
0x00, 0x3f, 0xc0, 0x0f, 0xf0, 0x01, 0xf0, 0x03, 0xff, 0xf0, 
0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xc0, 0x1f, 0xc0, 0x00, 
0x10, 0x03, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 
0xf8, 0x7f, 0x87, 0xfc, 0x1c, 0x1f, 0xff, 0xfe, 0x1f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xe3, 0xff, 0xf8, 0xfe, 0x0f, 0xfe, 0x1e, 0x0f, 
0xff, 0xfc, 0x1e, 0x00, 0x02, 0x00, 0x0f, 0xff, 0xf8, 0x03, 
0xc0, 0x00, 0x60, 0x00, 0x3f, 0xff, 0xe3, 0xff, 0xf8, 0xfc, 
0x1f, 0xff, 0x1e, 0x0f, 0xff, 0xfc, 0x1e, 0x00, 0x01, 0x00, 
0x01, 0xff, 0xc0, 0x00, 0x40, 0x00, 0x20, 0x00, 0x07, 0xff, 
0xe3, 0xff, 0xf8, 0xf8, 0x3f, 0xff, 0x9e, 0x07, 0xff, 0xf8, 
0x1f, 0x80, 0x01, 0xc3, 0xc0, 0xff, 0x83, 0xf8, 0x70, 0x00, 
0x38, 0x7f, 0x01, 0xff, 0xe3, 0xff, 0xf8, 0xf8, 0x7f, 0xff, 
0x9e, 0x07, 0xff, 0xf8, 0x1f, 0x87, 0xf9, 0xc3, 0xf0, 0x7f, 
0x0f, 0xfe, 0x78, 0xff, 0x38, 0x7f, 0xe0, 0xff, 0xe3, 0xff, 
0xf8, 0xf0, 0x7f, 0xff, 0xfe, 0x07, 0xff, 0xf0, 0x1f, 0x87, 
0xf9, 0xc3, 0xf8, 0x7e, 0x1f, 0xfe, 0x38, 0xff, 0x38, 0x7f, 
0xf0, 0x7f, 0xe3, 0xff, 0xf8, 0xf0, 0xff, 0xff, 0xfe, 0x03, 
0xff, 0xf0, 0x1f, 0x87, 0xff, 0xc3, 0xf8, 0x7c, 0x3f, 0xff, 
0x38, 0xff, 0xf8, 0x7f, 0xf8, 0x3f, 0xe3, 0xff, 0xf8, 0xe0, 
0xff, 0xff, 0xfe, 0x03, 0xff, 0xe0, 0x1f, 0x87, 0xff, 0xc3, 
0xfc, 0x78, 0x7f, 0xff, 0x38, 0xff, 0xf8, 0x7f, 0xfc, 0x1f, 
0xe3, 0xff, 0xf8, 0xe0, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xe0, 
0x1f, 0x87, 0xff, 0xc3, 0xfc, 0x78, 0x7f, 0xff, 0xf8, 0xff, 
0xf8, 0x7f, 0xfc, 0x1f, 0xe3, 0xff, 0xf8, 0xe1, 0xff, 0xff, 
0xfe, 0x11, 0xff, 0xc2, 0x1f, 0x87, 0xff, 0xc3, 0xfc, 0x78, 
0x7f, 0xff, 0xf8, 0xff, 0xf8, 0x7f, 0xfe, 0x1f, 0xe3, 0xff, 
0xf8, 0xe1, 0xff, 0xff, 0xfe, 0x10, 0xff, 0xc2, 0x1f, 0x87, 
0xff, 0xc3, 0xf8, 0x70, 0xff, 0xff, 0xf8, 0xff, 0xf8, 0x7f, 
0xfe, 0x1f, 0xe3, 0xff, 0xf8, 0xe1, 0xff, 0xff, 0xfe, 0x18, 
0xff, 0x86, 0x1f, 0x80, 0x07, 0xc3, 0xf0, 0xf0, 0xff, 0xff, 
0xf8, 0x00, 0xf8, 0x7f, 0xfe, 0x1f, 0xe3, 0xff, 0xf8, 0xe1, 
0xff, 0xff, 0xfe, 0x18, 0x7f, 0x86, 0x1f, 0x80, 0x07, 0xc3, 
0xe1, 0xf0, 0xff, 0xff, 0xf8, 0x00, 0xf8, 0x7f, 0xfe, 0x1f, 
0xe3, 0xff, 0xf8, 0xe0, 0xff, 0xff, 0xfe, 0x1c, 0x7f, 0x0e, 
0x1f, 0x87, 0xff, 0xc0, 0x03, 0xf0, 0xff, 0xff, 0xf8, 0xff, 
0xf8, 0x7f, 0xfe, 0x1f, 0xe3, 0xff, 0xf8, 0xe0, 0xff, 0xff, 
0xfe, 0x1c, 0x3f, 0x0e, 0x1f, 0x87, 0xff, 0xc0, 0x07, 0xf0, 
0xff, 0xff, 0xf8, 0xff, 0xf8, 0x7f, 0xfe, 0x1f, 0xe3, 0xff, 
0xf8, 0xe0, 0xff, 0xff, 0xfe, 0x1e, 0x3e, 0x1e, 0x1f, 0x87, 
0xff, 0xc3, 0x83, 0xf0, 0xff, 0xff, 0xf8, 0xff, 0xf8, 0x7f, 
0xfe, 0x1f, 0xe3, 0xff, 0xf8, 0xe0, 0xff, 0xff, 0xfe, 0x1e, 
0x1e, 0x3e, 0x1f, 0x87, 0xff, 0xc3, 0xc1, 0xf0, 0x7f, 0xff, 
0xf8, 0xff, 0xf8, 0x7f, 0xfe, 0x1f, 0xe1, 0xff, 0xf8, 0xf0, 
0x7f, 0xff, 0xde, 0x1f, 0x1e, 0x3e, 0x1f, 0x87, 0xff, 0xc3, 
0xe0, 0xf8, 0x7f, 0xff, 0xf8, 0xff, 0xf8, 0x7f, 0xfc, 0x1f, 
0xe1, 0xff, 0xf0, 0xf0, 0x7f, 0xff, 0xde, 0x1f, 0x0c, 0x7e, 
0x1f, 0x87, 0xff, 0xc3, 0xf0, 0x78, 0x3f, 0xff, 0x38, 0xff, 
0xf8, 0x7f, 0xfc, 0x3f, 0xe0, 0xff, 0xe0, 0xf8, 0x3f, 0xff, 
0x9e, 0x1f, 0x8c, 0x7e, 0x1f, 0x87, 0xfc, 0xc3, 0xf8, 0x3c, 
0x3f, 0xff, 0x38, 0xff, 0xd8, 0x7f, 0xf8, 0x3f, 0xf0, 0x7f, 
0xc0, 0xfc, 0x1f, 0xff, 0x9e, 0x1f, 0x80, 0xfe, 0x1f, 0x87, 
0xfc, 0xc3, 0xfc, 0x1c, 0x1f, 0xff, 0x38, 0xff, 0x98, 0x7f, 
0xf0, 0x7f, 0xf0, 0x3f, 0x80, 0xfe, 0x0f, 0xff, 0x1e, 0x1f, 
0xc0, 0xfe, 0x1f, 0x87, 0xf9, 0xc3, 0xfe, 0x0e, 0x0f, 0xfe, 
0x38, 0xff, 0x38, 0x7f, 0xe1, 0xff, 0xf8, 0x06, 0x18, 0x7f, 
0x03, 0xfe, 0x1e, 0x1f, 0xc1, 0xfe, 0x1f, 0x87, 0xe1, 0xc3, 
0xff, 0x07, 0x03, 0xfc, 0x30, 0x7e, 0x38, 0x3f, 0x83, 0xff, 
0xfc, 0x00, 0x30, 0x0f, 0x80, 0x00, 0x18, 0x0f, 0xe1, 0xf8, 
0x06, 0x00, 0x01, 0x00, 0xff, 0x81, 0xc0, 0x00, 0x60, 0x00, 
0x20, 0x00, 0x07, 0xff, 0xff, 0x00, 0x40, 0x0f, 0xf0, 0x00, 
0xf0, 0x03, 0xe1, 0xf0, 0x02, 0x00, 0x02, 0x00, 0xff, 0xc0, 
0xf0, 0x00, 0xc0, 0x00, 0x20, 0x00, 0x3f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xfc, 0x07, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

uint8_t SOE[] PROGMEM = {
0xc0, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xfe, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0x9e, 0x7f, 0xf9, 0xff, 0xff, 
0xff, 0xe7, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3f, 0x3f, 0xf9, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xfc, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0xf9, 0xff, 0xff, 
0xff, 0xe7, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x1f, 0xfc, 0x39, 0x0f, 0x87, 0xe1, 0xe7, 0xff, 0xf8, 0x78, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0x83, 0xf9, 0x98, 0xe7, 0x33, 
0xcc, 0xe7, 0xff, 0xf3, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0x73, 0x99, 0xe6, 0x79, 0x9e, 0x67, 0xff, 0xe7, 0x9c, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x33, 0xf9, 0xe6, 0x79, 
0x9e, 0x67, 0xff, 0xe7, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x33, 0xf9, 0xe6, 0x79, 0x9e, 0x67, 0xff, 0xe7, 0x9c, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x33, 0xf9, 0xe6, 0x79, 
0x9e, 0x67, 0xff, 0xe7, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3f, 0x33, 0x99, 0xe6, 0x79, 0x9e, 0x67, 0xff, 0xe7, 0x9c, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x9e, 0x79, 0x99, 0xe7, 0x33, 
0xcc, 0xe7, 0xff, 0xf3, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0xfc, 0x39, 0xe7, 0x87, 0xe1, 0xe7, 0xff, 0xf8, 0x7c, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 
0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0xf2, 0x0f, 0x80, 0xce, 0x41, 0xf0, 0x7e, 
0x0f, 0x22, 0x72, 0x0f, 0x80, 0xff, 0xff, 0x3f, 0xf1, 0xc7, 
0x38, 0xce, 0x38, 0xe7, 0x3c, 0xe7, 0x1e, 0x71, 0xc7, 0x38, 
0xff, 0xff, 0x00, 0x73, 0xe7, 0x7c, 0xce, 0x7c, 0xcf, 0x99, 
0xf3, 0x3e, 0x73, 0xe7, 0x7c, 0xff, 0xff, 0x3f, 0xf3, 0xe6, 
0x7c, 0xce, 0x7c, 0xcf, 0x99, 0xf3, 0x3e, 0x73, 0xe6, 0x7c, 
0xff, 0xff, 0x3f, 0xf3, 0xe6, 0x7c, 0xce, 0x7c, 0xc0, 0x18, 
0x03, 0x3e, 0x73, 0xe6, 0x7c, 0xff, 0xff, 0x3f, 0xf3, 0xe6, 
0x7c, 0xce, 0x7c, 0xcf, 0xf9, 0xff, 0x3e, 0x73, 0xe6, 0x7c, 
0xff, 0xff, 0x3f, 0xf3, 0xe6, 0x7c, 0xce, 0x7c, 0xcf, 0xf9, 
0xff, 0x3e, 0x73, 0xe6, 0x7c, 0xff, 0xff, 0x3f, 0xf3, 0xe6, 
0x7c, 0xce, 0x7c, 0xe7, 0x9c, 0xf3, 0x3e, 0x73, 0xe6, 0x7c, 
0xff, 0xff, 0x3f, 0xf3, 0xe7, 0x38, 0xce, 0x7c, 0xe7, 0x3c, 
0xe7, 0x3e, 0x73, 0xe7, 0x38, 0xff, 0xff, 0x00, 0x33, 0xe7, 
0x84, 0xce, 0x7c, 0xf0, 0x7e, 0x0f, 0x3e, 0x73, 0xe7, 0x84, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xfe, 
0x7c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7c, 
0xff, 0xff, 0xff, 0xff, 0xfe, 0x39, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x83};

uint8_t NS[] PROGMEM = {
0x1f, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xcf, 0xff, 0xf3, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x0f, 0xcf, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xcf, 0xff, 0xf3, 0xff, 
0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x27, 0xcf, 0x81, 0xe0, 0x9f, 0x99, 0x1c, 0x0f, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x33, 0xcf, 0x00, 0xe0, 0x9f, 
0x98, 0x18, 0x07, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x33, 0xce, 0x7e, 0x73, 0x9f, 0x98, 0xf3, 0xf3, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x39, 0xcf, 0xfe, 0x73, 0x9f, 
0x99, 0xff, 0xf3, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3c, 0xcf, 0xc0, 0x73, 0x9f, 0x99, 0xfe, 0x03, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3c, 0xcf, 0x00, 0x73, 0x9f, 
0x99, 0xf8, 0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3e, 0x4e, 0x3e, 0x73, 0x9f, 0x99, 0xf1, 0xf3, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0e, 0x7e, 0x73, 0x9f, 
0x99, 0xf3, 0xf3, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3f, 0x0e, 0x7c, 0x73, 0x8f, 0x19, 0xf3, 0xe3, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x8f, 0x00, 0x70, 0xc0, 
0x19, 0xf8, 0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x3f, 0xcf, 0x86, 0x78, 0xe1, 0x99, 0xfc, 0x33, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x83, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xfc, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0x7c, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0x7f, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0xff, 0xfc, 0x3c, 0xfc, 0x3e, 0x43, 0xfc, 0x3f, 0x87, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xf0, 0x1c, 0xf0, 
0x0e, 0x01, 0xf0, 0x1e, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0x0f, 0xf3, 0xcc, 0xf3, 0xce, 0x38, 0xf3, 0xce, 0x79, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0xe7, 0xfc, 0xe7, 
0xe6, 0x7c, 0xe7, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xf8, 0xe7, 0xfc, 0xe0, 0x06, 0x7c, 0xe7, 0xfc, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x67, 0xfc, 0xe0, 
0x06, 0x7c, 0xe7, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xf9, 0xfe, 0x67, 0xfc, 0xe7, 0xfe, 0x7c, 0xe7, 0xfc, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xfe, 0x67, 0xcc, 0xe7, 
0xe6, 0x7c, 0xe7, 0xcc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfc, 0x7c, 0x73, 0x8c, 0xf3, 0xc6, 0x7c, 0xf3, 0x8e, 0x78, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xf0, 0x1c, 0xf0, 
0x0e, 0x7c, 0xf0, 0x1e, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x03, 0xfc, 0x3c, 0xfc, 0x1e, 0x7c, 0xfc, 0x3f, 0x83};

uint8_t SSHA[] PROGMEM = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc1, 0xff, 0xff, 0xdf, 0xfe, 0xff, 0xfe, 0x0f, 0xfe, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xff, 0xff, 0xdf, 0xfe, 
0xff, 0xfd, 0xf7, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x7f, 0x7f, 0xff, 0xff, 0xfe, 0xff, 0xfb, 0xfb, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x71, 0xf8, 0xde, 0x1e, 
0xff, 0xfb, 0xfb, 0xc6, 0xf8, 0xf4, 0x3c, 0x7c, 0x78, 0x7f, 
0x3f, 0xee, 0xf6, 0x5c, 0xee, 0xff, 0xf9, 0xff, 0xb2, 0xf7, 
0x73, 0xdb, 0x3b, 0xb7, 0xbf, 0x81, 0xdf, 0x6f, 0x5d, 0xee, 
0xff, 0xfc, 0x0f, 0x7a, 0xef, 0xb7, 0xd7, 0xb7, 0xd7, 0xff, 
0xf0, 0xdf, 0x6f, 0xdf, 0xee, 0xff, 0xff, 0x87, 0x7e, 0xef, 
0xb7, 0xd7, 0xf7, 0xd3, 0xff, 0xfe, 0x5f, 0x6f, 0xde, 0x0e, 
0xff, 0xff, 0xf3, 0x7e, 0xe0, 0x37, 0xd7, 0xf0, 0x18, 0x7f, 
0x7f, 0x5f, 0x6f, 0xdc, 0xee, 0xff, 0xfb, 0xfb, 0x7e, 0xef, 
0xf7, 0xd7, 0xf7, 0xff, 0x3f, 0x7f, 0x5f, 0x6f, 0x5d, 0xee, 
0xff, 0xfb, 0xfb, 0x7a, 0xef, 0xb7, 0xd7, 0xb7, 0xd7, 0xbf, 
0x9e, 0xee, 0xf6, 0x5d, 0xce, 0xff, 0xfc, 0xf7, 0xb2, 0xf7, 
0x37, 0xdb, 0x3b, 0x93, 0xb1, 0xc1, 0xf1, 0xf8, 0xde, 0x2e, 
0xff, 0xfe, 0x0f, 0xc6, 0xf8, 0x77, 0xdc, 0x7c, 0x38, 0x71, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfb, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xdf, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 
0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xbf, 0xff, 0xff, 
0xff, 0xff, 0xaf, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xfb, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xaf, 0xfd, 0xff, 
0x7f, 0x6f, 0x74, 0x63, 0x87, 0xa1, 0xdb, 0xbc, 0x7c, 0x3f, 
0xed, 0xff, 0xaf, 0xa5, 0xe1, 0x7f, 0x6f, 0x73, 0x9d, 0x3b, 
0x9e, 0xd0, 0xbb, 0xbb, 0xdf, 0xed, 0xff, 0x77, 0x98, 0x5e, 
0x00, 0x6f, 0x77, 0xbd, 0x7b, 0xbe, 0xdb, 0xb7, 0xdb, 0xff, 
0xf3, 0xff, 0x77, 0xbd, 0xdf, 0x7f, 0x6f, 0x77, 0xbd, 0xfb, 
0xbe, 0xdb, 0xb7, 0xd9, 0xff, 0xf3, 0x7e, 0xfb, 0xbd, 0xcf, 
0x7f, 0x6f, 0x77, 0xbd, 0x83, 0xbe, 0xdb, 0xb0, 0x1c, 0x3f, 
0xe9, 0x7e, 0x03, 0xbd, 0xe1, 0x7f, 0x6f, 0x77, 0xbd, 0x3b, 
0xbe, 0xdb, 0xb7, 0xff, 0x9f, 0xdc, 0xfd, 0xfd, 0xbd, 0xfc, 
0x7f, 0x6f, 0x77, 0xbd, 0x7b, 0xbe, 0xdb, 0xb7, 0xdb, 0xdf, 
0xde, 0xfd, 0xfd, 0xbd, 0xde, 0x7f, 0x6e, 0x77, 0xbd, 0x73, 
0xbe, 0xdb, 0xbb, 0x99, 0xd1, 0xcc, 0x7d, 0xfd, 0xbd, 0xce, 
0x7f, 0x71, 0x77, 0xbd, 0x8b, 0xbe, 0xd8, 0xbc, 0x3c, 0x31, 
0xe1, 0xfb, 0xfe, 0xbc, 0x61, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff};

uint8_t MICHELLE[] PROGMEM = {
0x3f, 0x9f, 0xcf, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x8f, 0xcf, 0xff, 0xe7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x9f, 0x0f, 0x9f, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x0f, 0x9f, 0xff, 0xe7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x9f, 0x0f, 0x9f, 0x07, 0xe7, 0xe0, 0xfc, 0x1f, 0x98, 0x70, 
0x7f, 0x07, 0xff, 0xff, 0xff, 0x8f, 0x67, 0x9e, 0x01, 0xe7, 
0xc0, 0x78, 0x0f, 0x80, 0x20, 0x3e, 0x01, 0xff, 0xff, 0xff, 
0xce, 0x67, 0x3c, 0x79, 0xe7, 0x8f, 0x71, 0xc7, 0x8f, 0x07, 
0x1c, 0x79, 0xff, 0xff, 0xff, 0xce, 0x67, 0x38, 0xfc, 0xe7, 
0x1f, 0xe3, 0xe3, 0x9f, 0x9f, 0x98, 0xfc, 0xff, 0xff, 0xff, 
0xce, 0x67, 0x39, 0xfc, 0xe7, 0x3f, 0xe7, 0xf3, 0x9f, 0x9f, 
0x99, 0xfc, 0xff, 0xff, 0xff, 0xe6, 0xf3, 0x38, 0x00, 0xe7, 
0x3f, 0xe7, 0xf3, 0x9f, 0x9f, 0x98, 0x00, 0xff, 0xff, 0xff, 
0xe4, 0xf2, 0x78, 0x00, 0xe7, 0x3f, 0xe7, 0xf3, 0x9f, 0x9f, 
0x98, 0x00, 0xff, 0xff, 0xff, 0xe4, 0xf2, 0x79, 0xff, 0xe7, 
0x3f, 0xe7, 0xf3, 0x9f, 0x9f, 0x99, 0xff, 0xff, 0xff, 0xff, 
0xe4, 0xf2, 0x79, 0xff, 0xe7, 0x1f, 0xe3, 0xe3, 0x9f, 0x9f, 
0x99, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xf8, 0xfc, 0x7e, 0xe7, 
0x9f, 0x71, 0xc7, 0x9f, 0x9f, 0x9c, 0x7e, 0xff, 0xff, 0xff, 
0xf1, 0xf8, 0xfe, 0x00, 0xe7, 0x80, 0x78, 0x0f, 0x9f, 0x9f, 
0x9e, 0x00, 0xff, 0xff, 0xff, 0xf1, 0xf8, 0xff, 0x01, 0xe7, 
0xe0, 0xfc, 0x1f, 0x9f, 0x9f, 0x9f, 0x01, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 
0xff, 0xfe, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0xfe, 0x3c, 0xff, 0xfc, 0xff, 0xff, 0xfe, 0x79, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf8, 0xfe, 0x3c, 0xff, 0xfc, 0xff, 
0xff, 0xfe, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x7c, 0x3f, 0xff, 0xfc, 0xff, 0xff, 0xfe, 0x79, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0x7d, 0x3f, 0xff, 0xfc, 0xff, 
0xff, 0xfe, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0x39, 0x3c, 0xfc, 0x3c, 0x87, 0xf8, 0x3e, 0x79, 0xf8, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0x3b, 0x3c, 0xf0, 0x1c, 0x03, 
0xe0, 0x1e, 0x79, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0x93, 0x3c, 0xf3, 0xdc, 0x71, 0xe7, 0x8e, 0x79, 0xe7, 0x8f, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0x93, 0x3c, 0xe7, 0xfc, 0xf9, 
0xcf, 0xce, 0x79, 0xcf, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0xc7, 0x3c, 0xe7, 0xfc, 0xf9, 0xc0, 0x0e, 0x79, 0xc0, 0x0f, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xc7, 0x3c, 0xe7, 0xfc, 0xf9, 
0xc0, 0x0e, 0x79, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0xef, 0x3c, 0xe7, 0xfc, 0xf9, 0xcf, 0xfe, 0x79, 0xcf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x3c, 0xe7, 0xfc, 0xf9, 
0xcf, 0xfe, 0x79, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0xff, 0x3c, 0xf3, 0xdc, 0xf9, 0xe3, 0xee, 0x79, 0xe3, 0xef, 
0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x3c, 0xf0, 0x1c, 0xf9, 
0xe0, 0x0e, 0x79, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf9, 
0xff, 0x3c, 0xfc, 0x3c, 0xf9, 0xf8, 0x1e, 0x79, 0xf8, 0x1f};

#endif
