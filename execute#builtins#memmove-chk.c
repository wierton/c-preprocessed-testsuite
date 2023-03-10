
/* Copyright (C) 2004, 2005  Free Software Foundation.

   Ensure builtin __memcpy_chk performs correctly.  */

extern void abort (void);
typedef long unsigned int size_t;
extern size_t strlen(const char *);
extern void *memcpy (void *, const void *, size_t);
extern void *memmove (void *, const void *, size_t);
extern int memcmp (const void *, const void *, size_t);

#include "chk.h"

const char s1[] = "123";
char p[32] = "";
volatile char *s2 = "defg"; /* prevent constant propagation to happen when whole program assumptions are made.  */
volatile char *s3 = "FGH"; /* prevent constant propagation to happen when whole program assumptions are made.  */
volatile size_t l1 = 1; /* prevent constant propagation to happen when whole program assumptions are made.  */

void
__attribute__((noinline))
test1 (void)
{
  int i;


  /* The functions below might not be optimized into direct stores on all
     arches.  It depends on how many instructions would be generated and
     what limits the architecture chooses in STORE_BY_PIECES_P.  */
  memmove_disallowed = 1;
  memcpy_disallowed = 1;


  /* All the memmove calls in this routine except last have fixed length, so
     object size checking should be done at compile time if optimizing.  */
  chk_calls = 0;

  if (__builtin___memmove_chk (p, "ABCDE", 6, __builtin_object_size (p, 0)) != p || memcmp (p, "ABCDE", 6))
    abort ();
  if (__builtin___memmove_chk (p + 16, "VWX" + 1, 2, __builtin_object_size (p + 16, 0)) != p + 16
      || memcmp (p + 16, "WX\0\0", 5))
    abort ();
  if (__builtin___memmove_chk (p + 1, "", 1, __builtin_object_size (p + 1, 0)) != p + 1 || memcmp (p, "A\0CDE", 6))
    abort ();
  if (__builtin___memmove_chk (p + 3, "FGHI", 4, __builtin_object_size (p + 3, 0)) != p + 3 || memcmp (p, "A\0CFGHI", 8))
    abort ();

  i = 8;
  __builtin___memmove_chk (p + 20, "qrstu", 6, __builtin_object_size (p + 20, 0));
  __builtin___memmove_chk (p + 25, "QRSTU", 6, __builtin_object_size (p + 25, 0));
  if (__builtin___memmove_chk (p + 25 + 1, s1, 3, __builtin_object_size (p + 25 + 1, 0)) != p + 25 + 1
      || memcmp (p + 25, "Q123U", 6))
    abort ();

  if (__builtin___memmove_chk (__builtin___memmove_chk (p, "abcdEFG", 4, __builtin_object_size (p, 0)) + 4, "efg", 4, __builtin_object_size (__builtin___memmove_chk (p, "abcdEFG", 4, __builtin_object_size (p, 0)) + 4, 0)) != p + 4
      || memcmp (p, "abcdefg", 8))
    abort();

  /* Test at least one instance of the __builtin_ style.  We do this
     to ensure that it works and that the prototype is correct.  */
  if (__builtin___memmove_chk (p, "ABCDE", 6, __builtin_object_size (p, 0)) != p || memcmp (p, "ABCDE", 6))
    abort ();

  __builtin___memmove_chk (p + 5, s3, 1, __builtin_object_size (p + 5, 0));
  if (memcmp (p, "ABCDEFg", 8))
    abort ();

  memmove_disallowed = 0;
  memcpy_disallowed = 0;
  if (chk_calls)
    abort ();
  chk_calls = 0;

  __builtin___memmove_chk (p + 6, s1 + 1, l1, __builtin_object_size (p + 6, 0));
  if (memcmp (p, "ABCDEF2", 8))
    abort ();

  /* The above memmove copies into an object with known size, but
     unknown length, so it should be a __memmove_chk call.  */
  if (chk_calls != 1)
    abort ();
}

long buf1[64];
char *buf2 = (char *) (buf1 + 32);
long buf5[20];
char buf7[20];

