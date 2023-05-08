#include <limits.h>


int main (void)
{
  void *x = ((void *)((unsigned int)0x7fffffff + 2));
  void *y = ((void *)((unsigned long)0x7fffffffffffffffL + 2));
  if (x >= ((void *)((unsigned int)0x7fffffff + 1))
      && x <= ((void *)((unsigned int)0x7fffffff + 6))
      && y >= ((void *)((unsigned long)0x7fffffffffffffffL + 1))
      && y <= ((void *)((unsigned long)0x7fffffffffffffffL + 6)))
    exit (0);
  else
    abort ();
}
