#include <stdio.h>
#include <stdlib.h>

// This program takes a hexadecimal unsigned long int
// as a command-line argument and prints that number
// in binary form (in bits).
// It requires that a long int have 8 bytes.
// It can handle values <= 0xFFFFFFFFFFFFFFFF

int main(int argc, char *argv[]) {
   // this program requires that a long int have 8 bytes
   if( sizeof(long int) != 8 ) {
      fprintf(stderr, "sizeof(long int) is not 8!\n");
      exit(88);
   }

   unsigned long int lu = 0;
   if( argc == 2 ) {
      lu = strtoull(argv[1], NULL, 16);
   } else {
      printf("Usage: %s hexadecimal number w/o 0x\n", argv[0]);
      exit(1);
   }

   // byte 1 is the leftmost byte
   unsigned int byte1 = 0;
   unsigned int byte2 = 0;
   unsigned int byte3 = 0;
   unsigned int byte4 = 0;
   unsigned int byte5 = 0;
   unsigned int byte6 = 0;
   unsigned int byte7 = 0;
   unsigned int byte8 = 0;
   // bit1 is the leftmost bit of the respective byte
   unsigned int bit1 = 0;
   unsigned int bit2 = 0;
   unsigned int bit3 = 0;
   unsigned int bit4 = 0;
   unsigned int bit5 = 0;
   unsigned int bit6 = 0;
   unsigned int bit7 = 0;
   unsigned int bit8 = 0;

   byte1 = (lu & 0xFF00000000000000) >> 56;
   byte2 = (lu & 0x00FF000000000000) >> 48;
   byte3 = (lu & 0x0000FF0000000000) >> 40;
   byte4 = (lu & 0x000000FF00000000) >> 32;
   byte5 = (lu & 0x00000000FF000000) >> 24;
   byte6 = (lu & 0x00FF000000FF0000) >> 16;
   byte7 = (lu & 0x0000FF000000FF00) >>  8;
   byte8 =  lu & 0x00000000000000FF       ;

   printf("The hexadecimal value input is %s\n", argv[1]);
//   printf("The hexadecimal value of %s is 0x%08lx\n", argv[1], lu);
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
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 2
   bit1 = (byte2 & 0x80) >> 7;
   bit2 = (byte2 & 0x40) >> 6;
   bit3 = (byte2 & 0x20) >> 5;
   bit4 = (byte2 & 0x10) >> 4;
   bit5 = (byte2 & 0x08) >> 3;
   bit6 = (byte2 & 0x04) >> 2;
   bit7 = (byte2 & 0x02) >> 1;
   bit8 =  byte2 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 3
   bit1 = (byte3 & 0x80) >> 7;
   bit2 = (byte3 & 0x40) >> 6;
   bit3 = (byte3 & 0x20) >> 5;
   bit4 = (byte3 & 0x10) >> 4;
   bit5 = (byte3 & 0x08) >> 3;
   bit6 = (byte3 & 0x04) >> 2;
   bit7 = (byte3 & 0x02) >> 1;
   bit8 =  byte3 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 4
   bit1 = (byte4 & 0x80) >> 7;
   bit2 = (byte4 & 0x40) >> 6;
   bit3 = (byte4 & 0x20) >> 5;
   bit4 = (byte4 & 0x10) >> 4;
   bit5 = (byte4 & 0x08) >> 3;
   bit6 = (byte4 & 0x04) >> 2;
   bit7 = (byte4 & 0x02) >> 1;
   bit8 =  byte4 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 5
   bit1 = (byte5 & 0x80) >> 7;
   bit2 = (byte5 & 0x40) >> 6;
   bit3 = (byte5 & 0x20) >> 5;
   bit4 = (byte5 & 0x10) >> 4;
   bit5 = (byte5 & 0x08) >> 3;
   bit6 = (byte5 & 0x04) >> 2;
   bit7 = (byte5 & 0x02) >> 1;
   bit8 =  byte5 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 6
   bit1 = (byte6 & 0x80) >> 7;
   bit2 = (byte6 & 0x40) >> 6;
   bit3 = (byte6 & 0x20) >> 5;
   bit4 = (byte6 & 0x10) >> 4;
   bit5 = (byte6 & 0x08) >> 3;
   bit6 = (byte6 & 0x04) >> 2;
   bit7 = (byte6 & 0x02) >> 1;
   bit8 =  byte6 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 7
   bit1 = (byte7 & 0x80) >> 7;
   bit2 = (byte7 & 0x40) >> 6;
   bit3 = (byte7 & 0x20) >> 5;
   bit4 = (byte7 & 0x10) >> 4;
   bit5 = (byte7 & 0x08) >> 3;
   bit6 = (byte7 & 0x04) >> 2;
   bit7 = (byte7 & 0x02) >> 1;
   bit8 =  byte7 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);

   // byte 8
   bit1 = (byte8 & 0x80) >> 7;
   bit2 = (byte8 & 0x40) >> 6;
   bit3 = (byte8 & 0x20) >> 5;
   bit4 = (byte8 & 0x10) >> 4;
   bit5 = (byte8 & 0x08) >> 3;
   bit6 = (byte8 & 0x04) >> 2;
   bit7 = (byte8 & 0x02) >> 1;
   bit8 =  byte8 & 0x01      ;
   printf("%u%u%u%u%u%u%u%u ", bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8);
   printf("\n");

   return(0);
}

