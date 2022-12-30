// This program displays the size in bytes of common data types
// and also the upper and lower limits of each of these types.
// Signed data types always have lower limits of zero.
// Tom Hedden December 2, 2017, revised May 31, 2020

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <float.h> // needed to use float macros
// #include <stdint.h>

int main(void) {
   fprintf(stdout, "\n");

   fprintf(stdout, "The size in bytes of a bool is %zu\n", sizeof(bool));
   // printf("The smallest value of a bool is %d\n", SCHAR_MIN);
   // printf("The largest value of a bool is %d\n", SCHAR_MAX);
   fprintf(stdout, "\n");

   fprintf(stdout, "The size in bytes of a pointer to a bool is %zu\n", sizeof(bool *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a signed char is %zu\n", sizeof(signed char));
   printf("The smallest value of a signed char is %d\n", SCHAR_MIN);
   printf("The largest value of a signed char is %d\n", SCHAR_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a signed char is %zu\n", sizeof(signed char *));
   fprintf(stdout, "\n");

   printf("The size in bytes of an unsigned char is %zu\n", sizeof(unsigned char));
   printf("The largest value of an unsigned char is %u\n", UCHAR_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to an unsigned char is %zu\n", sizeof(unsigned char *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a signed short int is %zu\n", sizeof(signed short int));
   printf("The smallest value of a signed short int is %d\n", SHRT_MIN);
   printf("The largest value of a signed short int is %d\n", SHRT_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a signed short int is %zu\n", sizeof(signed short int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of an unsigned short int is %zu\n", sizeof(unsigned short int));
   printf("The largest value of an unsigned short int is %u\n", USHRT_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of pointer to an unsigned short int is %zu\n", sizeof(unsigned short int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a signed int is %zu\n", sizeof(signed int));
   printf("The smallest value of a signed int is %d\n", INT_MIN);
   printf("The largest value of a signed int is %d\n", INT_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a signed int is %zu\n", sizeof(signed int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of an unsigned int is %zu\n", sizeof(unsigned int));
   printf("The largest value of an unsigned int is %u\n", UINT_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to an unsigned int is %zu\n", sizeof(unsigned int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a signed long int is %zu\n", sizeof(signed long int));
   printf("The smallest value of a signed long int is %ld\n", LONG_MIN);
   printf("The largest value of a signed long int is %ld\n", LONG_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a signed long int is %zu\n", sizeof(signed long int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of an unsigned long int is %zu\n", sizeof(unsigned long int));
   printf("The largest value of an unsigned long int is %lu\n", ULONG_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to an unsigned long int is %zu\n", sizeof(unsigned long int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a signed long long int is %zu\n", sizeof(signed long long int));
   printf("The smallest value of a signed long long int is %lld\n", LLONG_MIN);
   printf("The largest value of a signed long long int is %lld\n", LLONG_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a signed long long int is %zu\n", sizeof(signed long long int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of an unsigned long long int is %zu\n", sizeof(unsigned long long int));
   printf("The largest value of an unsigned long long int is %llu\n", ULLONG_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to an unsigned long long int is %zu\n", sizeof(unsigned long long int *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a float is %zu\n", sizeof(float));
   printf("The smallest value of a float is %f\n", FLT_MIN);
   printf("The largest value of a float is %f\n", FLT_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a float is %zu\n", sizeof(float *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a double is %zu\n", sizeof(double));
   printf("The smallest value of a double is %g\n", DBL_MIN);
   printf("The largest value of a double is %g\n", DBL_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a double is %zu\n", sizeof(double *));
   fprintf(stdout, "\n");

   printf("The size in bytes of a long double is %zu\n", sizeof(long double));
   printf("The smallest value of a long double is %Lg\n", LDBL_MIN);
   printf("The largest value of a long double is %Lg\n", LDBL_MAX);
   fprintf(stdout, "\n");

   printf("The size in bytes of a pointer to a long double is %zu\n", sizeof(long double *));
   fprintf(stdout, "\n");

   return 0;
}

