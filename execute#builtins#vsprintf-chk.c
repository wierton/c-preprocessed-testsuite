
/* Copyright (C) 2004, 2005  Free Software Foundation.

   Ensure builtin __vsprintf_chk performs correctly.  */

#include <stdarg.h>


extern void abort (void);
typedef long unsigned int size_t;
extern size_t strlen(const char *);
extern void *memcpy (void *, const void *, size_t);
extern char *strcpy (char *, const char *);
extern int memcmp (const void *, const void *, size_t);
extern void *memset (void *, int, size_t);
extern int vsprintf (char *, const char *, va_list);

#include "chk.h"

const char s1[] = "123";
char p[32] = "";
char *s2 = "defg";
char *s3 = "FGH";
char *s4;
size_t l1 = 1;
static char buffer[32];
char * volatile ptr = "barf"; /* prevent constant propagation to happen when whole program assumptions are made.  */

int
__attribute__((noinline))
test1_sub (int i, ...)
{
  int ret = 0;
  va_list ap;
  
 __builtin_va_start(
 ap
 ,
 i
 )
                 ;
  switch (i)
    {
    case 0:
      __builtin___vsprintf_chk (buffer, 0, __builtin_object_size (buffer, 0), "foo", ap);
      break;
    case 1:
      ret = __builtin___vsprintf_chk (buffer, 0, __builtin_object_size (buffer, 0), "foo", ap);
      break;
    case 2:
      __builtin___vsprintf_chk (buffer, 0, __builtin_object_size (buffer, 0), "%s", ap);
      break;
    case 3:
      ret = __builtin___vsprintf_chk (buffer, 0, __builtin_object_size (buffer, 0), "%s", ap);
      break;
    case 4:
      __builtin___vsprintf_chk (buffer, 0, __builtin_object_size (buffer, 0), "%d - %c", ap);
      break;
    case 5:
      __builtin___vsprintf_chk (s4, 0, __builtin_object_size (s4, 0), "%d - %c", ap);
      break;
    }
  
 __builtin_va_end(
 ap
 )
            ;
  return ret;
}

void
__attribute__((noinline))
test1 (void)
{
  chk_calls = 0;
  vsprintf_disallowed = 1;

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  test1_sub (0);
  if (memcmp (buffer, "foo", 4) || buffer[4] != 'A')
    abort ();

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  if (test1_sub (1) != 3)
    abort ();
  if (memcmp (buffer, "foo", 4) || buffer[4] != 'A')
    abort ();

  if (chk_calls)
    abort ();
  vsprintf_disallowed = 0;

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  test1_sub (2, "bar");
  if (memcmp (buffer, "bar", 4) || buffer[4] != 'A')
    abort ();

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  if (test1_sub (3, "bar") != 3)
    abort ();
  if (memcmp (buffer, "bar", 4) || buffer[4] != 'A')
    abort ();

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  test1_sub (2, ptr);
  if (memcmp (buffer, "barf", 5) || buffer[5] != 'A')
    abort ();

  __builtin___memset_chk (buffer, 'A', 32, __builtin_object_size (buffer, 0));
  test1_sub (4, (int) l1 + 27, *ptr);
  if (memcmp (buffer, "28 - b\0AAAAA", 12))
    abort ();

  if (chk_calls != 4)
    abort ();
  chk_calls = 0;

  test1_sub (5, (int) l1 - 17, ptr[1]);
  if (memcmp (s4, "-16 - a", 8))
    abort ();
  if (chk_calls)
    abort ();
}

