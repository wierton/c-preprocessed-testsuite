
/* Undefined behavior from a call to va_arg with a type other than
   that of the argument passed (in particular, with a type such as
   "float" that can never be the type of an argument passed through
   "...") does not appear until after the va_list expression is
   evaluated.  PR 38483.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */

#include <stdarg.h>


extern void exit (int);
extern void abort (void);

va_list ap;
float f;

va_list *
foo (void)
{
  exit (0);
  return &ap;
}

void
bar (int i, ...)
{
  
 __builtin_va_start(
 ap
 ,
 i
 )
                 ;
  f = 
     __builtin_va_arg(
     *foo ()
     ,
     float
     )
                            ;
  
 __builtin_va_end(
 ap
 )
            ;
}

int
main (void)
{
  bar (1, 0);
  abort ();
}
