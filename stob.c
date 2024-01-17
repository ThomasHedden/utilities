#include <stdio.h>
#include <stdlib.h>

/* Written by Thomas Hedden 17 January 2024.
   This program shows the bit patterns for
   commmand line arguments. The bit patterns
   of multiple arguments are output on separate
   lines. The bit patterns of mulitple bytes
   within the same argument are separated by
   spaces. For example, the following command ...
   $ stob A AB Ж
   ... has the following output:
   01000001 
   01000001 01000010 
   11010000 10010110 */

char * showbits(char *, char);

int main(int argc, char * argv[]) {
   // test for input, output syntax message
   if(argc < 2) {
      fprintf(stderr, "syntax: %s string(s)\n", argv[0]);
      exit(1);
   }

   // mystr will hold bit representation of each passed char
   char * mystr = malloc(sizeof(char) * 8 + 1);
   if(mystr == NULL) {
      fprintf(stderr, "unable to allocate memory for mystr\n");
      exit(1);
   }

   char c; // byte whose bit pattern will be put in string
   // cycle through all command-line arguments
   for(int i = 1; i < argc; i++) {
      // cycle through all bytes in each command-line argument
      for(int j = 0; argv[i][j] != '\0'; j++) {
         c = argv[i][j];
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
      }
      fprintf(stdout, "\n");
   }
   free(mystr);
   return(0);
}

