
/* { dg-options "-fwrapv" } */
#include <limits.h>

extern void abort ();
extern void exit (int);
void f(int i)
{
  i = i > 0 ? i : -i;
  if (i<0)
    return;
  abort ();
}

int main(int argc, char *argv[])
{
  f(
   (-0x7fffffff - 1)
          );
  exit (0);
}
