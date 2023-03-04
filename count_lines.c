#include <stdio.h>
#include <stdlib.h>  // needed for exit()
#include <stdbool.h> // needed for iseol()

/***************************************************************
*                             README                           *
 This program counts the number of NON-BLANK lines in a text
 file, that is the number of lines that have more than an
 end-of-line character on them.
 Written by Thomas Hedden March 2023.
***************************************************************/

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
FILE*        open_file(char*, char*);
short int    line_count(FILE *);
bool         iseol(char);

/***************************************************************
*                         MAIN FUNCTION                        *
***************************************************************/
int main(int argc, char * argv[]) {
   /**********************************************************
   *                        CHECK INPUT                      *
   **********************************************************/
   if( argc != 2 ) {
      fprintf(stderr, "Usage: %s filename\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   /**********************************************************
   *                        OPEN FILES                       *
   **********************************************************/
   FILE * infp = open_file(argv[1], "r");

   /************************************************************
   *                  VARIABLE DECLARATIONS                    *
   ************************************************************/
   short int lines = 0; // number lines in file
   int       c; // declare as int so can find EOF

   lines = line_count(infp);
 
   fprintf(stdout, "file %s has %d lines\n", argv[0], lines);
 
   /**********************************************************
   *                        CLOSE FILES                      *
   **********************************************************/
   fclose(infp);

   return(0);   
}

/***************************************************************
*                     FUNCTION DEFINITTIONS                    *
***************************************************************/
// all functions have been put in separate files

