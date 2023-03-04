#include <stdio.h>
#include <stdlib.h>  // needed for exit()
#include <stdbool.h> // needed for iseol()

/***************************************************************
*                             README                           *
 This function counts the number of NON-BLANK lines in a text
 file, that is the number of lines that have more than an
 end-of-line character on them.
 It takes as its argument a FILE* pointer to an open file
 and returns an short int.
 Written by Thomas Hedden March 2023.
***************************************************************/

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
bool         iseol(char);

/***************************************************************
*                         MAIN FUNCTION                        *
***************************************************************/
short int line_count_of(FILE * infp) {
   /************************************************************
   *                  VARIABLE DECLARATIONS                    *
   ************************************************************/
   short int lines = 0; // no. lines in file
   int       c;         // declare as int so can find EOF
   bool      last_char_was_EOL;

   last_char_was_EOL = true;
   while( c = fgetc(infp) ) {
      if( feof(infp) || c == EOF ) { // found EOF
         break;
      }
      if((last_char_was_EOL == true) && !(iseol(c))) {
         lines++;
         last_char_was_EOL = false;
	 continue;
      }
      if(iseol(c)) {
         last_char_was_EOL = true;
         continue;
      }
      continue;
   }
 
   return(lines);   
}

/***************************************************************
*                     FUNCTION DEFINITTIONS                    *
***************************************************************/
// all functions have been put in separate files

