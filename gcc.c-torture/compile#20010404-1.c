
/* This testcase caused a floating point exception in the compiler when
   compiled with -O2. The crash occurs when trying to simplify division
   and modulo operations.  */

#include <limits.h>


extern void bar (int);

void foo ()
{
  int a = 
         (-0x7fffffff - 1)
                ;
  int b = -1;
  bar (a / b);
  bar (a % b);
}
