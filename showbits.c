#include <stdio.h>
#include <stdlib.h>

/* Written by Thomas Hedden 16 January 2024.
   This function takes as its arguments a null-terminated
   string having a string length of eight (nine counting
   the terminating null) and an unsigned char.
   It is the responsibility of the calling function to
   allocate memory for the string and to free the memory
   once it is no longer needed.
   This function returns a pointer to the passed string 
   showing the bit pattern of the passed unsigned char.
   For example, if the char 'A' is passed, the returned
   string will have the value "01000001". */

char * showbits(char * ms, char c) {
   unsigned int integer_array[8] = {0};
   integer_array[0] = ((c & 0x80) >> 7);
   integer_array[1] = ((c & 0x40) >> 6);
   integer_array[2] = ((c & 0x20) >> 5);
   integer_array[3] = ((c & 0x10) >> 4);
   integer_array[4] = ((c & 0x08) >> 3);
   integer_array[5] = ((c & 0x04) >> 2);
   integer_array[6] = ((c & 0x02) >> 1);
   integer_array[7] = ((c & 0x01)     );

   for(int i = 0; i < 8; i++) {
      if(integer_array[i]) {
         ms[i] = '1';
      } else {
         ms[i] = '0';
      }
   }
   ms[8] = '\0';
   return(ms);
}

