
/* PR tree-optimization/80426 */
/* Testcase by <ishiura-compiler@ml.kwansei.ac.jp> */




int x;

int main (void)
{
  volatile int a = 0;
  volatile int b = -0x7fffffff;
  int j;

  for(j = 0; j < 18; j += 1) {
    x = ( (a == 0) != (b - (int)((-0x7fffffff -1)) ) );
  }

  if (x != 0)
    __builtin_abort ();

  return 0;
}