void
__attribute__((noinline))
test2_sub (long *buf3, char *buf4, char *buf6, int n)
{
  int i = 0;

  /* All the memmove/__builtin_memmove/__builtin___memmove_chk
     calls in this routine are either fixed length, or have
     side-effects in __builtin_object_size arguments, or
     dst doesn't point into a known object.  */
  chk_calls = 0;

  /* These should probably be handled by store_by_pieces on most arches.  */
  if (__builtin___memmove_chk (buf1, "ABCDEFGHI", 9, __builtin_object_size (buf1, 0)) != (char *) buf1
      || memcmp (buf1, "ABCDEFGHI\0", 11))
    abort ();

  if (__builtin___memmove_chk (buf1, "abcdefghijklmnopq", 17, __builtin_object_size (buf1, 0)) != (char *) buf1
      || memcmp (buf1, "abcdefghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf3, "ABCDEF", 6, __builtin_object_size (buf3, 0)) != (char *) buf1
      || memcmp (buf1, "ABCDEFghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf3, "a", 1, __builtin_object_size (buf3, 0)) != (char *) buf1
      || memcmp (buf1, "aBCDEFghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk ((char *) buf3 + 2, "bcd" + ++i, 2, __builtin_object_size ((char *) buf3 + 2, 0)) != (char *) buf1 + 2
      || memcmp (buf1, "aBcdEFghijklmnopq\0", 19)
      || i != 1)
    abort ();

  /* These should probably be handled by move_by_pieces on most arches.  */
  if (__builtin___memmove_chk ((char *) buf3 + 4, buf5, 6, __builtin_object_size ((char *) buf3 + 4, 0)) != (char *) buf1 + 4
      || memcmp (buf1, "aBcdRSTUVWklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk ((char *) buf1 + ++i + 8, (char *) buf5 + 1, 1, __builtin_object_size ((char *) buf1 + ++i + 8, 0))
      != (char *) buf1 + 10
      || memcmp (buf1, "aBcdRSTUVWSlmnopq\0", 19)
      || i != 2)
    abort ();

  if (__builtin___memmove_chk ((char *) buf3 + 14, buf6, 2, __builtin_object_size ((char *) buf3 + 14, 0)) != (char *) buf1 + 14
      || memcmp (buf1, "aBcdRSTUVWSlmnrsq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf3, buf5, 8, __builtin_object_size (buf3, 0)) != (char *) buf1
      || memcmp (buf1, "RSTUVWXYVWSlmnrsq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf3, buf5, 17, __builtin_object_size (buf3, 0)) != (char *) buf1
      || memcmp (buf1, "RSTUVWXYZ01234567\0", 19))
    abort ();

  __builtin___memmove_chk (buf3, "aBcdEFghijklmnopq\0", 19, __builtin_object_size (buf3, 0));

  /* These should be handled either by movmemendM or memmove
     call.  */

  /* buf3 points to an unknown object, so __memmove_chk should not be done.  */
  if (__builtin___memmove_chk ((char *) buf3 + 4, buf5, n + 6, __builtin_object_size ((char *) buf3 + 4, 0)) != (char *) buf1 + 4
      || memcmp (buf1, "aBcdRSTUVWklmnopq\0", 19))
    abort ();

  /* This call has side-effects in dst, therefore no checking.  */
  if (__builtin___memmove_chk ((char *) buf1 + ++i + 8, (char *) buf5 + 1,
          n + 1, __builtin_object_size ((char *) buf1 + ++i + 8, 0))
      != (char *) buf1 + 11
      || memcmp (buf1, "aBcdRSTUVWkSmnopq\0", 19)
      || i != 3)
    abort ();

  if (__builtin___memmove_chk ((char *) buf3 + 14, buf6, n + 2, __builtin_object_size ((char *) buf3 + 14, 0)) != (char *) buf1 + 14
      || memcmp (buf1, "aBcdRSTUVWkSmnrsq\0", 19))
    abort ();

  i = 1;

  /* These might be handled by store_by_pieces.  */
  if (__builtin___memmove_chk (buf2, "ABCDEFGHI", 9, __builtin_object_size (buf2, 0)) != buf2
      || memcmp (buf2, "ABCDEFGHI\0", 11))
    abort ();

  if (__builtin___memmove_chk (buf2, "abcdefghijklmnopq", 17, __builtin_object_size (buf2, 0)) != buf2
      || memcmp (buf2, "abcdefghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf4, "ABCDEF", 6, __builtin_object_size (buf4, 0)) != buf2
      || memcmp (buf2, "ABCDEFghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf4, "a", 1, __builtin_object_size (buf4, 0)) != buf2
      || memcmp (buf2, "aBCDEFghijklmnopq\0", 19))
    abort ();

  if (__builtin___memmove_chk (buf4 + 2, "bcd" + i++, 2, __builtin_object_size (buf4 + 2, 0)) != buf2 + 2
      || memcmp (buf2, "aBcdEFghijklmnopq\0", 19)
      || i != 2)
    abort ();

  /* These might be handled by move_by_pieces.  */
  if (__builtin___memmove_chk (buf4 + 4, buf7, 6, __builtin_object_size (buf4 + 4, 0)) != buf2 + 4
      || memcmp (buf2, "aBcdRSTUVWklmnopq\0", 19))
    abort ();

  /* Side effect.  */
  if (__builtin___memmove_chk (buf2 + i++ + 8, buf7 + 1, 1,
          __builtin_object_size (buf2 + i++ + 8, 0))
      != buf2 + 10
      || memcmp (buf2, "aBcdRSTUVWSlmnopq\0", 19)
      || i != 3)
    abort ();

  if (__builtin___memmove_chk (buf4 + 14, buf6, 2, __builtin_object_size (buf4 + 14, 0)) != buf2 + 14
      || memcmp (buf2, "aBcdRSTUVWSlmnrsq\0", 19))
    abort ();

  __builtin___memmove_chk (buf4, "aBcdEFghijklmnopq\0", 19, __builtin_object_size (buf4, 0));

  /* These should be handled either by movmemendM or memmove
     call.  */
  if (__builtin___memmove_chk (buf4 + 4, buf7, n + 6, __builtin_object_size (buf4 + 4, 0)) != buf2 + 4
      || memcmp (buf2, "aBcdRSTUVWklmnopq\0", 19))
    abort ();

  /* Side effect.  */
  if (__builtin___memmove_chk (buf2 + i++ + 8, buf7 + 1, n + 1,
          __builtin_object_size (buf2 + i++ + 8, 0))
      != buf2 + 11
      || memcmp (buf2, "aBcdRSTUVWkSmnopq\0", 19)
      || i != 4)
    abort ();

  if (__builtin___memmove_chk (buf4 + 14, buf6, n + 2, __builtin_object_size (buf4 + 14, 0)) != buf2 + 14
      || memcmp (buf2, "aBcdRSTUVWkSmnrsq\0", 19))
    abort ();

  if (chk_calls)
    abort ();
}

void
__attribute__((noinline))
test2 (void)
{
  long *x;
  char *y;
  int z;
  __builtin___memmove_chk (buf5, "RSTUVWXYZ0123456789", 20, __builtin_object_size (buf5, 0));
  __builtin___memmove_chk (buf7, "RSTUVWXYZ0123456789", 20, __builtin_object_size (buf7, 0));
 __asm ("" : "=r" (x) : "0" (buf1));
 __asm ("" : "=r" (y) : "0" (buf2));
 __asm ("" : "=r" (z) : "0" (0));
  test2_sub (x, y, "rstuvwxyz", z);
}

static const struct foo
{
  char *s;
  double d;
  long l;
} foo[] =
{
  { "hello world1", 3.14159, 101L },
  { "hello world2", 3.14159, 102L },
  { "hello world3", 3.14159, 103L },
  { "hello world4", 3.14159, 104L },
  { "hello world5", 3.14159, 105L },
  { "hello world6", 3.14159, 106L }
};

static const struct bar
{
  char *s;
  const struct foo f[3];
} bar[] =
{
  {
    "hello world10",
    {
      { "hello1", 3.14159, 201L },
      { "hello2", 3.14159, 202L },
      { "hello3", 3.14159, 203L },
    }
  },
  {
    "hello world11",
    {
      { "hello4", 3.14159, 204L },
      { "hello5", 3.14159, 205L },
      { "hello6", 3.14159, 206L },
    }
  }
};

static const int baz[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

void
__attribute__((noinline))
test3 (void)
{
  const char *s;
  struct foo f1[sizeof foo/sizeof*foo];
  struct bar b1[sizeof bar/sizeof*bar];
  int bz[sizeof baz/sizeof*baz];

  /* All the memmove/__builtin_memmove calls in this routine have fixed
     length.  */
  chk_calls = 0;

  /* All the *memmove calls below have src in read-only memory, so all
     of them should be optimized into memcpy.  */
  memmove_disallowed = 1;
  if (__builtin___memmove_chk (f1, foo, sizeof (foo), __builtin_object_size (f1, 0)) != f1 || memcmp (f1, foo, sizeof (foo)))
    abort ();
  if (__builtin___memmove_chk (b1, bar, sizeof (bar), __builtin_object_size (b1, 0)) != b1 || memcmp (b1, bar, sizeof (bar)))
    abort ();
  __builtin___memmove_chk (bz, baz, sizeof (baz), __builtin_object_size (bz, 0));
  if (memcmp (bz, baz, sizeof (baz)))
    abort ();

  if (__builtin___memmove_chk (p, "abcde", 6, __builtin_object_size (p, 0)) != p || memcmp (p, "abcde", 6))
    abort ();
  s = s1;
  if (__builtin___memmove_chk (p + 2, ++s, 0, __builtin_object_size (p + 2, 0)) != p + 2 || memcmp (p, "abcde", 6) || s != s1 + 1)
    abort ();
  if (__builtin___memmove_chk (p + 3, "", 1, __builtin_object_size (p + 3, 0)) != p + 3 || memcmp (p, "abc\0e", 6))
    abort ();
  __builtin___memmove_chk (p + 2, "fghijk", 4, __builtin_object_size (p + 2, 0));
  if (memcmp (p, "abfghi", 7))
    abort ();
  s = s1 + 1;
  __builtin___memmove_chk (p + 1, s++, 0, __builtin_object_size (p + 1, 0));
  if (memcmp (p, "abfghi", 7) || s != s1 + 2)
    abort ();
  __builtin___memmove_chk (p + 4, "ABCDE", 1, __builtin_object_size (p + 4, 0));
  if (memcmp (p, "abfgAi", 7))
    abort ();

  /* memmove with length 1 can be optimized into memcpy if it can be
     expanded inline.  */
  if (__builtin___memmove_chk (p + 2, p + 3, 1, __builtin_object_size (p + 2, 0)) != p + 2)
    abort ();
  if (memcmp (p, "abggAi", 7))
    abort ();

  if (chk_calls)
    abort ();
  memmove_disallowed = 0;
}

/* Test whether compile time checking is done where it should
   and so is runtime object size checking.  */
void
__attribute__((noinline))
test4 (void)
{
  struct A { char buf1[10]; char buf2[10]; } a;
  char *r = l1 == 1 ? &a.buf1[5] : &a.buf2[4];
  char buf3[20];
  int i;
  size_t l;

  /* The following calls should do runtime checking
     - length is not known, but destination is.  */
  chk_calls = 0;
  __builtin___memmove_chk (a.buf1 + 2, s3, l1, __builtin_object_size (a.buf1 + 2, 0));
  __builtin___memmove_chk (r, s3, l1 + 1, __builtin_object_size (r, 0));
  r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
  __builtin___memmove_chk (r, s2, l1 + 2, __builtin_object_size (r, 0));
  __builtin___memmove_chk (r + 2, s3, l1, __builtin_object_size (r + 2, 0));
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
  __builtin___memmove_chk (r, s2, l1, __builtin_object_size (r, 0));
  if (chk_calls != 5)
    abort ();

  /* Following have known destination and known length,
     so if optimizing certainly shouldn't result in the checking
     variants.  */
  chk_calls = 0;
  __builtin___memmove_chk (a.buf1 + 2, s3, 1, __builtin_object_size (a.buf1 + 2, 0));
  __builtin___memmove_chk (r, s3, 2, __builtin_object_size (r, 0));
  r = l1 == 1 ? __builtin_alloca (4) : &a.buf2[7];
  __builtin___memmove_chk (r, s2, 3, __builtin_object_size (r, 0));
  r = buf3;
  l = 4;
  for (i = 0; i < 4; ++i)
    {
      if (i == l1 - 1)
 r = &a.buf1[1], l = 2;
      else if (i == l1)
 r = &a.buf2[7], l = 3;
      else if (i == l1 + 1)
 r = &buf3[5], l = 4;
      else if (i == l1 + 2)
 r = &a.buf1[9], l = 1;
    }
  __builtin___memmove_chk (r, s2, 1, __builtin_object_size (r, 0));
  /* Here, l is known to be at most 4 and __builtin_object_size (&buf3[16], 0)
     is 4, so this doesn't need runtime checking.  */
  __builtin___memmove_chk (&buf3[16], s2, l, __builtin_object_size (&buf3[16], 0));
  if (chk_calls)
    abort ();
  chk_calls = 0;
}

/* Test whether runtime and/or compile time checking catches
   buffer overflows.  */
void
__attribute__((noinline))
test5 (void)
{
  struct A { char buf1[10]; char buf2[10]; } a;
  char buf3[20];

  chk_fail_allowed = 1;
  /* Runtime checks.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___memmove_chk (&a.buf2[9], s2, l1 + 1, __builtin_object_size (&a.buf2[9], 0));
      abort ();
    }
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___memmove_chk (&a.buf2[7], s3, strlen (s3) + 1, __builtin_object_size (&a.buf2[7], 0));
      abort ();
    }
  /* This should be detectable at compile time already.  */
  if (__builtin_setjmp (chk_fail_buf) == 0)
    {
      __builtin___memmove_chk (&buf3[19], "ab", 2, __builtin_object_size (&buf3[19], 0));
      abort ();
    }
  chk_fail_allowed = 0;
}
/* Use a sequence length that is not divisible by two, to make it more
   likely to detect when words are mixed up.  */


static union {
  char buf[((sizeof (long long)) + (10 * sizeof (long long)) + (sizeof (long long)))];
  long long align_int;
  long double align_fp;
} u1, u2;

void
__attribute__((noinline))
test6 (void)
{
  int off1, off2, len, i;
  char *p, *q, c;

  for (off1 = 0; off1 < (sizeof (long long)); off1++)
    for (off2 = 0; off2 < (sizeof (long long)); off2++)
      for (len = 1; len < (10 * sizeof (long long)); len++)
 {
   for (i = 0, c = 'A'; i < ((sizeof (long long)) + (10 * sizeof (long long)) + (sizeof (long long))); i++, c++)
     {
       u1.buf[i] = 'a';
       if (c >= 'A' + 31)
  c = 'A';
       u2.buf[i] = c;
     }

   p = __builtin___memmove_chk (u1.buf + off1, u2.buf + off2, len, __builtin_object_size (u1.buf + off1, 0));
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

   for (i = 0; i < (sizeof (long long)); i++, q++)
     if (*q != 'a')
       abort ();
 }
}



char srcb[80] __attribute__ ((aligned));
char dstb[80] __attribute__ ((aligned));

void
__attribute__((noinline))
check (char *test, char *match, int n)
{
  if (memcmp (test, match, n))
    abort ();
}
void
__attribute__((noinline))
test7 (void)
{
  int i;

  chk_calls = 0;

  for (i = 0; i < sizeof (srcb); ++i)
      srcb[i] = 'a' + i % 26;

  { __builtin___memset_chk (dstb, 0, 0, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 0, __builtin_object_size (dstb, 0)); check (dstb, srcb, 0); } { __builtin___memset_chk (dstb, 0, (0) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (0) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (0) + 1); } { __builtin___memset_chk (dstb, 0, (0) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (0) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (0) + 2); } { __builtin___memset_chk (dstb, 0, (0) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (0) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (0) + 3); };
  { __builtin___memset_chk (dstb, 0, 4, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 4, __builtin_object_size (dstb, 0)); check (dstb, srcb, 4); } { __builtin___memset_chk (dstb, 0, (4) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (4) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (4) + 1); } { __builtin___memset_chk (dstb, 0, (4) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (4) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (4) + 2); } { __builtin___memset_chk (dstb, 0, (4) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (4) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (4) + 3); };
  { __builtin___memset_chk (dstb, 0, 8, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 8, __builtin_object_size (dstb, 0)); check (dstb, srcb, 8); } { __builtin___memset_chk (dstb, 0, (8) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (8) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (8) + 1); } { __builtin___memset_chk (dstb, 0, (8) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (8) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (8) + 2); } { __builtin___memset_chk (dstb, 0, (8) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (8) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (8) + 3); };
  { __builtin___memset_chk (dstb, 0, 12, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 12, __builtin_object_size (dstb, 0)); check (dstb, srcb, 12); } { __builtin___memset_chk (dstb, 0, (12) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (12) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (12) + 1); } { __builtin___memset_chk (dstb, 0, (12) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (12) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (12) + 2); } { __builtin___memset_chk (dstb, 0, (12) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (12) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (12) + 3); };
  { __builtin___memset_chk (dstb, 0, 16, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 16, __builtin_object_size (dstb, 0)); check (dstb, srcb, 16); } { __builtin___memset_chk (dstb, 0, (16) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (16) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (16) + 1); } { __builtin___memset_chk (dstb, 0, (16) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (16) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (16) + 2); } { __builtin___memset_chk (dstb, 0, (16) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (16) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (16) + 3); };
  { __builtin___memset_chk (dstb, 0, 20, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 20, __builtin_object_size (dstb, 0)); check (dstb, srcb, 20); } { __builtin___memset_chk (dstb, 0, (20) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (20) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (20) + 1); } { __builtin___memset_chk (dstb, 0, (20) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (20) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (20) + 2); } { __builtin___memset_chk (dstb, 0, (20) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (20) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (20) + 3); };
  { __builtin___memset_chk (dstb, 0, 24, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 24, __builtin_object_size (dstb, 0)); check (dstb, srcb, 24); } { __builtin___memset_chk (dstb, 0, (24) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (24) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (24) + 1); } { __builtin___memset_chk (dstb, 0, (24) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (24) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (24) + 2); } { __builtin___memset_chk (dstb, 0, (24) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (24) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (24) + 3); };
  { __builtin___memset_chk (dstb, 0, 28, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 28, __builtin_object_size (dstb, 0)); check (dstb, srcb, 28); } { __builtin___memset_chk (dstb, 0, (28) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (28) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (28) + 1); } { __builtin___memset_chk (dstb, 0, (28) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (28) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (28) + 2); } { __builtin___memset_chk (dstb, 0, (28) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (28) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (28) + 3); };
  { __builtin___memset_chk (dstb, 0, 32, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 32, __builtin_object_size (dstb, 0)); check (dstb, srcb, 32); } { __builtin___memset_chk (dstb, 0, (32) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (32) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (32) + 1); } { __builtin___memset_chk (dstb, 0, (32) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (32) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (32) + 2); } { __builtin___memset_chk (dstb, 0, (32) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (32) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (32) + 3); };
  { __builtin___memset_chk (dstb, 0, 36, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 36, __builtin_object_size (dstb, 0)); check (dstb, srcb, 36); } { __builtin___memset_chk (dstb, 0, (36) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (36) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (36) + 1); } { __builtin___memset_chk (dstb, 0, (36) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (36) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (36) + 2); } { __builtin___memset_chk (dstb, 0, (36) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (36) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (36) + 3); };
  { __builtin___memset_chk (dstb, 0, 40, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 40, __builtin_object_size (dstb, 0)); check (dstb, srcb, 40); } { __builtin___memset_chk (dstb, 0, (40) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (40) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (40) + 1); } { __builtin___memset_chk (dstb, 0, (40) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (40) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (40) + 2); } { __builtin___memset_chk (dstb, 0, (40) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (40) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (40) + 3); };
  { __builtin___memset_chk (dstb, 0, 44, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 44, __builtin_object_size (dstb, 0)); check (dstb, srcb, 44); } { __builtin___memset_chk (dstb, 0, (44) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (44) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (44) + 1); } { __builtin___memset_chk (dstb, 0, (44) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (44) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (44) + 2); } { __builtin___memset_chk (dstb, 0, (44) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (44) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (44) + 3); };
  { __builtin___memset_chk (dstb, 0, 48, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 48, __builtin_object_size (dstb, 0)); check (dstb, srcb, 48); } { __builtin___memset_chk (dstb, 0, (48) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (48) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (48) + 1); } { __builtin___memset_chk (dstb, 0, (48) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (48) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (48) + 2); } { __builtin___memset_chk (dstb, 0, (48) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (48) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (48) + 3); };
  { __builtin___memset_chk (dstb, 0, 52, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 52, __builtin_object_size (dstb, 0)); check (dstb, srcb, 52); } { __builtin___memset_chk (dstb, 0, (52) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (52) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (52) + 1); } { __builtin___memset_chk (dstb, 0, (52) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (52) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (52) + 2); } { __builtin___memset_chk (dstb, 0, (52) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (52) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (52) + 3); };
  { __builtin___memset_chk (dstb, 0, 56, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 56, __builtin_object_size (dstb, 0)); check (dstb, srcb, 56); } { __builtin___memset_chk (dstb, 0, (56) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (56) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (56) + 1); } { __builtin___memset_chk (dstb, 0, (56) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (56) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (56) + 2); } { __builtin___memset_chk (dstb, 0, (56) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (56) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (56) + 3); };
  { __builtin___memset_chk (dstb, 0, 60, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 60, __builtin_object_size (dstb, 0)); check (dstb, srcb, 60); } { __builtin___memset_chk (dstb, 0, (60) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (60) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (60) + 1); } { __builtin___memset_chk (dstb, 0, (60) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (60) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (60) + 2); } { __builtin___memset_chk (dstb, 0, (60) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (60) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (60) + 3); };
  { __builtin___memset_chk (dstb, 0, 64, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 64, __builtin_object_size (dstb, 0)); check (dstb, srcb, 64); } { __builtin___memset_chk (dstb, 0, (64) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (64) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (64) + 1); } { __builtin___memset_chk (dstb, 0, (64) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (64) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (64) + 2); } { __builtin___memset_chk (dstb, 0, (64) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (64) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (64) + 3); };
  { __builtin___memset_chk (dstb, 0, 68, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 68, __builtin_object_size (dstb, 0)); check (dstb, srcb, 68); } { __builtin___memset_chk (dstb, 0, (68) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (68) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (68) + 1); } { __builtin___memset_chk (dstb, 0, (68) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (68) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (68) + 2); } { __builtin___memset_chk (dstb, 0, (68) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (68) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (68) + 3); };
  { __builtin___memset_chk (dstb, 0, 72, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 72, __builtin_object_size (dstb, 0)); check (dstb, srcb, 72); } { __builtin___memset_chk (dstb, 0, (72) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (72) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (72) + 1); } { __builtin___memset_chk (dstb, 0, (72) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (72) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (72) + 2); } { __builtin___memset_chk (dstb, 0, (72) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (72) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (72) + 3); };
  { __builtin___memset_chk (dstb, 0, 76, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, 76, __builtin_object_size (dstb, 0)); check (dstb, srcb, 76); } { __builtin___memset_chk (dstb, 0, (76) + 1, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (76) + 1, __builtin_object_size (dstb, 0)); check (dstb, srcb, (76) + 1); } { __builtin___memset_chk (dstb, 0, (76) + 2, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (76) + 2, __builtin_object_size (dstb, 0)); check (dstb, srcb, (76) + 2); } { __builtin___memset_chk (dstb, 0, (76) + 3, __builtin_object_size (dstb, 0)); __builtin___memmove_chk (dstb, srcb, (76) + 3, __builtin_object_size (dstb, 0)); check (dstb, srcb, (76) + 3); };

  /* All memmove calls in this routine have constant arguments.  */
  if (chk_calls)
    abort ();
}

void
main_test (void)
{

  /* Object size checking is only intended for -O[s123].  */
  return;

  __asm ("" : "=r" (l1) : "0" (l1));
  test1 ();
  test2 ();
  __builtin___memset_chk (p, '\0', sizeof (p), __builtin_object_size (p, 0));
  test3 ();
  test4 ();
  test5 ();
  test6 ();
  test7 ();
}
