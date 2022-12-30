#include <stdio.h>
#include <stdlib.h> // needed for malloc() and exit()
#include <string.h> // needed for strlen(), strcpy(), strcat()
// #include <math.h>   // needed for pow()

int main(int argc, char *argv[]) {
   // make sure that a command line argument was provided
   if(argc < 2) {
      // otherwise, print syntax statement about usage of program
      fprintf(stderr, "Syntax: %s binary number to convert!\n", argv[0]);
      return(1);
   }
   // put all argv[]s together in one long string
   short int i; // loop iterator
   // length of argv[]s; there is at least argv[1] 
   short unsigned int length = strlen(argv[1]);
   // buffer that holds all argv[]s concatenated together
   char * all_argvs = malloc(length + 1);
   strcpy(all_argvs, argv[1]);
   if(argc >= 3) { // need to append rest of argv[]s to buffer
      for(i = 2; argv[i] != NULL; i++) {
         length += strlen(argv[i]);
         if(length > 64) { // length exceeds range for long int
            fprintf(stderr, "%d digits exceeds range for long int!\n", length);
	    exit(EXIT_FAILURE);
         }
         all_argvs = realloc(all_argvs, length);
         strcat(all_argvs, argv[i]);
      }
   } else {
      ; // do nothing: all argv[]s are already in all_argvs
   }
   unsigned long int value_to_add; // value to be added for current
                                   // twos_place
   unsigned long int total; // total value of all values of value_to_add
                            // for all places for all argv[]s concatenated
                            // together, evaluated as a binary number
   // loop through concatenated argv[]s, calculate value when
   // interpreted as a binary number, and print it out
   for(i = length - 1,
       total = 0,
       value_to_add = 1; i >= 0; i--, value_to_add *= 2) {
      if(all_argvs[i] == '0') {
         // twos place value is 0, so do not increment total
         continue;
      } else if(all_argvs[i] == '1') {
         // increment total by value_to_add for this twos place
         total += value_to_add;
         continue;
      } else {
         fprintf(stderr, "Found illegal character %c!\n", all_argvs[i]);
	 exit(EXIT_FAILURE);
      }
   }
   fprintf(stdout, "total is 0x%lX\n", total);
   return(0);
}

