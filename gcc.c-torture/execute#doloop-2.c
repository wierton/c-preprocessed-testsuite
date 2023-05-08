#include <limits.h>


extern void exit (int);
extern void abort (void);

volatile unsigned int i;

int
main (void)
{
  unsigned short z = 0;

  do ++i;
  while (--z > 0);
  if (i != 
          (0x7fff * 2 + 1) 
                    + 1U)
    abort ();
  exit (0);
}
