#include <stdarg.h>


main ()
{
  double f (int x, ...)
    {
      va_list args;
      double a;

      
     __builtin_va_start(
     args
     ,
     x
     )
                       ;
      a = 
         __builtin_va_arg(
         args
         ,
         double
         )
                              ;
      
     __builtin_va_end(
     args
     )
                  ;
      return a;
    }

  if (f (1, (double)1) != 1.0)
    abort ();
  exit (0);
}
