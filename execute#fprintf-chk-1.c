
/* { dg-skip-if "requires io" { freestanding } }  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


volatile int should_optimize;

int
__attribute__((noinline))
__fprintf_chk (FILE *f, int flag, const char *fmt, ...)
{
  va_list ap;
  int ret;




  should_optimize = 1;
  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  ret = vfprintf (f, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  return ret;
}

int
main (void)
{
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "hello"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "hello") != 5) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "hello\n") != 6) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "a"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "a") != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, ""); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "") != 0) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "%s", "hello"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%s", "hello") != 5) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "%s", "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%s", "hello\n") != 6) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "%s", "a"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%s", "a") != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "%s", ""); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%s", "") != 0) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __fprintf_chk (
 stdout
 , 1, "%c", 'x'); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%c", 'x') != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 0; __fprintf_chk (
 stdout
 , 1, "%s\n", "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%s\n", "hello\n") != 7) abort (); if (!should_optimize) abort ();;
  should_optimize = 0; __fprintf_chk (
 stdout
 , 1, "%d\n", 0); if (!should_optimize) abort (); should_optimize = 0; if (__fprintf_chk (
 stdout
 , 1, "%d\n", 0) != 2) abort (); if (!should_optimize) abort ();;
  return 0;
}
