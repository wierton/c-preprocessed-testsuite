
/* { dg-additional-options "-fwrapv" } */

#include <limits.h>


extern void abort ();

int test2(int x)
{
  return x + 
            (-0x7fffffff - 1)
                   ;
}

int test3(int x)
{
  return x - 
            (-0x7fffffff - 1)
                   ;
}

int test5(int x)
{
  int y = 
         (-0x7fffffff - 1)
                ;
  return x + y;
}

int test6(int x)
{
  int y = 
         (-0x7fffffff - 1)
                ;
  return x - y;
}



void test(int a, int b)
{
  if (test2(a) != b)
    abort();
  if (test3(a) != b)
    abort();
  if (test5(a) != b)
    abort();
  if (test6(a) != b)
    abort();
}


int main()
{

  test(0x00000000,0x80000000);
  test(0x80000000,0x00000000);
  test(0x12345678,0x92345678);
  test(0x92345678,0x12345678);
  test(0x7fffffff,0xffffffff);
  test(0xffffffff,0x7fffffff);
  return 0;
}
