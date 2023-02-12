#include <stdarg.h>

#include <sys/types.h>



/* If some target has a Max alignment less than 16, please create
   a #ifdef around the alignment and add your alignment.  */






extern void abort (void);

extern int inside_main;
void *chk_fail_buf[256] __attribute__((aligned (16)));
volatile int chk_fail_allowed, chk_calls;
volatile int memcpy_disallowed, mempcpy_disallowed, memmove_disallowed;
volatile int memset_disallowed, strcpy_disallowed, stpcpy_disallowed;
volatile int strncpy_disallowed, stpncpy_disallowed, strcat_disallowed;
volatile int strncat_disallowed, sprintf_disallowed, vsprintf_disallowed;
volatile int snprintf_disallowed, vsnprintf_disallowed;
extern long unsigned int strlen (const char *);
extern int vsprintf (char *, const char *, va_list);

void __attribute__((noreturn))
__chk_fail (void)
{
  if (chk_fail_allowed)
    __builtin_longjmp (chk_fail_buf, 1);
  abort ();
}

void *
memcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  while (n-- != 0)
    *dstp++ = *srcp++;

  return dst;
}

void *
__memcpy_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into memcpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memcpy (dst, src, n);
}

void *
mempcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  while (n-- != 0)
    *dstp++ = *srcp++;

  return dstp;
}

void *
__mempcpy_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into mempcpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return mempcpy (dst, src, n);
}

void *
memmove (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;






  srcp = src;
  dstp = dst;
  if (srcp < dstp)
    while (n-- != 0)
      dstp[n] = srcp[n];
  else
    while (n-- != 0)
      *dstp++ = *srcp++;

  return dst;
}

void *
__memmove_chk (void *dst, const void *src, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into memmove.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memmove (dst, src, n);
}

void *
memset (void *dst, int c, long unsigned int n)
{
  while (n-- != 0)
    n[(char *) dst] = c;

  /* Single-byte memsets should be done inline when optimisation
     is enabled.  Do this after the copy in case we're being called to
     initialize bss.  */





  return dst;
}

void *
__memset_chk (void *dst, int c, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into memset.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return memset (dst, c, n);
}

char *
strcpy (char *d, const char *s)
{
  char *r = d;




  while ((*d++ = *s++));
  return r;
}

char *
__strcpy_chk (char *d, const char *s, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into strcpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (s) >= size)
    __chk_fail ();
  return strcpy (d, s);
}

char *
stpcpy (char *dst, const char *src)
{





  while (*src != 0)
    *dst++ = *src++;

  *dst = 0;
  return dst;
}

char *
__stpcpy_chk (char *d, const char *s, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into stpcpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (s) >= size)
    __chk_fail ();
  return stpcpy (d, s);
}

char *
stpncpy (char *dst, const char *src, long unsigned int n)
{





  for (; *src && n; n--)
    *dst++ = *src++;

  char *ret = dst;

  while (n--)
    *dst++ = 0;

  return ret;
}


char *
__stpncpy_chk (char *s1, const char *s2, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into stpncpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return stpncpy (s1, s2, n);
}

char *
strncpy (char *s1, const char *s2, long unsigned int n)
{
  char *dest = s1;




  for (; *s2 && n; n--)
    *s1++ = *s2++;
  while (n--)
    *s1++ = 0;
  return dest;
}

char *
__strncpy_chk (char *s1, const char *s2, long unsigned int n, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into strncpy.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (n > size)
    __chk_fail ();
  return strncpy (s1, s2, n);
}

char *
strcat (char *dst, const char *src)
{
  char *p = dst;






  while (*p)
    p++;
  while ((*p++ = *src++))
    ;
  return dst;
}

char *
__strcat_chk (char *d, const char *s, long unsigned int size)
{
  /* If size is -1, GCC should always optimize the call into strcat.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  if (strlen (d) + strlen (s) >= size)
    __chk_fail ();
  return strcat (d, s);
}

char *
strncat (char *s1, const char *s2, long unsigned int n)
{
  char *dest = s1;
  char c;




  while (*s1) s1++;
  c = '\0';
  while (n > 0)
    {
      c = *s2++;
      *s1++ = c;
      if (c == '\0')
 return dest;
      n--;
    }
  if (c != '\0')
    *s1 = '\0';
  return dest;
}

char *
__strncat_chk (char *d, const char *s, long unsigned int n, long unsigned int size)
{
  long unsigned int len = strlen (d), n1 = n;
  const char *s1 = s;

  /* If size is -1, GCC should always optimize the call into strncat.  */
  if (size == (long unsigned int) -1)
    abort ();
  ++chk_calls;
  while (len < size && n1 > 0)
    {
      if (*s1++ == '\0')
 break;
      ++len;
      --n1;
    }

  if (len >= size)
    __chk_fail ();
  return strncat (d, s, n);
}

/* No chk test in GCC testsuite needs more bytes than this.
   As we can't expect vsnprintf to be available on the target,
   assume 4096 bytes is enough.  */
static char chk_sprintf_buf[4096];

int
__sprintf_chk (char *str, int flag, long unsigned int size, const char *fmt, ...)
{
  int ret;
  va_list ap;

  /* If size is -1 and flag 0, GCC should always optimize the call into
     sprintf.  */
  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;




  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  if (ret >= 0)
    {
      if (ret >= size)
 __chk_fail ();
      memcpy (str, chk_sprintf_buf, ret + 1);
    }
  return ret;
}

int
__vsprintf_chk (char *str, int flag, long unsigned int size, const char *fmt,
  va_list ap)
{
  int ret;

  /* If size is -1 and flag 0, GCC should always optimize the call into
     vsprintf.  */
  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;




  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret >= size)
 __chk_fail ();
      memcpy (str, chk_sprintf_buf, ret + 1);
    }
  return ret;
}

int
__snprintf_chk (char *str, long unsigned int len, int flag, long unsigned int size,
  const char *fmt, ...)
{
  int ret;
  va_list ap;

  /* If size is -1 and flag 0, GCC should always optimize the call into
     snprintf.  */
  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;
  if (size < len)
    __chk_fail ();




  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}

int
__vsnprintf_chk (char *str, long unsigned int len, int flag, long unsigned int size,
   const char *fmt, va_list ap)
{
  int ret;

  /* If size is -1 and flag 0, GCC should always optimize the call into
     vsnprintf.  */
  if (size == (long unsigned int) -1 && flag == 0)
    abort ();
  ++chk_calls;
  if (size < len)
    __chk_fail ();




  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}

int
snprintf (char *str, long unsigned int len, const char *fmt, ...)
{
  int ret;
  va_list ap;





  
 __builtin_va_start(
 ap
 ,
 fmt
 )
                   ;
  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  
 __builtin_va_end(
 ap
 )
            ;
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else if (len)
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}

/* uClibc's vsprintf calls vsnprintf.  */

int
vsnprintf (char *str, long unsigned int len, const char *fmt, va_list ap)
{
  int ret;





  ret = vsprintf (chk_sprintf_buf, fmt, ap);
  if (ret >= 0)
    {
      if (ret < len)
 memcpy (str, chk_sprintf_buf, ret + 1);
      else if (len)
 {
   memcpy (str, chk_sprintf_buf, len - 1);
   str[len - 1] = '\0';
 }
    }
  return ret;
}
