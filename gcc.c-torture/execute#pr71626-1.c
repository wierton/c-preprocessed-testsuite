
/* PR middle-end/71626 */

typedef long int V __attribute__((__vector_size__(sizeof (long int))));

__attribute__((noinline, noclone)) V
foo ()
{
  V v = { (long int) foo };
  return v;
}

int
main ()
{
  V v = foo ();
  if (v[0] != (long int) foo)
    __builtin_abort ();
  return 0;
}
