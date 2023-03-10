
/* PR rtl-optimization/97386 */

__attribute__((noipa)) unsigned char
foo (unsigned int c)
{
  return __builtin_bswap16 ((unsigned long long) (0xccccLLU << c | 0xccccLLU >> ((-c) & 63)));
}

int
main ()
{
  unsigned char x = foo (0);
  if (8 == 8 && 2 == 2 && x != 0xcc)
    __builtin_abort ();
  return 0;
}
