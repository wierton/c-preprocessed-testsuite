
/* Copyright (C) 1999 Free Software Foundation, Inc.
  Contributed by Nathan Sidwell 20 Jan 1999 <nathan@acm.org> */

/* check range combining boolean operations work */

extern void abort();



void func(int i)
{
  /* fold-const does some clever things with range tests. Make sure
     we get (some of) them right */

  /* these must fail, regardless of the value of i */
  if ((i < 0) && (i >= 0))
    abort();
  if ((i > 0) && (i <= 0))
    abort();
  if ((i >= 0) && (i < 0))
    abort();
  if ((i <= 0) && (i > 0))
    abort();

  if ((i < 77) && (i >= 77))
    abort();
  if ((i > 77) && (i <= 77))
    abort();
  if ((i >= 77) && (i < 77))
    abort();
  if ((i <= 77) && (i > 77))
    abort();

  /* these must pass, regardless of the value of i */
  if (! ((i < 0) || (i >= 0)))
    abort();
  if (! ((i > 0) || (i <= 0)))
    abort();
  if (! ((i >= 0) || (i < 0)))
    abort();
  if (! ((i <= 0) || (i > 0)))
    abort();

  if (! ((i < 77) || (i >= 77)))
    abort();
  if (! ((i > 77) || (i <= 77)))
    abort();
  if (! ((i >= 77) || (i < 77)))
    abort();
  if (! ((i <= 77) || (i > 77)))
    abort();

  return;
}

int main()
{
  func(0);
  func(1);
  return 0;
}
