
/* Copyright (C) 2002  Free Software Foundation.

   Test that (A & C1) op C2 optimizations behave correctly where C1 is
   a constant power of 2, op is == or !=, and C2 is C1 or zero.

   Written by Roger Sayle, 5th May 2002.  */

#include <limits.h>


extern void abort (void);

void test1 (signed char c, int set);
void test2 (unsigned char c, int set);
void test3 (short s, int set);
void test4 (unsigned short s, int set);
void test5 (int i, int set);
void test6 (unsigned int i, int set);
void test7 (long long l, int set);
void test8 (unsigned long long l, int set);
void
test1 (signed char c, int set)
{
  if ((c & (0x7f +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((c & (0x7f +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (0x7f +1)) == (0x7f +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (0x7f +1)) != (0x7f +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test2 (unsigned char c, int set)
{
  if ((c & (0x7f +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((c & (0x7f +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (0x7f +1)) == (0x7f +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((c & (0x7f +1)) != (0x7f +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test3 (short s, int set)
{
  if ((s & (0x7fff +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((s & (0x7fff +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (0x7fff +1)) == (0x7fff +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (0x7fff +1)) != (0x7fff +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test4 (unsigned short s, int set)
{
  if ((s & (0x7fff +1)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((s & (0x7fff +1)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (0x7fff +1)) == (0x7fff +1))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((s & (0x7fff +1)) != (0x7fff +1))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test5 (int i, int set)
{
  if ((i & (0x7fffffff +1U)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((i & (0x7fffffff +1U)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (0x7fffffff +1U)) == (0x7fffffff +1U))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (0x7fffffff +1U)) != (0x7fffffff +1U))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test6 (unsigned int i, int set)
{
  if ((i & (0x7fffffff +1U)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((i & (0x7fffffff +1U)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (0x7fffffff +1U)) == (0x7fffffff +1U))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((i & (0x7fffffff +1U)) != (0x7fffffff +1U))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test7 (long long l, int set)
{
  if ((l & (0x7fffffffffffffffLL +1ULL)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) == (0x7fffffffffffffffLL +1ULL))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) != (0x7fffffffffffffffLL +1ULL))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

void
test8 (unsigned long long l, int set)
{
  if ((l & (0x7fffffffffffffffLL +1ULL)) == 0)
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) != 0)
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) == (0x7fffffffffffffffLL +1ULL))
    {
      if (!set) abort ();
    }
  else
    if (set) abort ();

  if ((l & (0x7fffffffffffffffLL +1ULL)) != (0x7fffffffffffffffLL +1ULL))
    {
      if (set) abort ();
    }
  else
    if (!set) abort ();
}

int
main ()
{
  test1 (0, 0);
  test1 (0x7f, 0);
  test1 (
        (-0x7f - 1)
                 , 1);
  test1 (
        (0x7f * 2 + 1)
                 , 1);

  test2 (0, 0);
  test2 (0x7f, 0);
  test2 (
        (-0x7f - 1)
                 , 1);
  test2 (
        (0x7f * 2 + 1)
                 , 1);

  test3 (0, 0);
  test3 (0x7fff, 0);
  test3 (
        (-0x7fff - 1)
                , 1);
  test3 (
        (0x7fff * 2 + 1)
                 , 1);

  test4 (0, 0);
  test4 (0x7fff, 0);
  test4 (
        (-0x7fff - 1)
                , 1);
  test4 (
        (0x7fff * 2 + 1)
                 , 1);

  test5 (0, 0);
  test5 (0x7fffffff, 0);
  test5 (
        (-0x7fffffff - 1)
               , 1);
  test5 (
        (0x7fffffff * 2U + 1U)
                , 1);

  test6 (0, 0);
  test6 (0x7fffffff, 0);
  test6 (
        (-0x7fffffff - 1)
               , 1);
  test6 (
        (0x7fffffff * 2U + 1U)
                , 1);

  test7 (0, 0);
  test7 (0x7fffffffffffffffLL, 0);
  test7 ((-0x7fffffffffffffffLL -1), 1);
  test7 ((0x7fffffffffffffffLL * 2ULL + 1), 1);

  test8 (0, 0);
  test8 (0x7fffffffffffffffLL, 0);
  test8 ((-0x7fffffffffffffffLL -1), 1);
  test8 ((0x7fffffffffffffffLL * 2ULL + 1), 1);

  return 0;
}
