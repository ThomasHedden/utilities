#include <stdio.h>
#include <stdlib.h>   // needed for exit()
#include <stdbool.h>  // needed for is1butf8() etc.

/***************************************************************/
/*                     #DEFINE STATEMENTS                      */
/***************************************************************/
#define MAXARRAY  80       /* size of array into which words
                              (one word per line expected)
                              from input files are placed      */
#define MXFNSZ   256       /* maximum length of filenames (using
                              Second Extended Filesystem)      */
#define MXSZVAR   32       /* maximum size of ANSI C variables,
                              including '\0'                   */

/***************************************************************/
/*                           README                            */
/***************************************************************/
/* This program takes a Unicode character in the form of the
   hexadecimal value of a UTF-8 character and converts it into
   the corresponding Unicode code point in the form U+(hex value).
   For example, 0xD096, which corresponds to Russian capital
   letter Ж (ZH) is converted into Unicode code point U+0416.
   Written by Thomas Hedden April 2021.
*/

/***************************************************************/
/*                 THINGS THAT NEED ATTENTION                  */
/***************************************************************/
// #include's and #define's should be bracketed by INFDEFINE's

/***************************************************************/
/*               STRUCT DECLARATIONS AND TYPEDEFS              */
/***************************************************************/
/* to make it quicker to declare a nice small data type        */
typedef unsigned int UNT;

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
int   putuchar(unsigned int);
bool  is1butf8(unsigned int); // returns true if 1-byte UTF-8
bool  is2butf8(unsigned int); // returns true if 2-byte UTF-8
bool  is3butf8(unsigned int); // returns true if 3-byte UTF-8
bool  is4butf8(unsigned int); // returns true if 4-byte UTF-8
int   decode_utf8(unsigned int); // returns U code point of
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
   int u;

   /************************************************************
   *                       CHECK INPUT                         *
   ************************************************************/
   if( argc == 2 ) {
      // get input from command line
      u = strtoul(argv[1], NULL, 10);
   } else {
      printf("Usage: %s decimal number\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // output original input decimal value, corresponding character,
   // and corresponding Unicode code point
   if(u < 0) {
      fprintf(stderr, "%d is not a UTF-8 character\n", u);
      exit(EXIT_FAILURE);
   }
   printf("%d ", u);
   putuchar(u);
   printf(" has Unicode code point U+%04x\n", decode_utf8(u));

   return(0);
}

/***************************************************************/
/*                    FUNCTION DEFINITIONS                     */
/***************************************************************/
// all functions have been put in separate files

