#include <stdio.h>

/* This function returns 0 if the system
   on which it is run is little endian,
   and 1 if the system on which it is
   run is big endian.
*/

int machineEndianness(void) {
   short s = 0x0102;
   char *p = (char *) &s;
   if (p[0] == 0x02) // Lowest address contains least significant byte
      return 0; // little endian
   else
      return 1; // big endian
}

