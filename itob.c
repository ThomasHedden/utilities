#include <stdio.h>
#include <stdlib.h> // needed for strtoll()
#include <errno.h>  // needed for errno
#include <limits.h> // needed for INT_MAX etc.

/* Written by Thomas Hedden January 2024.
   This program shows the bit patterns for
   integer commmand line arguments. The
   integers can be of any length:
   1 byte (char), 2 bytes (short int),
   4 bytes (int), or 8 bytes (long), and
   they can be written as decimal integers,
   hexadecimal integers (e.g., 0x41),
   or as octal integers (e.g., 0755).
   Only as many bytes are shown as are
   necessary to represent the data type.
   This program only handles integers:
   conversion stops at the first non-
   numeric character detected, so floats
   will be truncated at the decimal point,
   and alphabetic characters (A, B, C,
   etc.) will return 00000000.
   The bit patterns of multiple arguments
   are output on separate lines, and,
   if an integer requires more than one
   byte, the bytes are separated by spaces.
   For example, the following command ...
   $ itob 65 0x41 53398 
   ... has the following output:
   01000001 
   01000001 
   11010000 10010110 */

char * showbits(char *, char);
void error_check(char *, long long int, char *);

int main(int argc, char * argv[]) {
   // test for input, output syntax message
   if(argc < 2) {
      fprintf(stderr, "syntax: %s integer(s)\n", argv[0]);
      exit(1);
   }

   // mystr will hold bit representation of each passed char
   char * mystr = malloc(sizeof(char) * 8 + 1); // + 1 for \0
   if(mystr == NULL) {
      fprintf(stderr, "unable to allocate memory for mystr\n");
      exit(1);
   }

   // holds integer value of each command line parameter
   // once it has been converted from string argv[i]
   long long int n;

   // holds bit pattern of each byte in n
   char c;

   // used for error checking
   char *end;

   for(int i = 1; i < argc; i++) {
      errno = 0;
      // convert command line parameter from string
      // to long long int
      // assigning 0 as last argument to strtoll() makes
      // it recognize numbers as decimal (if they don't
      // begin with 0), hexadecimal (if they begin with
      // 0x), or octal (if they begin with 0 but not 0x).
      n = strtoll(argv[i], &end, 0);

      // one-byte range
      if(n >= -128 && n <= 255) {
         c = (char) n;
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s", mystr);
         fprintf(stdout, "     ");
         // check for errors
         error_check(argv[i], n, end);
         continue;
      }
      // two-byte range
      if(n >= -32768 && n <= 65535) {
         // high-order byte
         c = (0xFF00 & n) >> 8;
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // low-order byte
         c = (0x00FF & n);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s", mystr);
         fprintf(stdout, "     ");
         // check for errors
         error_check(argv[i], n, end);
         continue;
      }
      // four-byte range
      if(n >= -2147483648 && n <= 4294967295) {
         // highest-order byte
         c = (0xFF000000 & n) >> 24;
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // second highest-order byte
         c = (0x00FF0000 & n) >> 16;
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // second lowest-order byte
         c = (0x0000FF00 & n) >> 8;;
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // lowest-order byte
         c = (0x000000FF & n);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s", mystr);
         fprintf(stdout, "     ");
         // check for errors
         error_check(argv[i], n, end);
         continue;
      }
      // eight-byte range
      if(n >= -9223372036854775808 && n <= 18446744073709551615) {
         // highest-order byte
         c = ((0xFF00000000000000 & n) >> 56);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // second highest-order byte
         c = ((0x00FF000000000000 & n) >> 48);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // third highest-order byte
         c = ((0x0000FF0000000000 & n) >> 40);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // fourth highest-order byte
         c = ((0x000000FF00000000 & n) >> 32);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // fourth lowest-order byte
         c = ((0x00000000FF000000 & n) >> 24);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // third lowest-order byte
         c = ((0x0000000000FF0000 & n) >> 16);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // second lowest-order byte
         c = ((0x000000000000FF00 & n) >> 8);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s ", mystr);
         // lowest-order byte
         c = (0x00000000000000FF & n);
         mystr = showbits(mystr, c);
         fprintf(stdout, "%s", mystr);
         fprintf(stdout, "     ");
         // check for errors
         error_check(argv[i], n, end);
         continue;
      }
   }
   free(mystr);
   return(0);
}

