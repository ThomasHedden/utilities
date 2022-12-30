#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // needed for uint32_t
#include <string.h> // needed for memcpy()

int main(int argc, char *argv[]) {
   float f = 0;
   // need stdint.h for this:
   uint32_t ui32;
   unsigned int u = 0;
   signed int expon = 0;
   // byte 1 is the leftmost byte
   unsigned char sign_bit;
   unsigned int byte1 = 0;
   unsigned int byte2 = 0;
   unsigned int byte3 = 0;
   unsigned int byte4 = 0;
   // bit1 is the leftmost bit of the respective byte
   unsigned int bit1 = 0;
   unsigned int bit2 = 0;
   unsigned int bit3 = 0;
   unsigned int bit4 = 0;
   unsigned int bit5 = 0;
   unsigned int bit6 = 0;
   unsigned int bit7 = 0;
   unsigned int bit8 = 0;

   if( argc == 2 ) {
      f = strtof(argv[1], NULL);
   } else {
      fprintf(stderr, "Usage: %s float\n", argv[0]);
      exit(1);
   }

   // requires string.h
   memcpy(&ui32, &f, 4);
   u = ui32;

   byte1 = (u & 0xFF000000) >> 24;
   byte2 = (u & 0x00FF0000) >> 16;
   byte3 = (u & 0x0000FF00) >>  8;
   byte4 =  u & 0x000000FF;

   expon = ((u & 0x7F800000) >> 23);

   fprintf(stdout, "The binary representation of %s is:\n", argv[1]);
   fprintf(stdout, "Sign bit  Exponent   Mantissa\n");
   fprintf(stdout, "========  ========   =======================\n");

   // byte 1
   bit1 = (byte1 & 0x80) >> 7; // represents sign
   bit2 = (byte1 & 0x40) >> 6; // 1st bit of exponent
   bit3 = (byte1 & 0x20) >> 5; // 2nd bit of exponent
   bit4 = (byte1 & 0x10) >> 4; // 3rd bit of exponent
   bit5 = (byte1 & 0x08) >> 3; // 4th bit of exponent
   bit6 = (byte1 & 0x04) >> 2; // 5th bit of exponent
   bit7 = (byte1 & 0x02) >> 1; // 6th bit of exponent
   bit8 =  byte1 & 0x01      ; // 7th bit of exponent

   sign_bit = (bit1 == 1 ? '-' : '+'); // + or minus sign

   fprintf(stdout, "%u", bit1); // sign
   fprintf(stdout, " ");        // padding
   fprintf(stdout, "(%c)", sign_bit);
   fprintf(stdout, "     ");    // padding
   fprintf(stdout, "%u%u%u%u%u%u%u", bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 2
   bit1 = (byte2 & 0x80) >> 7; // 8th byte of exponent
   bit2 = (byte2 & 0x40) >> 6; // 1st bit of mantissa
   bit3 = (byte2 & 0x20) >> 5; // 2nd bit of mantissa
   bit4 = (byte2 & 0x10) >> 4; // 3rd bit of mantissa
   bit5 = (byte2 & 0x08) >> 3; // 4th bit of mantissa
   bit6 = (byte2 & 0x04) >> 2; // 5th bit of mantissa
   bit7 = (byte2 & 0x02) >> 1; // 6th bit of mantissa
   bit8 =  byte2 & 0x01      ; // 7th bit of mantissa

   fprintf(stdout, "%u", bit1); // 8th bit of exponent
   fprintf(stdout, "   ");       // padding
   fprintf(stdout, "%u%u%u%u%u%u%u", bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 3
   bit1 = (byte3 & 0x80) >> 7; // 8th bit of mantissa
   bit2 = (byte3 & 0x40) >> 6; // 9th bit of mantissa
   bit3 = (byte3 & 0x20) >> 5; // 10th bit of mantissa
   bit4 = (byte3 & 0x10) >> 4; // 11th bit of mantissa
   bit5 = (byte3 & 0x08) >> 3; // 12th bit of mantissa
   bit6 = (byte3 & 0x04) >> 2; // 13th bit of mantissa
   bit7 = (byte3 & 0x02) >> 1; // 14th bit of mantissa
   bit8 =  byte3 & 0x01      ; // 15th bit of mantissa

   fprintf(stdout, "%u%u%u%u%u%u%u%u", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 4
   bit1 = (byte4 & 0x80) >> 7; // 16th bit of mantissa
   bit2 = (byte4 & 0x40) >> 6; // 17th bit of mantissa
   bit3 = (byte4 & 0x20) >> 5; // 18th bit of mantissa
   bit4 = (byte4 & 0x10) >> 4; // 19th bit of mantissa
   bit5 = (byte4 & 0x08) >> 3; // 20th bit of mantissa
   bit6 = (byte4 & 0x04) >> 2; // 21st bit of mantissa
   bit7 = (byte4 & 0x02) >> 1; // 22nd bit of mantissa
   bit8 =  byte4 & 0x01      ; // 23rd bit of mantissa

   fprintf(stdout, "%u%u%u%u%u%u%u%u", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   fprintf(stdout, "\n");

   fprintf(stdout, "Minus bias:    -7F\n");
   fprintf(stdout, "Real exp  ");
   fprintf(stdout, "%8d", (expon - 0x7F));
   fprintf(stdout, "\n");

   return(0);
}

