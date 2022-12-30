#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char * char_to_binary(char);

int main(int argc, char *argv[]) {
   char c;

   if( argc == 2 ) {
      c = (char) * argv[1];
   } else {
      fprintf(stderr, "Usage: %s char\n", argv[0]);
      exit(1);
   }

   fprintf(stdout, "The input is %s\n", argv[1]);
   fprintf(stdout, "The char input is %c\n", c);

   char * binary_rep = char_to_binary(c);

   fprintf(stdout, "The binary representation is:\n");
   fprintf(stdout, "%s\n", binary_rep);

   free(binary_rep);

   return(0);
}

char * char_to_binary(char c) {
   fprintf(stdout, "The char in the function char_to_binary() is:\n");
   fprintf(stdout, "%c\n", c);
   unsigned int u = (unsigned int) c;
   printf("In char_to_binary the value of u is %u\n", u);
   if( u > 255 ) {
      fprintf(stderr, "input is not a char\n");
      exit(1);
   }
   // byte 1 is the leftmost byte
   // byte 4 is the rightmost byte
   unsigned char byte4 = (char) (u & 0x000000FF);

   // byte 4
   char * string_from_function = malloc( 8 + 1 ); // +1 for \0
   if(string_from_function == NULL) {
      fprintf(stderr, "unable to allocate memory for string in function\n");
      exit(1);
   } else {
      string_from_function[0] = (char) (byte4 & 0x80) >> 7;
      string_from_function[1] = (char) (byte4 & 0x40) >> 6;
      string_from_function[2] = (char) (byte4 & 0x20) >> 5;
      string_from_function[3] = (char) (byte4 & 0x10) >> 4;
      string_from_function[4] = (char) (byte4 & 0x08) >> 3;
      string_from_function[5] = (char) (byte4 & 0x04) >> 2;
      string_from_function[6] = (char) (byte4 & 0x02) >> 1;
      string_from_function[7] = (char)  byte4 & 0x01      ;
      string_from_function[8] = '\0';
   }

   // char string_from_function[] = "01000001";

   // printf("In char_to_binary the string binary_rep() is %c%c%c%c%c%c%c%c\n", 
   printf("In char_to_binary the string binary_rep() is %c %c %c %c %c %c %c %c\n", 
      string_from_function[0],
      string_from_function[1],
      string_from_function[2],
      string_from_function[3],
      string_from_function[4],
      string_from_function[5],
      string_from_function[6],
      string_from_function[7] );

   printf("In char_to_binary the pointer to the string binary_rep() is %p\n", string_from_function);
   printf("In char_to_binary the size of the string binary_rep() is %zu\n", sizeof(string_from_function));
   printf("In char_to_binary the string binary_rep() is %s\n", string_from_function);
   return(string_from_function);
};

