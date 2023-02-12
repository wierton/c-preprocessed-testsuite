
/* PR sanitizer/81281 */

void
foo (unsigned p, unsigned a, unsigned b)
{
  unsigned q = p + 7;
  if (a - (1U + 0x7fffffff) >= 2)
    __builtin_unreachable ();
  int d = p + b;
  int c = p + a;
  if (c - d != 0x7fffffff)
    __builtin_abort ();
}

void
bar (unsigned p, unsigned a)
{
  unsigned q = p + 7;
  if (a - (1U + 0x7fffffff) >= 2)
    __builtin_unreachable ();
  int c = p;
  int d = p + a;
  if (c - d != -0x7fffffff - 1)
    __builtin_abort ();
}

int
main ()
{
  foo (-1U, 1U + 0x7fffffff, 1U);
  bar (-1U, 1U + 0x7fffffff);
  return 0;
}
