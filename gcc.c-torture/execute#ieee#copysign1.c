#include <string.h>
#include <stdlib.h>
#include <float.h>






/* Work around the fact that with the Intel double-extended precision,
   we've got a 10 byte type stuffed into some amount of padding.  And
   the fact that -ffloat-store is going to stuff this value temporarily
   into some bit of stack frame that we've no control over and can't zero.  */







/* Work around the fact that the sign of the second double in the IBM
   double-double format is not strictly specified when it contains a zero.
   For instance, -0.0L can be represented with either (-0.0, +0.0) or
   (-0.0, -0.0).  The former is what we'll get from the compiler when it
   builds constants; the later is what we'll get from the negation operator
   at runtime.  */
/* ??? This hack only works for big-endian, which is fortunately true for
   AIX and, Darwin.  */
float cf (float x, float y) { return __builtin_copysignf (x, y); } struct Df { float x, y, z; }; static const struct Df Tf[] = { { 1.0, 2.0, 1.0 }, { 1.0, -2.0, -1.0 }, { -1.0, -2.0, -1.0 }, { 0.0, -2.0, -0.0 }, { -0.0, -2.0, -0.0 }, { -0.0, 2.0, 0.0 }, { __builtin_inff (), -0.0, -__builtin_inff () }, { -__builtin_nanf (""), __builtin_inff (), __builtin_nanf ("") } }; void testf (void) { int i, n = sizeof (Tf) / sizeof (Tf[0]); float r; for (i = 0; i < n; ++i) { r = cf (Tf[i].x, Tf[i].y); if (memcmp (&r, &Tf[i].z, sizeof(float)) != 0) abort (); } }
double c (double x, double y) { return __builtin_copysign (x, y); } struct D { double x, y, z; }; static const struct D T[] = { { 1.0, 2.0, 1.0 }, { 1.0, -2.0, -1.0 }, { -1.0, -2.0, -1.0 }, { 0.0, -2.0, -0.0 }, { -0.0, -2.0, -0.0 }, { -0.0, 2.0, 0.0 }, { __builtin_inf (), -0.0, -__builtin_inf () }, { -__builtin_nan (""), __builtin_inf (), __builtin_nan ("") } }; void test (void) { int i, n = sizeof (T) / sizeof (T[0]); double r; for (i = 0; i < n; ++i) { r = c (T[i].x, T[i].y); if (memcmp (&r, &T[i].z, sizeof(double)) != 0) abort (); } }
long double cl (long double x, long double y) { return __builtin_copysignl (x, y); } struct Dl { long double x, y, z; }; static const struct Dl Tl[] = { { 1.0, 2.0, 1.0 }, { 1.0, -2.0, -1.0 }, { -1.0, -2.0, -1.0 }, { 0.0, -2.0, -0.0 }, { -0.0, -2.0, -0.0 }, { -0.0, 2.0, 0.0 }, { __builtin_infl (), -0.0, -__builtin_infl () }, { -__builtin_nanl (""), __builtin_infl (), __builtin_nanl ("") } }; void testl (void) { int i, n = sizeof (Tl) / sizeof (Tl[0]); long double r; for (i = 0; i < n; ++i) { r = cl (Tl[i].x, Tl[i].y); if (memcmp (&r, &Tl[i].z, 10) != 0) abort (); } }

int main()
{
  testf();
  test();
  testl();
  return 0;
}
