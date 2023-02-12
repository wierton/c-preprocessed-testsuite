#include <limits.h>


int n = 0;

g (i)
{
  n++;
}

f (m)
{
  int i;
  i = m;
  do
    {
      g (i * 4);
      i -= 0x7fffffff / 8;
    }
  while (i > 0);
}

main ()
{
  f (0x7fffffff/8*4);
  if (n != 4)
    abort ();
  exit (0);
}
