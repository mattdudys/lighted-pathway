#!/usr/bin/python
import Image
import sys

def convert_to_char_array(infile, outfile):
    inimage = Image.open(infile)
    bitmap = {0: '0', 255: '1'}
    cols, rows = inimage.size
    print infile, inimage.size

    if cols % 8 != 0:
        raise ValueError, 'Columns (width) needs to be divisible by 8.'

    pixels = inimage.size[0] * inimage.size[1]
    binary = ''
    for r in xrange(0, rows):
        for c in xrange(0, cols):
            binary += bitmap[inimage.getpixel((c, r))]
    #print binary
    pixel_data = ['0x%02x' % int(binary[i:i+8], 2) for i in xrange(0, pixels, 8)]
    hex_data = ''
    for pixel in xrange(0, len(pixel_data)):
        if pixel % 10 == 0:
            hex_data += '\n'
        hex_data += pixel_data[pixel] + ', '
        
    #print hex_data
    with open(outfile, 'w') as out:
        out.write('uint8_t ' + infile.split('.')[0].upper() + '[] PROGMEM = {' + hex_data[:-2] + '};\n')

if __name__ == '__main__':
    for filename in sys.argv[1:]:
        convert_to_char_array(filename, filename + '.ascii')

    with open('patterns.h', 'w') as out_file:
        out_file.write('''#ifndef PATTERNS_H
#define PATTERNS_H
#include <inttypes.h>
#include <avr/pgmspace.h>

''')
        for filename in sys.argv[1:]:
	    with open(filename + '.ascii', 'r') as in_file:
	        for line in in_file.readlines():
		    out_file.write(line)

        out_file.write('#endif\n')

