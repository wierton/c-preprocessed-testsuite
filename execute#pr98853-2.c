
/* PR target/98853 */


__attribute__((noipa)) unsigned long long
foo (unsigned long long x, unsigned int y)
{
  return ((unsigned) x & 0xfffe0000U) | (y & 0x1ffff);
}


int
main ()
{

  if (foo (0xdeadbeefcaf2babeULL, 0xdeaffeedU) != 0x00000000caf3feedULL)
    __builtin_abort ();

  return 0;
}
