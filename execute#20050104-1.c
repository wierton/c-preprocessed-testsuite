
/* PR tree-optimization/19060 */

void abort (void);

static
long long min ()
{
  return -0x7fffffffffffffffLL - 1;
}

void
foo (long long j)
{
  if (j > 10 || j < min ())
    abort ();
}

int
main (void)
{
  foo (10);
  return 0;
}
