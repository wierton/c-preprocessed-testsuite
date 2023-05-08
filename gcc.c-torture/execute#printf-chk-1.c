
/* { dg-skip-if "requires io" { freestanding } }  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


volatile int should_optimize;

int
__attribute__((noinline))
__printf_chk (int flag, const char *fmt, ...)
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
  ret = vprintf (fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  return ret;
}

int
main (void)
{
  should_optimize = 0; __printf_chk (1, "hello"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "hello") != 5) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "hello\n") != 6) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "a"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "a") != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, ""); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "") != 0) abort (); if (!should_optimize) abort ();;
  should_optimize = 0; __printf_chk (1, "%s", "hello"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%s", "hello") != 5) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "%s", "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%s", "hello\n") != 6) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "%s", "a"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%s", "a") != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "%s", ""); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%s", "") != 0) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "%c", 'x'); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%c", 'x') != 1) abort (); if (!should_optimize) abort ();;
  should_optimize = 1; __printf_chk (1, "%s\n", "hello\n"); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%s\n", "hello\n") != 7) abort (); if (!should_optimize) abort ();;
  should_optimize = 0; __printf_chk (1, "%d\n", 0); if (!should_optimize) abort (); should_optimize = 0; if (__printf_chk (1, "%d\n", 0) != 2) abort (); if (!should_optimize) abort ();;
  return 0;
}
