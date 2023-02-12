
/* PR c/99324 */

#include <stdarg.h>


int
foo (int x, ...)
{
  va_list a;
  
 __builtin_va_start(
 a
 ,
 x
 )
                ;
  int b[6] = {};
  int bar (c)
    int c[1][
            __builtin_va_arg(
            a
            ,
            int
            )
                           ];
  {
    return sizeof c[0];
  }
  int r = bar (b);
  
 __builtin_va_end(
 a
 )
           ;
  return r;
}
