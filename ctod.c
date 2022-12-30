#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if( argc != 2 ) {
      printf("Usage: %s char\n", argv[0]);
      exit(1);
   }
   char c = (char) *argv[1];
   printf("The decimal value of '%c' is %d\n", c, (int) c);
   return(0);
}

