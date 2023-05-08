
/* PR target/98853 */


__attribute__((__noipa__)) unsigned long long
foo (unsigned x, unsigned long long y, unsigned long long z)
{
  __builtin_memcpy (2 + (char *) &x, 2 + (char *) &y, 2);
  return x + z;
}


int
main ()
{

  if (foo (0x44444444U, 0x1111111111111111ULL, 0x2222222222222222ULL)
      != 0x2222222233336666ULL)
    __builtin_abort ();

  return 0;
}
