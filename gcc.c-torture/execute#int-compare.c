#include <limits.h>


gt (a, b)
{
  return a > b;
}

ge (a, b)
{
  return a >= b;
}

lt (a, b)
{
  return a < b;
}

le (a, b)
{
  return a <= b;
}

void
true (c)
{
  if (!c)
    abort();
}

void
false (c)
{
  if (c)
    abort();
}

f ()
{
  true (gt (2, 1));
  false (gt (1, 2));

  true (gt (0x7fffffff, 0));
  false (gt (0, 0x7fffffff));
  true (gt (0x7fffffff, 1));
  false (gt (1, 0x7fffffff));

  false (gt (
            (-0x7fffffff - 1)
                   , 0));
  true (gt (0, 
              (-0x7fffffff - 1)
                     ));
  false (gt (
            (-0x7fffffff - 1)
                   , 1));
  true (gt (1, 
              (-0x7fffffff - 1)
                     ));

  true (gt (0x7fffffff, 
                    (-0x7fffffff - 1)
                           ));
  false (gt (
            (-0x7fffffff - 1)
                   , 0x7fffffff));

  true (ge (2, 1));
  false (ge (1, 2));

  true (ge (0x7fffffff, 0));
  false (ge (0, 0x7fffffff));
  true (ge (0x7fffffff, 1));
  false (ge (1, 0x7fffffff));

  false (ge (
            (-0x7fffffff - 1)
                   , 0));
  true (ge (0, 
              (-0x7fffffff - 1)
                     ));
  false (ge (
            (-0x7fffffff - 1)
                   , 1));
  true (ge (1, 
              (-0x7fffffff - 1)
                     ));

  true (ge (0x7fffffff, 
                    (-0x7fffffff - 1)
                           ));
  false (ge (
            (-0x7fffffff - 1)
                   , 0x7fffffff));

  false (lt (2, 1));
  true (lt (1, 2));

  false (lt (0x7fffffff, 0));
  true (lt (0, 0x7fffffff));
  false (lt (0x7fffffff, 1));
  true (lt (1, 0x7fffffff));

  true (lt (
           (-0x7fffffff - 1)
                  , 0));
  false (lt (0, 
               (-0x7fffffff - 1)
                      ));
  true (lt (
           (-0x7fffffff - 1)
                  , 1));
  false (lt (1, 
               (-0x7fffffff - 1)
                      ));

  false (lt (0x7fffffff, 
                     (-0x7fffffff - 1)
                            ));
  true (lt (
           (-0x7fffffff - 1)
                  , 0x7fffffff));

  false (le (2, 1));
  true (le (1, 2));

  false (le (0x7fffffff, 0));
  true (le (0, 0x7fffffff));
  false (le (0x7fffffff, 1));
  true (le (1, 0x7fffffff));

  true (le (
           (-0x7fffffff - 1)
                  , 0));
  false (le (0, 
               (-0x7fffffff - 1)
                      ));
  true (le (
           (-0x7fffffff - 1)
                  , 1));
  false (le (1, 
               (-0x7fffffff - 1)
                      ));

  false (le (0x7fffffff, 
                     (-0x7fffffff - 1)
                            ));
  true (le (
           (-0x7fffffff - 1)
                  , 0x7fffffff));
}

main ()
{
  f ();
  exit (0);
}
