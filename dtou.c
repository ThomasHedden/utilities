#include <stdio.h>
#include <stdlib.h>  // needed for exit()
#include <stdbool.h> // needed for is1butf8(), etc.

/* This program was written by Thomas Hedden on 04 July 2020.
   It takes a command line argument of a hexadecimal number
   and prints out the UTF-8 equivalent to stdout. */

/***************************************************************
*                      NEEDED ENHANCEMENTS                     *
***************************************************************/

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
bool is1butf8(unsigned int);
bool is2butf8(unsigned int);
bool is3butf8(unsigned int);
bool is4butf8(unsigned int);

/***************************************************************
*                         MAIN FUNCTION                        *
***************************************************************/
int main(int argc, char *argv[]) {
   // this program requires that an int have 4 bytes
   if( sizeof(int) != 4 ) {
      fprintf(stderr, "sizeof(int) is not 4!\n");
      exit(EXIT_FAILURE);
   }

   unsigned int u = 0;

   if( argc == 2 ) {
      u = strtoul(argv[1], NULL, 10);
   } else {
      fprintf(stderr, "Usage: %s decimal (base 10) number\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if( is1butf8(u) ) {
      fprintf(stdout, "%c",       (char) ((u & 0x000000FF)      ));
   }
   if( is2butf8(u) ) {
      fprintf(stdout, "%c%c",     (char) ((u & 0x0000FF00) >>  8),
                                  (char) ((u & 0x000000FF)      ));
   }
   if( is3butf8(u) ) {
      fprintf(stdout, "%c%c%c",   (char) ((u & 0x00FF0000) >> 16),
                                  (char) ((u & 0x0000FF00) >>  8),
                                  (char) ((u & 0x000000FF)      ));
   }
   if( is4butf8(u) ) {
      fprintf(stdout, "%c%c%c%c", (char) ((u & 0xFF000000) >> 24),
                                  (char) ((u & 0x00FF0000) >> 16),
                                  (char) ((u & 0x0000FF00) >>  8),
                                  (char) ((u & 0x000000FF)      ));
   }
   fprintf(stdout, "\n");

   return(0);
}

/***************************************************************
*                     FUNCTION DEFINITIONS                    *
***************************************************************/
// all functions have been put into separate files

