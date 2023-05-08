
/* { dg-skip-if "requires io" { freestanding } }  */

/* This test tests complex conjugate and passing/returning of
   complex parameter.  */

#include <stdlib.h>
#include <stdio.h>


int e;
__complex__ float ctest_float (__complex__ float x) { __complex__ float res; res = ~x; return res; } void test_float (void) { __complex__ float res, x; x = 1.0 + 2.0i; res = ctest_float (x); if (res != 1.0 - 2.0i) { printf ("test_" "float" " failed\n"); ++e; } }
__complex__ double ctest_double (__complex__ double x) { __complex__ double res; res = ~x; return res; } void test_double (void) { __complex__ double res, x; x = 1.0 + 2.0i; res = ctest_double (x); if (res != 1.0 - 2.0i) { printf ("test_" "double" " failed\n"); ++e; } }
__complex__ long double ctest_long_double (__complex__ long double x) { __complex__ long double res; res = ~x; return res; } void test_long_double (void) { __complex__ long double res, x; x = 1.0 + 2.0i; res = ctest_long_double (x); if (res != 1.0 - 2.0i) { printf ("test_" "long_double" " failed\n"); ++e; } }
__complex__ int ctest_int (__complex__ int x) { __complex__ int res; res = ~x; return res; } void test_int (void) { __complex__ int res, x; x = 1.0 + 2.0i; res = ctest_int (x); if (res != 1.0 - 2.0i) { printf ("test_" "int" " failed\n"); ++e; } }
__complex__ long int ctest_long_int (__complex__ long int x) { __complex__ long int res; res = ~x; return res; } void test_long_int (void) { __complex__ long int res, x; x = 1.0 + 2.0i; res = ctest_long_int (x); if (res != 1.0 - 2.0i) { printf ("test_" "long_int" " failed\n"); ++e; } }

int
main (void)
{

  e = 0;

  test_float ();
  test_double ();
  test_long_double ();
  test_int ();
  test_long_int ();

  if (e != 0)
    abort ();

  return 0;
}
