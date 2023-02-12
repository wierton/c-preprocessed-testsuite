
/* Copyright (C) 2000  Free Software Foundation.

   If the argument to va_end() has side effects, test whether side
   effects from that argument are honored.

   Written by Kaveh R. Ghazi, 10/31/2000.  */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>






static void __attribute__ ((__format__ (__printf__, 1, 2)))
doit (const char *s, ...)
{
  va_list *ap_array[3], **ap_ptr = ap_array;

  ap_array[0] = malloc (sizeof(va_list));
  ap_array[1] = 
               ((void *)0)
                   ;
  ap_array[2] = malloc (sizeof(va_list));

  
 __builtin_va_start(
 *ap_array[0]
 ,
 s
 )
                           ;
  vprintf (s, **ap_ptr);
  /* Increment the va_list pointer once.  */
  
 __builtin_va_end(
 **ap_ptr++
 )
                    ;

  /* Increment the va_list pointer a second time.  */
  ap_ptr++;

  
 __builtin_va_start(
 *ap_array[2]
 ,
 s
 )
                           ;
  /* If we failed to increment ap_ptr twice, then the parameter passed
     in here will dereference NULL and should cause a crash.  */
  vprintf (s, **ap_ptr);
  
 __builtin_va_end(
 **ap_ptr
 )
                  ;

  /* Just in case, If *ap_ptr is NULL abort anyway.  */
  if (*ap_ptr == 0)
    abort();
}

int main()
{
  doit ("%s", "hello world\n");
  exit (0);
}
