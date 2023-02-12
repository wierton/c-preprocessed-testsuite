
/* The FR-V port used to fail this test because the andcc patterns
   wrongly claimed to set the C and V flags.  */
#include <limits.h>


int x[4] = { 
            (-0x7fffffff - 1) 
                    / 2, 0x7fffffff, 2, 4 };

int
main ()
{
  if (x[0] < x[1])
    if ((x[2] & x[3]) < 0)
      abort ();
  exit (0);
}
