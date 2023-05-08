
/* { dg-skip-if "requires io" { freestanding } }  */


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


volatile int should_optimize;

int
__attribute__((noinline))
__vfprintf_chk (FILE *f, int flag, const char *fmt, va_list ap)
{




  should_optimize = 1;
  return vfprintf (f, fmt, ap);
}

void
inner (int x, ...)
{
  va_list ap, ap2;
  
 __builtin_va_start(
 ap
 ,
 x
 )
                 ;
  
 __builtin_va_start(
 ap2
 ,
 x
 )
                  ;

  switch (x)
    {
#include "vfprintf-chk-1.c"
/* { dg-skip-if "requires io" { freestanding } }  */
  case 0: should_optimize = 1; __vfprintf_chk (
 stdout
 , 1, "hello", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "hello", ap2) != 5) abort (); if (! should_optimize) abort (); break;;
  case 1: should_optimize = 1; __vfprintf_chk (
 stdout
 , 1, "hello\n", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "hello\n", ap2) != 6) abort (); if (! should_optimize) abort (); break;;
  case 2: should_optimize = 1; __vfprintf_chk (
 stdout
 , 1, "a", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "a", ap2) != 1) abort (); if (! should_optimize) abort (); break;;
  case 3: should_optimize = 1; __vfprintf_chk (
 stdout
 , 1, "", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "", ap2) != 0) abort (); if (! should_optimize) abort (); break;;
  case 4: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%s", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%s", ap2) != 5) abort (); if (! should_optimize) abort (); break;;
  case 5: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%s", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%s", ap2) != 6) abort (); if (! should_optimize) abort (); break;;
  case 6: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%s", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%s", ap2) != 1) abort (); if (! should_optimize) abort (); break;;
  case 7: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%s", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%s", ap2) != 0) abort (); if (! should_optimize) abort (); break;;
  case 8: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%c", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%c", ap2) != 1) abort (); if (! should_optimize) abort (); break;;
  case 9: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%s\n", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%s\n", ap2) != 7) abort (); if (! should_optimize) abort (); break;;
  case 10: should_optimize = 0; __vfprintf_chk (
 stdout
 , 1, "%d\n", ap); if (! should_optimize) abort (); should_optimize = 0; if (__vfprintf_chk (
 stdout
 , 1, "%d\n", ap2) != 2) abort (); if (! should_optimize) abort (); break;;

    default:
      abort ();
    }

  
 __builtin_va_end(
 ap
 )
            ;
  
 __builtin_va_end(
 ap2
 )
             ;
}

int
main (void)
{


#include "vfprintf-chk-1.c"
/* { dg-skip-if "requires io" { freestanding } }  */
  inner (0);;
  inner (1);;
  inner (2);;
  inner (3);;
  inner (4, "hello");;
  inner (5, "hello\n");;
  inner (6, "a");;
  inner (7, "");;
  inner (8, 'x');;
  inner (9, "hello\n");;
  inner (10, 0);;

  return 0;
}
