#include <stdio.h>
#include <stdlib.h>  // needed for exit()

/* This program was written by Thomas Hedden on 25 January 2022.
   It takes a command line argument of a hexadecimal number
   and prints out the corresponding int(s) to stdout. */

/***************************************************************
*                      NEEDED ENHANCEMENTS                     *
***************************************************************/

/***************************************************************
*                     FUNCTION DECLARATIONS                    *
***************************************************************/
FILE* open_file(char*, char*);

/***************************************************************
*                         MAIN FUNCTION                        *
***************************************************************/
int main(int argc, char *argv[]) {
   // this program requires that an int have 4 bytes
   if( sizeof(int) != 4 ) {
      fprintf(stderr, "sizeof(int) is not 4!\n");
      exit(EXIT_FAILURE);
   }
   /**********************************************************
   *                        CHECK INPUT                      *
   **********************************************************/
   if( argc != 2 ) {
      fprintf(stderr, "Usage: %s filename\n", argv[0]);
      exit(1);
   }
   /**********************************************************
   *                        OPEN FILES                       *
   **********************************************************/
   FILE* fp;
   // try to open file read only; if successful, close file
   // and exit with error message that file already exists;
   // if unsuccessful, open file to write
   if ((fp = fopen(argv[1], "r")) != NULL) {
      fclose(fp);
      fprintf(stderr, "File %s already exists!\n", argv[1]);
      exit(2);
   } else {
      fp = fopen(argv[1], "w");
   }

   /*
   char c;
   unsigned int u = 0;

   if( argc == 2 ) {
      u = strtoul(argv[1], NULL, 16);
   } else {
      fprintf(stderr, "Usage: %s hexadecimal number w/o 0x\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // traverse stream
   while( c = (unsigned char) fgetc(opened_file_stream) ) { 
      if( feof(opened_file_stream) || c == EOF ) {                      // found EOF
         break;
      }
      fprintf(stdout, "%c", c);
   }
   fprintf(stdout, "\n");


   fprintf(stdout, "%X", u);

   fprintf(stdout, "\n");
*/
   /**********************************************************
   *                        CLOSE FILES                      *
   **********************************************************/
   // if file pointer is not null, close it
   if (fp != NULL) {
      fflush(fp);
      fclose(fp);
   }

   return(0);
}

/***************************************************************
*                     FUNCTION DEFINITIONS                    *
***************************************************************/
// all functions have been put into separate files

