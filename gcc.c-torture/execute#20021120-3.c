
/* Test whether a partly call-clobbered register will be moved over a call.
   Although the original test case didn't use any GNUisms, it proved
   difficult to reduce without the named register extension.  */






unsigned int foo (char *c, unsigned int x, unsigned int y)
{
  register unsigned int z ;

  sprintf (c, "%d", x / y);
  z = x + 1;
  return z / (y + 1);
}

int main ()
{
  char c[16];

  if (foo (c, ~1U, 4) != (~0U / 5))
    abort ();
  exit (0);
}
