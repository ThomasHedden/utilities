#include <stdio.h>
#include <stdlib.h> // needed for exit()

/***************************************************************/
/*                           README                            */
/***************************************************************/
/* This program takes a Unicode code point in the form
   U+(hex value) and converts it into the hexadecimal value of
   the corresponding UTF-8 character. For example, Unicode code
   point U+0416 is converted to 0xD096, which corresponds to
   Russian capital letter Ж (ZH).
   Written by Thomas Hedden March 2021. Revised January 2022g.
*/

/***************************************************************/
/*                 THINGS THAT NEED ATTENTION                  */
/***************************************************************/
/* #include's should be bracketed by INFDEFINE's
   testing statements should be removed
*/

/***************************************************************/
/*               STRUCT DECLARATIONS AND TYPEDEFS              */
/***************************************************************/
typedef unsigned int UNT;
typedef unsigned char UNC;

UNT encode_utf8(UNT);
// UNT putuchar(UNT);

int main(int argc, char *argv[]) {
   // variable declarations
   UNT ucp; // holds Unicode code point passed as CL argument

   // this program requires that the size of an int be 4 bytes
   if( sizeof(int) != 4 ) {
      fprintf(stderr, "sizeof(int) is not 4!\n");
      exit(EXIT_FAILURE);
   }

   if( argc == 2 ) {
      ucp = (unsigned int) strtoul(argv[1], NULL, 16);
   } else {
      printf("Usage: %s Unicode code point\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // putuchar( encode_utf8(ucp) );
   // fprintf(stdout, "\n");

   fprintf(stdout, "0x%X\n", encode_utf8(ucp) );

   return(0);
}