void
__attribute__((noinline))
test2_sub (int i, ...)
{
  va_list ap;
  struct A { char buf1[10]; char buf2[10]; } a;
  char *r = l1 == 1 ? &a.buf1[5] : &a.buf2[4];
  char buf3[20];
  int j;

  
 __builtin_va_start(
 ap
 ,
 i
 )
                 ;
  /* The following calls should do runtime checking
     - source length is not known, but destination is.  */
  switch (i)
    {
    case 0:
      __builtin___vsprintf_chk (a.buf1 + 2, 0, __builtin_object_size (a.buf1 + 2, 0), "%s", ap);
      break;
    case 1:
      __builtin___vsprintf_chk (r, 0, __builtin_object_size (r, 0), "%s%c", ap);
      break;
    case 2:
      r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
      __builtin___vsprintf_chk (r, 0, __builtin_object_size (r, 0), "%c %s", ap);
      break;
    case 3:
      r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
      __builtin___vsprintf_chk (r + 2, 0, __builtin_object_size (r + 2, 0), s3 + 3, ap);
      break;
    case 4:
    case 7:
      r = buf3;
      for (j = 0; j < 4; ++j)
 {
   if (j == l1 - 1)
     r = &a.buf1[1];
   else if (j == l1)
     r = &a.buf2[7];
   else if (j == l1 + 1)
     r = &buf3[5];
   else if (j == l1 + 2)
     r = &a.buf1[9];
 }
      if (i == 4)
 __builtin___vsprintf_chk (r, 0, __builtin_object_size (r, 0), s2 + 4, ap);
      else
 __builtin___vsprintf_chk (r, 0, __builtin_object_size (r, 0), "a", ap);
      break;
    case 5:
      r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
      __builtin___vsprintf_chk (r, 0, __builtin_object_size (r, 0), "%s", ap);
      break;
    case 6:
      __builtin___vsprintf_chk (a.buf1 + 2, 0, __builtin_object_size (a.buf1 + 2, 0), "", ap);
      break;
    case 8:
      __builtin___vsprintf_chk (s4, 0, __builtin_object_size (s4, 0), "%s %d", ap);
      break;
    }
  
 __builtin_va_end(
 ap
 )
            ;
}

/* Test whether compile time checking is done where it should
   and so is runtime object size checking.  */
void
__attribute__((noinline))
test2 (void)
{
  /* The following calls should do runtime checking
     - source length is not known, but destination is.  */
  chk_calls = 0;
  test2_sub (0, s3 + 3);
  test2_sub (1, s3 + 3, s3[3]);
  test2_sub (2, s2[2], s2 + 4);
  test2_sub (3);
  test2_sub (4);
  test2_sub (5, s1 + 1);
  if (chk_calls != 6)
    abort ();

  /* Following have known destination and known source length,
     so if optimizing certainly shouldn't result in the checking
     variants.  */
  chk_calls = 0;
  vsprintf_disallowed = 1;
  test2_sub (6);
  test2_sub (7);
  vsprintf_disallowed = 0;
  /* Unknown destination and source, no checking.  */
  test2_sub (8, s3, 0);
  if (chk_calls)
    abort ();
}

void
__attribute__((noinline))
test3_sub (int i, ...)
{
  va_list ap;
  struct A { char buf1[10]; char buf2[10]; } a;
  char buf3[20];

  
 __builtin_va_start(
 ap
 ,
 i
 )
                 ;
  /* The following calls should do runtime checking
     - source length is not known, but destination is.  */
  switch (i)
    {
    case 0:
      __builtin___vsprintf_chk (&a.buf2[9], 0, __builtin_object_size (&a.buf2[9], 0), "%c%s", ap);
      break;
    case 1:
      __builtin___vsprintf_chk (&a.buf2[7], 0, __builtin_object_size (&a.buf2[7], 0), "%s%c", ap);
      break;
    case 2:
      __builtin___vsprintf_chk (&a.buf2[7], 0, __builtin_object_size (&a.buf2[7], 0), "%d", ap);
      break;
    case 3:
      __builtin___vsprintf_chk (&buf3[17], 0, __builtin_object_size (&buf3[17], 0), "%s", ap);
      break;
    case 4:
      __builtin___vsprintf_chk (&buf3[19], 0, __builtin_object_size (&buf3[19], 0), "a", ap);
      break;
    }
  
 __builtin_va_end(
 ap
 )
            ;
}

/* Test whether runtime and/or compile time checking catches
   buffer overflows.  */
void
__attribute__((noinline))
test3 (void)
{
  chk_fail_allowed = 1;
  /* Runtime checks.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      test3_sub (0, s2[3], s2 + 4);
      abort ();
    }
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      test3_sub (1, s3 + strlen (s3) - 2, *s3);
      abort ();
    }
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      test3_sub (2, (int) l1 + 9999);
      abort ();
    }
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      test3_sub (3, "abc");
      abort ();
    }
  /* This should be detectable at compile time already.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      test3_sub (4);
      abort ();
    }
  chk_fail_allowed = 0;
}

void
main_test (void)
{

  /* Object size checking is only intended for -O[s123].  */
  return;

  __asm ("" : "=r" (s2) : "0" (s2));
  __asm ("" : "=r" (s3) : "0" (s3));
  __asm ("" : "=r" (l1) : "0" (l1));
  s4 = p;
  test1 ();
  test2 ();
  test3 ();
}
