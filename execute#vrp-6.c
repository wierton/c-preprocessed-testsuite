
/* { dg-require-effective-target int32plus } */
#include <limits.h>


extern void exit (int);
extern void abort ();

void test01(unsigned int a, unsigned int b)
{
  if (a < 5)
    abort();
  if (b < 5)
    abort();
  if (a - b != 5)
    abort();
}

void test02(unsigned int a, unsigned int b)
{
  if (a >= 12)
    if (b > 15)
      if (a - b < 
                 (0x7fffffff * 2U + 1U) 
                          - 15U)
 abort ();
}

int main(int argc, char *argv[])
{
  unsigned x = 0x80000000;
  test01(x + 5, x);
  test02(14, 16);
  exit (0);
}
