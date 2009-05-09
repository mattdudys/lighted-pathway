#!/usr/bin/python
import Image
import sys

def convert_to_char_array(infile, outfile):
    inimage = Image.open(infile)
    bitmap = {0: '0', 255: '1'}
    cols, rows = inimage.size

    if cols % 8 != 0:
        raise ValueError, 'Columns (width) needs to be divisible by 8.'

    print inimage.size
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
        out.write('{' + hex_data[:-2] + '};')

if __name__ == '__main__':
    convert_to_char_array(sys.argv[1], sys.argv[2])
