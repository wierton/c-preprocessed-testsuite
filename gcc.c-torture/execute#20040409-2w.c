
/* { dg-additional-options "-fwrapv" } */

#include <limits.h>


extern void abort ();

int test3(int x)
{
  return (x + 
             (-0x7fffffff - 1)
                    ) ^ 0x1234;
}

int test4(int x)
{
  return (x ^ 0x1234) + 
                       (-0x7fffffff - 1)
                              ;
}

int test5(int x)
{
  return (x - 
             (-0x7fffffff - 1)
                    ) ^ 0x1234;
}

int test6(int x)
{
  return (x ^ 0x1234) - 
                       (-0x7fffffff - 1)
                              ;
}

int test9(int x)
{
  int y = 
         (-0x7fffffff - 1)
                ;
  int z = 0x1234;
  return (x + y) ^ z;
}

int test10(int x)
{
  int y = 0x1234;
  int z = 
         (-0x7fffffff - 1)
                ;
  return (x ^ y) + z;
}

int test11(int x)
{
  int y = 
         (-0x7fffffff - 1)
                ;
  int z = 0x1234;
  return (x - y) ^ z;
}

int test12(int x)
{
  int y = 0x1234;
  int z = 
         (-0x7fffffff - 1)
                ;
  return (x ^ y) - z;
}


void test(int a, int b)
{
  if (test3(a) != b)
    abort();
  if (test4(a) != b)
    abort();
  if (test5(a) != b)
    abort();
  if (test6(a) != b)
    abort();
  if (test9(a) != b)
    abort();
  if (test10(a) != b)
    abort();
  if (test11(a) != b)
    abort();
  if (test12(a) != b)
    abort();
}


int main()
{

  test(0x00000000,0x80001234);
  test(0x00001234,0x80000000);
  test(0x80000000,0x00001234);
  test(0x80001234,0x00000000);
  test(0x7fffffff,0xffffedcb);
  test(0xffffffff,0x7fffedcb);
  return 0;
}
