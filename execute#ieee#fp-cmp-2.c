
#include <signal.h>



float fnan = 1.0f/0.0f - 1.0f/0.0f;
float x = 1.0f;

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
  if (fnan == fnan)
    abort ();
  if (fnan != x)
    x = 1.0;
  else
    abort ();

  if (fnan < x)
    abort ();
  if (fnan > x)
    abort ();
  if (fnan <= x)
    abort ();
  if (fnan >= x)
    abort ();
  if (fnan == x)
    abort ();

  exit (0);
}
