
/* PR rtl-optimization/84169 */


typedef unsigned __int128 T;




T b;

static __attribute__ ((noipa)) T
foo (T c, T d, T e, T f, T g, T h)
{
  __builtin_mul_overflow ((unsigned char) h, -16, &h);
  return b + h;
}

int
main ()
{
  T x = foo (0, 0, 0, 0, 0, 4);
  if (x != -64)
    __builtin_abort ();
  return 0;
}
