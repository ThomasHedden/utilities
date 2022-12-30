#include <stdio.h>
#include <stdlib.h>

/* This program takes a single base-10 number one the
   command line and prints out its hexademical equivalent. */

int main(int argc, char *argv[]) {

   unsigned int u = 0;

   if( argc == 2 ) {
      u = strtoul(argv[1], NULL, 10);
   } else {
      printf("Usage: %s decimal number\n", argv[0]);
      exit(1);
   }

   printf("The hexadecimal value of %u is 0x%04x\n", u, u);

   return(0);
}

