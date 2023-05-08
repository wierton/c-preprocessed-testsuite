
/* { dg-add-options stack_size } */

/* Origin: hp@bitrange.com
   Test that return values come out right from a 1000-level call chain to
   functions without parameters that each need at least one "long"
   preserved.  Exposed problems related to the MMIX port.  */

long level = 0;
extern long foo (void);
extern long bar (void);







int
main (void)
{
  if (foo () == -42)
    exit (0);

  abort ();
}

long
foo (void)
{
  long tmp = ++level;
  return bar () + tmp;
}

long
bar (void)
{
  long tmp = level;
  return tmp > 500 - 1 ? -42 - tmp : foo () - tmp;
}
