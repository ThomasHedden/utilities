#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   // this program requires that an int have 4 bytes
   if( sizeof(int) != 4 ) {
      fprintf(stderr, "sizeof(int) is not 4!\n");
      exit(44);
   }

   unsigned int u = 0;
   // byte 1 is the leftmost byte
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
      u = strtoul(argv[1], NULL, 10);
   } else {
      printf("Usage: %s decimal number\n", argv[0]);
      exit(1);
   }

   byte1 = (u & 0xFF000000) >> 24;
   byte2 = (u & 0x00FF0000) >> 16;
   byte3 = (u & 0x0000FF00) >>  8;
   byte4 =  u & 0x000000FF;

   printf("The decimal value input is %s\n", argv[1]);
   printf("The hexadecimal value of %s is 0x%04x\n", argv[1], u);
   printf("The binary representation of %s is:\n", argv[1]);

   // byte 1
   bit1 = (byte1 & 0x80) >> 7;
   bit2 = (byte1 & 0x40) >> 6;
   bit3 = (byte1 & 0x20) >> 5;
   bit4 = (byte1 & 0x10) >> 4;
   bit5 = (byte1 & 0x08) >> 3;
   bit6 = (byte1 & 0x04) >> 2;
   bit7 = (byte1 & 0x02) >> 1;
   bit8 =  byte1 & 0x01      ;

   // printf("The values of the bits for byte1 are:\n");
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   // printf("\n");
   /* printf("The value of bit1 of byte1 is %u\n", bit1);
   printf("The value of bit2 of byte1 is %u\n", bit2);
   printf("The value of bit3 of byte1 is %u\n", bit3);
   printf("The value of bit4 of byte1 is %u\n", bit4);
   printf("The value of bit5 of byte1 is %u\n", bit5);
   printf("The value of bit6 of byte1 is %u\n", bit6);
   printf("The value of bit7 of byte1 is %u\n", bit7);
   printf("The value of bit8 of byte1 is %u\n", bit8);
   */

   // byte 2
   bit1 = (byte2 & 0x80) >> 7;
   bit2 = (byte2 & 0x40) >> 6;
   bit3 = (byte2 & 0x20) >> 5;
   bit4 = (byte2 & 0x10) >> 4;
   bit5 = (byte2 & 0x08) >> 3;
   bit6 = (byte2 & 0x04) >> 2;
   bit7 = (byte2 & 0x02) >> 1;
   bit8 =  byte2 & 0x01      ;

   // printf("The values of the bits for byte2 are:\n");
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   // printf("\n");
   /* printf("The value of bit1 of byte2 is %u\n", bit1);
   printf("The value of bit2 of byte2 is %u\n", bit2);
   printf("The value of bit3 of byte2 is %u\n", bit3);
   printf("The value of bit4 of byte2 is %u\n", bit4);
   printf("The value of bit5 of byte2 is %u\n", bit5);
   printf("The value of bit6 of byte2 is %u\n", bit6);
   printf("The value of bit7 of byte2 is %u\n", bit7);
   printf("The value of bit8 of byte2 is %u\n", bit8);
   */

   // byte 3
   bit1 = (byte3 & 0x80) >> 7;
   bit2 = (byte3 & 0x40) >> 6;
   bit3 = (byte3 & 0x20) >> 5;
   bit4 = (byte3 & 0x10) >> 4;
   bit5 = (byte3 & 0x08) >> 3;
   bit6 = (byte3 & 0x04) >> 2;
   bit7 = (byte3 & 0x02) >> 1;
   bit8 =  byte3 & 0x01      ;

   // printf("The values of the bits for byte3 are:\n");
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   // printf("\n");
   /* printf("The value of bit1 of byte3 is %u\n", bit1);
   printf("The value of bit2 of byte3 is %u\n", bit2);
   printf("The value of bit3 of byte3 is %u\n", bit3);
   printf("The value of bit4 of byte3 is %u\n", bit4);
   printf("The value of bit5 of byte3 is %u\n", bit5);
   printf("The value of bit6 of byte3 is %u\n", bit6);
   printf("The value of bit7 of byte3 is %u\n", bit7);
   printf("The value of bit8 of byte3 is %u\n", bit8);
   */

   // byte 4
   bit1 = (byte4 & 0x80) >> 7;
   bit2 = (byte4 & 0x40) >> 6;
   bit3 = (byte4 & 0x20) >> 5;
   bit4 = (byte4 & 0x10) >> 4;
   bit5 = (byte4 & 0x08) >> 3;
   bit6 = (byte4 & 0x04) >> 2;
   bit7 = (byte4 & 0x02) >> 1;
   bit8 =  byte4 & 0x01      ;

   // printf("The values of the bits for byte4 are:\n");
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   printf("\n");
   /* printf("The value of bit1 of byte4 is %u\n", bit1);
   printf("The value of bit2 of byte4 is %u\n", bit2);
   printf("The value of bit3 of byte4 is %u\n", bit3);
   printf("The value of bit4 of byte4 is %u\n", bit4);
   printf("The value of bit5 of byte4 is %u\n", bit5);
   printf("The value of bit6 of byte4 is %u\n", bit6);
   printf("The value of bit7 of byte4 is %u\n", bit7);
   printf("The value of bit8 of byte4 is %u\n", bit8);
   */

   return(0);
}

