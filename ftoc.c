#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   unsigned short int i; // iterator
   for(i = 1; i < argc; i++) {
      fprintf(stdout, "%s degrees F is %.1f degrees C\n", argv[i], (5*(atof(argv[i]) - 32))/9);
   }
   return(0);
}
