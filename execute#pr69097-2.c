
/* PR tree-optimization/69097 */

__attribute__((noinline, noclone)) int
f1 (int x, int y)
{
  return x % y;
}

__attribute__((noinline, noclone)) int
f2 (int x, int y)
{
  return x % -y;
}

__attribute__((noinline, noclone)) int
f3 (int x, int y)
{
  int z = -y;
  return x % z;
}

int
main ()
{
  if (f1 (-0x7fffffff - 1, 1) != 0
      || f2 (-0x7fffffff - 1, -1) != 0
      || f3 (-0x7fffffff - 1, -1) != 0)
    __builtin_abort ();
  return 0;
}
