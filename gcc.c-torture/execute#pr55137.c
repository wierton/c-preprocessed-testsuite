
/* PR c++/55137 */

extern void abort (void);

int
foo (unsigned int x)
{
  return ((int) (x + 1U) + 1) < (int) x;
}

int
bar (unsigned int x)
{
  return (int) (x + 1U) + 1;
}

int
baz (unsigned int x)
{
  return x + 1U;
}

int
main ()
{
  if (foo (0x7fffffff) != (bar (0x7fffffff) < 0x7fffffff)
      || foo (0x7fffffff) != ((int) baz (0x7fffffff) + 1 < 0x7fffffff))
    abort ();
  return 0;
}
