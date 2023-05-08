
/* PR rtl-optimization/88904 */

volatile int v;

__attribute__((noipa)) void
bar (const char *x, const char *y, int z)
{
  if (!v)
    __builtin_abort ();
  asm volatile ("" : "+g" (x));
  asm volatile ("" : "+g" (y));
  asm volatile ("" : "+g" (z));
}



typedef struct {
  unsigned M1;
  unsigned M2 : 1;
  int : 0;
  unsigned M3 : 1;
} S;

S
foo ()
{
  S result = {0, 0, 1};
  return result;
}

int
main ()
{
  S ret = foo ();
  ((ret.M2 == 0) ? (void) 0 : bar ("ret.M2 == 0", "execute/pr88904.c", 35));
  ((ret.M3 == 1) ? (void) 0 : bar ("ret.M3 == 1", "execute/pr88904.c", 36));
  return 0;
}
