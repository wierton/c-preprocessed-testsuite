
/* Copyright (C) 2004, 2005  Free Software Foundation.

   Ensure builtin __strcpy_chk performs correctly.  */

extern void abort (void);
typedef long unsigned int size_t;
extern size_t strlen(const char *);
extern void *memcpy (void *, const void *, size_t);
extern char *strcpy (char *, const char *);
extern int memcmp (const void *, const void *, size_t);

#include "chk.h"

 const char s1[] = "123";
char p[32] = "";
char *s2 = "defg";
char *s3 = "FGH";
char *s4;
size_t l1 = 1;

void
__attribute__((noinline))
test1 (void)
{
  chk_calls = 0;

  strcpy_disallowed = 1;




  if (__builtin___strcpy_chk (p, "abcde", __builtin_object_size (p, 0)) != p || memcmp (p, "abcde", 6))
    abort ();
  if (__builtin___strcpy_chk (p + 16, "vwxyz" + 1, __builtin_object_size (p + 16, 0)) != p + 16 || memcmp (p + 16, "wxyz", 5))
    abort ();
  if (__builtin___strcpy_chk (p + 1, "", __builtin_object_size (p + 1, 0)) != p + 1 || memcmp (p, "a\0cde", 6))
    abort ();
  if (__builtin___strcpy_chk (p + 3, "fghij", __builtin_object_size (p + 3, 0)) != p + 3 || memcmp (p, "a\0cfghij", 9))
    abort ();

  /* Test at least one instance of the __builtin_ style.  We do this
     to ensure that it works and that the prototype is correct.  */
  if (__builtin___strcpy_chk (p, "abcde", __builtin_object_size (p, 0)) != p || memcmp (p, "abcde", 6))
    abort ();

  strcpy_disallowed = 0;
  if (chk_calls)
    abort ();
}
/* Use a sequence length that is not divisible by two, to make it more
   likely to detect when words are mixed up.  */


static union {
  char buf[((sizeof (long long)) + (10 * sizeof (long long)) + 1 + (sizeof (long long)))];
  long long align_int;
  long double align_fp;
} u1, u2;

void
__attribute__((noinline))
test2 (void)
{
  int off1, off2, len, i;
  char *p, *q, c;

  for (off1 = 0; off1 < (sizeof (long long)); off1++)
    for (off2 = 0; off2 < (sizeof (long long)); off2++)
      for (len = 1; len < (10 * sizeof (long long)); len++)
 {
   for (i = 0, c = 'A'; i < ((sizeof (long long)) + (10 * sizeof (long long)) + 1 + (sizeof (long long))); i++, c++)
     {
       u1.buf[i] = 'a';
       if (c >= 'A' + 31)
  c = 'A';
       u2.buf[i] = c;
     }
   u2.buf[off2 + len] = '\0';

   p = __builtin___strcpy_chk (u1.buf + off1, u2.buf + off2, __builtin_object_size (u1.buf + off1, 0));
   if (p != u1.buf + off1)
     abort ();

   q = u1.buf;
   for (i = 0; i < off1; i++, q++)
     if (*q != 'a')
       abort ();

   for (i = 0, c = 'A' + off2; i < len; i++, q++, c++)
     {
       if (c >= 'A' + 31)
  c = 'A';
       if (*q != c)
  abort ();
     }

   if (*q++ != '\0')
     abort ();
   for (i = 0; i < (sizeof (long long)); i++, q++)
     if (*q != 'a')
       abort ();
 }
}

/* Test whether compile time checking is done where it should
   and so is runtime object size checking.  */
void
__attribute__((noinline))
test3 (void)
{
  struct A { char buf1[10]; char buf2[10]; } a;
  char *r = l1 == 1 ? &a.buf1[5] : &a.buf2[4];
  char buf3[20];
  int i;
  const char *l;

  /* The following calls should do runtime checking
     - source length is not known, but destination is.  */
  chk_calls = 0;
  __builtin___strcpy_chk (a.buf1 + 2, s3 + 3, __builtin_object_size (a.buf1 + 2, 0));
  __builtin___strcpy_chk (r, s3 + 2, __builtin_object_size (r, 0));
  r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
  __builtin___strcpy_chk (r, s2 + 2, __builtin_object_size (r, 0));
  __builtin___strcpy_chk (r + 2, s3 + 3, __builtin_object_size (r + 2, 0));
  r = buf3;
  for (i = 0; i < 4; ++i)
    {
      if (i == l1 - 1)
 r = &a.buf1[1];
      else if (i == l1)
 r = &a.buf2[7];
      else if (i == l1 + 1)
 r = &buf3[5];
      else if (i == l1 + 2)
 r = &a.buf1[9];
    }
  __builtin___strcpy_chk (r, s2 + 4, __builtin_object_size (r, 0));
  if (chk_calls != 5)
    abort ();

  /* Following have known destination and known source length,
     so if optimizing certainly shouldn't result in the checking
     variants.  */
  chk_calls = 0;
  __builtin___strcpy_chk (a.buf1 + 2, "", __builtin_object_size (a.buf1 + 2, 0));
  __builtin___strcpy_chk (r, "a", __builtin_object_size (r, 0));
  r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
  __builtin___strcpy_chk (r, s1 + 1, __builtin_object_size (r, 0));
  r = buf3;
  l = "abc";
  for (i = 0; i < 4; ++i)
    {
      if (i == l1 - 1)
 r = &a.buf1[1], l = "e";
      else if (i == l1)
 r = &a.buf2[7], l = "gh";
      else if (i == l1 + 1)
 r = &buf3[5], l = "jkl";
      else if (i == l1 + 2)
 r = &a.buf1[9], l = "";
    }
  __builtin___strcpy_chk (r, "", __builtin_object_size (r, 0));
  /* Here, strlen (l) + 1 is known to be at most 4 and
     __builtin_object_size (&buf3[16], 0) is 4, so this doesn't need
     runtime checking.  */
  __builtin___strcpy_chk (&buf3[16], l, __builtin_object_size (&buf3[16], 0));
  /* Unknown destination and source, no checking.  */
  __builtin___strcpy_chk (s4, s3, __builtin_object_size (s4, 0));
  if (chk_calls)
    abort ();
  chk_calls = 0;
}

/* Test whether runtime and/or compile time checking catches
   buffer overflows.  */
void
__attribute__((noinline))
test4 (void)
{
  struct A { char buf1[10]; char buf2[10]; } a;
  char buf3[20];

  chk_fail_allowed = 1;
  /* Runtime checks.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___strcpy_chk (&a.buf2[9], s2 + 3, __builtin_object_size (&a.buf2[9], 0));
      abort ();
    }
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___strcpy_chk (&a.buf2[7], s3 + strlen (s3) - 3, __builtin_object_size (&a.buf2[7], 0));
      abort ();
    }
  /* This should be detectable at compile time already.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___strcpy_chk (&buf3[19], "a", __builtin_object_size (&buf3[19], 0));
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
  test1 ();
  test2 ();
  s4 = p;
  test3 ();
  test4 ();
}
