#include <limits.h>


extern void abort (void);

static __attribute__((noinline)) void foo (int a)
{
  int b = (a - 1) + 
                   (-0x7fffffff - 1)
                          ;

  if (b != 
          (-0x7fffffff - 1)
                 )
    abort ();
}

int main (void)
{
  foo (1);
  return 0;
}
