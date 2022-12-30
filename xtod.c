#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   unsigned int u = 0;

   if( argc == 2 ) {
      u = strtoul(argv[1], NULL, 16);
   } else {
      printf("Usage: %s hexadecimal number w/o 0x\n", argv[0]);
      exit(1);
   }

   printf("The decimal value of 0x%x is %u\n", u, u);

   return(0);
}

