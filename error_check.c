#include <stdio.h>
#include <errno.h>
#include <limits.h>

// check for errors in conversion by strtoll()
// av is argv[i] for the current value of i;
// n is the value of argv[i] after conversion
// to a long long integer;
// end is a pointer to first byte following
// what was successfully converted;
// errno is error number;
void error_check(char * av, long long int n, char * end) {
   if (end == av) {
      (void) fprintf(stdout, "%s is not an integer\n", av);
   } else if ('\0' != *end) {
      (void) fprintf(stdout, "%s has extra characters at end of input: %s\n", av, end);
   } else if ((LONG_MIN == n || LONG_MAX == n) && ERANGE == errno) {
      (void) fprintf(stdout, "%s is out of range of type long\n", av);
   } else if (n > INT_MAX) {
      (void) fprintf(stdout, "%lld is greater than INT_MAX\n", n);
   } else if (n < INT_MIN) {
      (void) fprintf(stdout, "%lld is less than INT_MIN\n", n);
   } else {
      fprintf(stdout, "\n");
   }
}

