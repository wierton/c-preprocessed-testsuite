
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target trampolines } */
/* { dg-add-options stack_size } */

/* A slight variation of 920501-7.c.  */







x(a)
{
  __label__ xlab;
  void y(a)
    {
      void *x = &&llab;
      if (a==-1)
 goto *x;
      if (a==0)
 goto xlab;
    llab:
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
