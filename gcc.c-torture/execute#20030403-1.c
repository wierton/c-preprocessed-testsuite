
/* The non-destructive folder was always emitting >= when folding
   comparisons to signed_max+1.  */

#include <limits.h>


int
main ()
{
  unsigned long count = 8;

  if (count > 0x7fffffff)
    abort ();

  return (0);
}
