
/* Copyright (C) 2002  Free Software Foundation.

   Test that optimizing ((c>=1) && (c<=127)) into (signed char)c < 0
   doesn't cause any problems for the compiler and behaves correctly.

   Written by Roger Sayle, 8th May 2002.  */

#include <limits.h>


extern void abort (void);

void
testc (unsigned char c, int ok)
{
  if ((c>=1) && (c<=0x7f))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
tests (unsigned short s, int ok)
{
  if ((s>=1) && (s<=0x7fff))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
testi (unsigned int i, int ok)
{
  if ((i>=1) && (i<=0x7fffffff))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

void
testl (unsigned long l, int ok)
{
  if ((l>=1) && (l<=0x7fffffffffffffffL))
    {
      if (!ok) abort ();
    }
  else
    if (ok) abort ();
}

int
main ()
{
  testc (0, 0);
  testc (1, 1);
  testc (0x7f, 1);
  testc (0x7f +1, 0);
  testc (
        (0x7f * 2 + 1)
                 , 0);

  tests (0, 0);
  tests (1, 1);
  tests (0x7fff, 1);
  tests (0x7fff +1, 0);
  tests (
        (0x7fff * 2 + 1)
                 , 0);

  testi (0, 0);
  testi (1, 1);
  testi (0x7fffffff, 1);
  testi (0x7fffffff +1U, 0);
  testi (
        (0x7fffffff * 2U + 1U)
                , 0);

  testl (0, 0);
  testl (1, 1);
  testl (0x7fffffffffffffffL, 1);
  testl (0x7fffffffffffffffL +1UL, 0);
  testl (
        (0x7fffffffffffffffL * 2UL + 1UL)
                 , 0);

  return 0;
}
