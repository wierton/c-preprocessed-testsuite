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
   AIX and Darwin.  */
static float Yf[] = { 2.0, -2.0, -2.0, -2.0, -2.0, 2.0, -0.0, __builtin_inff () }; static const float Zf[] = { 1.0, -1.0, -1.0, -0.0, -0.0, 0.0, -__builtin_inff (), __builtin_nanf ("") }; void testf (void) { float r[8]; int i; r[0] = __builtin_copysignf (1.0, Yf[0]); r[1] = __builtin_copysignf (1.0, Yf[1]); r[2] = __builtin_copysignf (-1.0, Yf[2]); r[3] = __builtin_copysignf (0.0, Yf[3]); r[4] = __builtin_copysignf (-0.0, Yf[4]); r[5] = __builtin_copysignf (-0.0, Yf[5]); r[6] = __builtin_copysignf (__builtin_inff (), Yf[6]); r[7] = __builtin_copysignf (-__builtin_nanf (""), Yf[7]); for (i = 0; i < 8; ++i) if (memcmp (r+i, Zf+i, sizeof(float)) != 0) abort (); }
static double Y[] = { 2.0, -2.0, -2.0, -2.0, -2.0, 2.0, -0.0, __builtin_inf () }; static const double Z[] = { 1.0, -1.0, -1.0, -0.0, -0.0, 0.0, -__builtin_inf (), __builtin_nan ("") }; void test (void) { double r[8]; int i; r[0] = __builtin_copysign (1.0, Y[0]); r[1] = __builtin_copysign (1.0, Y[1]); r[2] = __builtin_copysign (-1.0, Y[2]); r[3] = __builtin_copysign (0.0, Y[3]); r[4] = __builtin_copysign (-0.0, Y[4]); r[5] = __builtin_copysign (-0.0, Y[5]); r[6] = __builtin_copysign (__builtin_inf (), Y[6]); r[7] = __builtin_copysign (-__builtin_nan (""), Y[7]); for (i = 0; i < 8; ++i) if (memcmp (r+i, Z+i, sizeof(double)) != 0) abort (); }
static long double Yl[] = { 2.0, -2.0, -2.0, -2.0, -2.0, 2.0, -0.0, __builtin_infl () }; static const long double Zl[] = { 1.0, -1.0, -1.0, -0.0, -0.0, 0.0, -__builtin_infl (), __builtin_nanl ("") }; void testl (void) { long double r[8]; int i; r[0] = __builtin_copysignl (1.0, Yl[0]); r[1] = __builtin_copysignl (1.0, Yl[1]); r[2] = __builtin_copysignl (-1.0, Yl[2]); r[3] = __builtin_copysignl (0.0, Yl[3]); r[4] = __builtin_copysignl (-0.0, Yl[4]); r[5] = __builtin_copysignl (-0.0, Yl[5]); r[6] = __builtin_copysignl (__builtin_infl (), Yl[6]); r[7] = __builtin_copysignl (-__builtin_nanl (""), Yl[7]); for (i = 0; i < 8; ++i) if (memcmp (r+i, Zl+i, 10) != 0) abort (); }

int main()
{
  testf();
  test();
  testl();
  return 0;
}
