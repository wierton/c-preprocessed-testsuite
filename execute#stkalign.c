
/* { dg-options "-fno-inline" } */
/* Check that stack alignment is not affected by variables not placed
   on the stack.  */

#include <assert.h>




unsigned test(unsigned n, unsigned p)
{
  static struct { char __attribute__((__aligned__(64))) c; } s;
  unsigned x;

  
 ((void) sizeof ((
 __alignof__(s) == 64
 ) ? 1 : 0), __extension__ ({ if (
 __alignof__(s) == 64
 ) ; else __assert_fail (
 "__alignof__(s) == ALIGNMENT"
 , "execute/stkalign.c", 14, __extension__ __PRETTY_FUNCTION__); }))
                                    ;
  asm ("" : "=g" (x), "+m" (s) : "0" (&x));

  return n ? test(n - 1, x) : (x ^ p);
}

unsigned test2(unsigned n, unsigned p)
{
  static struct { char c; } s;
  unsigned x;

  
 ((void) sizeof ((
 __alignof__(s) != 64
 ) ? 1 : 0), __extension__ ({ if (
 __alignof__(s) != 64
 ) ; else __assert_fail (
 "__alignof__(s) != ALIGNMENT"
 , "execute/stkalign.c", 25, __extension__ __PRETTY_FUNCTION__); }))
                                    ;
  asm ("" : "=g" (x), "+m" (s) : "0" (&x));

  return n ? test2(n - 1, x) : (x ^ p);
}

int main (int argc, char *argv[] __attribute__((unused)))
{
  unsigned int x, y;

  x = test(argc, 0);
  x |= test(argc + 1, 0);
  x |= test(argc + 2, 0);

  y = test2(argc, 0);
  y |= test2(argc + 1, 0);
  y |= test2(argc + 2, 0);

  return (x & (64 - 1)) == 0 && (y & (64 - 1)) != 0 ? 1 : 0;
}
