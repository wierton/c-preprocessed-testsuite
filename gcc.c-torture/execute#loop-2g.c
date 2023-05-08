
/* { dg-require-effective-target mmap } */
/* { dg-skip-if "the executable is at the same position the test tries to remap" { m68k-*-linux* } } */

#include <limits.h>

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

f (int s, char *p)
{
  int i;
  for (i = s; &p[i] < &p[40] && i >= 0; i++)
    {
      p[i] = -2;
    }
}

main ()
{

  char *p;
  int dev_zero;

  dev_zero = open ("/dev/zero", 
                               00
                                       );
  /* -1 is OK when we have MAP_ANON; else mmap will flag an error.  */
  if (0x7fffffff != 0x7fffffffL || sizeof (char *) != sizeof (int))
    exit (0);
  p = mmap ((void *)0x7fff8000, 0x10000, 
                               0x1
                                        |
                                         0x2
                                                   ,
     
    0x20
            |
             0x10
                      |
                       0x02
                                  , dev_zero, 0);
  if (p != (char *)-1)
    {
      p += (0x10000/2 - 2 * sizeof (char));;
      p[39] = 0;
      f (0, p);
      if (p[39] != (char)-2)
 abort ();
      p[39] = 0;
      f (-1, p);
      if (p[39] != 0)
 abort ();
    }

  exit (0);
}
