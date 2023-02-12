
/* { dg-additional-options "-Wl,-u,_printf_float" { target newlib_nano_io } } */

#include <stdio.h>
#include <stdarg.h>


char buf[50];
int
va (int a, double b, int c, ...)
{
  va_list ap;
  int d, e, f, g, h, i, j, k, l, m, n, o, p;
  
 __builtin_va_start(
 ap
 ,
 c
 )
                 ;

  d = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  e = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  f = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  g = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  h = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  i = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  j = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  k = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  l = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  m = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  n = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  o = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;
  p = 
     __builtin_va_arg(
     ap
     ,
     int
     )
                     ;

  sprintf (buf,
    "%d,%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
    a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);
  
 __builtin_va_end(
 ap
 )
            ;
}

main()
{
  va (1, 1.0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  if (strcmp ("1,1.000000,2,3,4,5,6,7,8,9,10,11,12,13,14,15", buf))
    abort();
  exit(0);
}
