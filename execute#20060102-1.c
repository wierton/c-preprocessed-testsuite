
extern void abort ();

int f(int x)
{
  return (x >> (sizeof (x) * 8 - 1)) ? -1 : 1;
}

volatile int one = 1;
int main (void)
{
  /* Test that the function above returns different values for
     different signs.  */
  if (f(one) == f(-one))
    abort ();
  return 0;
}
