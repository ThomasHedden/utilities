#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   unsigned int u = 0;

   if( argc == 2 ) {
      u = strtoul(argv[1], NULL, 10);
   } else {
      fprintf(stderr, "Usage: %s decimal number\n", argv[0]);
      exit(1);
   }

   // printf("The decimal value of u is 0x%04x\n", u);
   printf("%c\n", (char) u);

   return(0);
}

