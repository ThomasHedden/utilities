#include <stdio.h>

/* When run on a computer whose processor is little endian,
   this program prints "computer is little endian";
   when run on a computer whose processor is big endian,
   this program prints "computer is big endian".
*/

int machineEndianness(void);

int main(void) {
   fprintf(stderr, "computer is %s\n", machineEndianness() ? "big endian" : "little endian");
   return(0);
}


