
/* Copyright (C) 2004 Free Software Foundation.

   Check that constant folding and RTL simplification of -(x >> y) doesn't
   break anything and produces the expected results.

   Written by Roger Sayle, 11th March 2004.  */

extern void abort (void);



int test1(int x)
{
  return -(x >> ((sizeof(int)*8)-1));
}

int test2(unsigned int x)
{
  return -((int)(x >> ((sizeof(int)*8)-1)));
}

int test3(int x)
{
  int y;
  y = (sizeof(int)*8)-1;
  return -(x >> y);
}

int test4(unsigned int x)
{
  int y;
  y = (sizeof(int)*8)-1;
  return -((int)(x >> y));
}

int main()
{
  if (test1(0) != 0)
    abort ();
  if (test1(1) != 0)
    abort ();
  if (test1(-1) != 1)
    abort ();

  if (test2(0) != 0)
    abort ();
  if (test2(1) != 0)
    abort ();
  if (test2((unsigned int)-1) != -1)
    abort ();

  if (test3(0) != 0)
    abort ();
  if (test3(1) != 0)
    abort ();
  if (test3(-1) != 1)
    abort ();

  if (test4(0) != 0)
    abort ();
  if (test4(1) != 0)
    abort ();
  if (test4((unsigned int)-1) != -1)
    abort ();

  return 0;
}
