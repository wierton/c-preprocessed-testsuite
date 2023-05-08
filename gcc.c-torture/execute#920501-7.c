
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target trampolines } */
/* { dg-add-options stack_size } */







x(a)
{
  __label__ xlab;
  void y(a)
    {
      if (a==0)
 goto xlab;
      y (a-1);
    }
  y (a);
 xlab:;
  return a;
}

main ()
{
  if (x (1000) != 1000)
    abort ();

  exit (0);
}
