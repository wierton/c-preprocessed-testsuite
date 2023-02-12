#include <limits.h>


extern void abort ();

int test1(int x)
{
  return ~(x ^ 
              (-0x7fffffff - 1)
                     );
}

unsigned int test1u(unsigned int x)
{
  return ~(x ^ (unsigned int)
                            (-0x7fffffff - 1)
                                   );
}

unsigned int test2u(unsigned int x)
{
  return ~(x + (unsigned int)
                            (-0x7fffffff - 1)
                                   );
}

unsigned int test3u(unsigned int x)
{
  return ~(x - (unsigned int)
                            (-0x7fffffff - 1)
                                   );
}

int test4(int x)
{
  int y = 
         (-0x7fffffff - 1)
                ;
  return ~(x ^ y);
}

unsigned int test4u(unsigned int x)
{
  unsigned int y = (unsigned int)
                                (-0x7fffffff - 1)
                                       ;
  return ~(x ^ y);
}

unsigned int test5u(unsigned int x)
{
  unsigned int y = (unsigned int)
                                (-0x7fffffff - 1)
                                       ;
  return ~(x + y);
}

unsigned int test6u(unsigned int x)
{
  unsigned int y = (unsigned int)
                                (-0x7fffffff - 1)
                                       ;
  return ~(x - y);
}



void test(int a, int b)
{
  if (test1(a) != b)
    abort();
  if (test4(a) != b)
    abort();
}

void testu(unsigned int a, unsigned int b)
{
  if (test1u(a) != b)
    abort();
  if (test2u(a) != b)
    abort();
  if (test3u(a) != b)
    abort();
  if (test4u(a) != b)
    abort();
  if (test5u(a) != b)
    abort();
  if (test6u(a) != b)
    abort();
}


int main()
{

  test(0x00000000,0x7fffffff);
  test(0x80000000,0xffffffff);
  test(0x12345678,0x6dcba987);
  test(0x92345678,0xedcba987);
  test(0x7fffffff,0x00000000);
  test(0xffffffff,0x80000000);

  testu(0x00000000,0x7fffffff);
  testu(0x80000000,0xffffffff);
  testu(0x12345678,0x6dcba987);
  testu(0x92345678,0xedcba987);
  testu(0x7fffffff,0x00000000);
  testu(0xffffffff,0x80000000);
  return 0;
}
