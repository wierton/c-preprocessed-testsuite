
/* PR c/5078 */

#include <limits.h>


int f(int i)
{
  i -= 2 * (0x7fffffff + 1);
  return i;
}
