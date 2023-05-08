
/* PR tree-optimization/48734 */

unsigned int
foo (int x, unsigned int y, unsigned int z)
{
  z &= (x == -0x7fffffff - 1 ? x : -x) > y;
  z &= (x == -0x7fffffff - 1 ? x : -x) > y;
  z &= (x == -0x7fffffff - 1 ? x : -x) > y;
  z &= (x == -0x7fffffff - 1 ? x : -x) > y;
  return z;
}
