
/* { dg-add-options stack_size } */

#include <stdlib.h>


int *a, *b;
int n;






foo ()
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = -1;
  for (i = 0; i < 32768 - 1; i++)
    b[i] = -1;
}

main ()
{
  n = 32768;
  a = malloc (n * sizeof(*a));
  b = malloc (n * sizeof(*b));
  *b++ = 0;
  foo ();
  if (b[-1])
    abort ();
  exit (0);
}
