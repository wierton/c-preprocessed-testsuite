
#include <signal.h>



long double dnan = 1.0l/0.0l - 1.0l/0.0l;
long double x = 1.0l;

void leave ()
{
  exit (0);
}

main ()
{

  /* Move this line earlier, for architectures (like alpha) that issue 
     SIGFPE on the first comparisons. */

  /* Some machines catches a SIGFPE when a NaN is compared.
     Let this test succeed o such machines.  */
  signal (
         8
               , leave);

  /* NaN is an IEEE unordered operand.  All these test should be false.  */
  if (dnan == dnan)
    abort ();
  if (dnan != x)
    x = 1.0;
  else
    abort ();

  if (dnan < x)
    abort ();
  if (dnan > x)
    abort ();
  if (dnan <= x)
    abort ();
  if (dnan >= x)
    abort ();
  if (dnan == x)
    abort ();

  exit (0);
}
