
/* Test for builtin abs, labs, llabs, imaxabs.  */
/* Origin: Joseph Myers <jsm28@cam.ac.uk> */

#include <limits.h>

typedef long int intmax_t;


extern int abs (int);
extern long labs (long);
extern long long llabs (long long);
extern intmax_t imaxabs (intmax_t);
extern void abort (void);
extern void link_error (void);

void
main_test (void)
{
  /* For each type, test both runtime and compile time (constant folding)
     optimization.  */
  volatile int i0 = 0, i1 = 1, im1 = -1, imin = -0x7fffffff, imax = 0x7fffffff;
  volatile long l0 = 0L, l1 = 1L, lm1 = -1L, lmin = -0x7fffffffffffffffL, lmax = 0x7fffffffffffffffL;
  volatile long long ll0 = 0LL, ll1 = 1LL, llm1 = -1LL;
  volatile long long llmin = -0x7fffffffffffffffLL, llmax = 0x7fffffffffffffffLL;
  volatile intmax_t imax0 = 0, imax1 = 1, imaxm1 = -1;
  volatile intmax_t imaxmin = -0x7fffffffffffffffL, imaxmax = 0x7fffffffffffffffL;
  if (abs (i0) != 0)
    abort ();
  if (abs (0) != 0)
    link_error ();
  if (abs (i1) != 1)
    abort ();
  if (abs (1) != 1)
    link_error ();
  if (abs (im1) != 1)
    abort ();
  if (abs (-1) != 1)
    link_error ();
  if (abs (imin) != 0x7fffffff)
    abort ();
  if (abs (-0x7fffffff) != 0x7fffffff)
    link_error ();
  if (abs (imax) != 0x7fffffff)
    abort ();
  if (abs (0x7fffffff) != 0x7fffffff)
    link_error ();
  if (labs (l0) != 0L)
    abort ();
  if (labs (0L) != 0L)
    link_error ();
  if (labs (l1) != 1L)
    abort ();
  if (labs (1L) != 1L)
    link_error ();
  if (labs (lm1) != 1L)
    abort ();
  if (labs (-1L) != 1L)
    link_error ();
  if (labs (lmin) != 0x7fffffffffffffffL)
    abort ();
  if (labs (-0x7fffffffffffffffL) != 0x7fffffffffffffffL)
    link_error ();
  if (labs (lmax) != 0x7fffffffffffffffL)
    abort ();
  if (labs (0x7fffffffffffffffL) != 0x7fffffffffffffffL)
    link_error ();
  if (llabs (ll0) != 0LL)
    abort ();
  if (llabs (0LL) != 0LL)
    link_error ();
  if (llabs (ll1) != 1LL)
    abort ();
  if (llabs (1LL) != 1LL)
    link_error ();
  if (llabs (llm1) != 1LL)
    abort ();
  if (llabs (-1LL) != 1LL)
    link_error ();
  if (llabs (llmin) != 0x7fffffffffffffffLL)
    abort ();
  if (llabs (-0x7fffffffffffffffLL) != 0x7fffffffffffffffLL)
    link_error ();
  if (llabs (llmax) != 0x7fffffffffffffffLL)
    abort ();
  if (llabs (0x7fffffffffffffffLL) != 0x7fffffffffffffffLL)
    link_error ();
  if (imaxabs (imax0) != 0)
    abort ();
  if (imaxabs (0) != 0)
    link_error ();
  if (imaxabs (imax1) != 1)
    abort ();
  if (imaxabs (1) != 1)
    link_error ();
  if (imaxabs (imaxm1) != 1)
    abort ();
  if (imaxabs (-1) != 1)
    link_error ();
  if (imaxabs (imaxmin) != 0x7fffffffffffffffL)
    abort ();
  if (imaxabs (-0x7fffffffffffffffL) != 0x7fffffffffffffffL)
    link_error ();
  if (imaxabs (imaxmax) != 0x7fffffffffffffffL)
    abort ();
  if (imaxabs (0x7fffffffffffffffL) != 0x7fffffffffffffffL)
    link_error ();
}
