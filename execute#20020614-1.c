
/* PR c/6677 */
/* Verify that GCC doesn't perform illegal simplifications
   when folding constants.  */

#include <limits.h>


extern void abort (void);
extern void exit (int);

int main (void)
{
  int i;
  signed char j;
  unsigned char k;

  i = 0x7f;

  j = ((signed char) (i << 1)) / 2;

  if (j != -1)
    abort();

  j = ((signed char) (i * 2)) / 2;

  if (j != -1)
    abort();

  i = 
     (0x7f * 2 + 1)
              ;

  k = ((unsigned char) (i << 1)) / 2;

  if (k != 
          (0x7f * 2 + 1)
                   /2)
    abort();

  k = ((unsigned char) (i * 2)) / 2;

  if (k != 
          (0x7f * 2 + 1)
                   /2)
    abort();

  exit(0);
}
