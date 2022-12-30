#include <stdio.h>
#include <stdlib.h>   // needed for exit()

/***************************************************************/
/*                           README                            */
/***************************************************************/
/* This program takes a Unicode character in the form of the
   UTF-8 character and converts it into the corresponding
   Unicode code point in the form U+(hex value).
   For example, the Russian capital letter Ж (ZH), which
   corresponds to 0xD096, is converted into Unicode code point
   U+0416. Written by Thomas Hedden April 2021. */

/***************************************************************/
/*                 THINGS THAT NEED ATTENTION                  */
/***************************************************************/
// #include's and #define's should be bracketed by INFDEFINE's
// need to allow more than one UTF-8 character to be input
// without resulting in stack crashing. See utox.c for code.

/***************************************************************/
/*               STRUCT DECLARATIONS AND TYPEDEFS              */
/***************************************************************/
/* to make it quicker to declare a nice small data type        */
typedef unsigned int UNT; // to hold value of UTF-8 char
typedef short int    IT;  // for loop iterators

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
UNT getu(char *, int *);
UNT decode_utf8(unsigned int); // returns U code point of
                               // input hex value

/***************************************************************
*                         MAIN FUNCTION                        *
***************************************************************/
int main(int argc, char *argv[]) {
   // this program requires that the size of an int be 4 bytes
   if( sizeof(int) != 4 ) { 
      fprintf(stderr, "sizeof(int) is not 4!\n");
      exit(EXIT_FAILURE);
   }
   /************************************************************
   *                  VARIABLE DECLARATIONS                    *
   ************************************************************/
   UNT u = 0;
   IT i; // loop iterator
   IT j; // loop iterator

   /************************************************************
   *                       CHECK INPUT                         *
   ************************************************************/
   if(argc < 2) {
      // print usage message
      fprintf(stderr, "Usage: %s UTF-8 text\n", argv[0]);
      exit(EXIT_FAILURE);
   } else {
      // cycle through each positional parameter
      for(IT i = 1; argv[i] != NULL; i++) {
         // cycle through each UTF-8 character in this positional parameter
         for(int j = 0; (u = getu(argv[i], &j)) != '\0'; j++) {
            // calculate value of corresponding unsigned int
            fprintf(stdout, "U+%04X", decode_utf8(u));
	    fprintf(stdout, " ");
         }
	 fprintf(stdout, "\n");
      }
   }
   return(0);
}

/***************************************************************/
/*                    FUNCTION DEFINITIONS                     */
/***************************************************************/
// all functions have been put in separate files

