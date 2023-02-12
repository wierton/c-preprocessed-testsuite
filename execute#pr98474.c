
/* PR tree-optimization/98474 */


typedef __uint128_t T;






__attribute__ ((noipa)) void
foo (T *x)
{
  *x += ((T) 1) << ((16 * 8 / 2) + 1);
}

int
main ()
{
  T a = ((T) 1) << ((16 * 8 / 2) + 1);
  T b = a;
  T n;
  foo (&b);
  n = b;
  while (n >= a)
    n -= a;
  if ((int) (n >> (16 * 8 / 2)) != 0)
    __builtin_abort ();
  return 0;
}
