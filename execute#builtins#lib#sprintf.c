#include <stdio.h>
#include <stdarg.h>

extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
int
(sprintf) (char *buf, const char *fmt, ...)
{
  va_list ap;
  int r;




  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  r = vsprintf (buf, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  return r;
}
