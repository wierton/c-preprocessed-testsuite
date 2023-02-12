
/* PR tree-optimization/106878 */

typedef long int intptr_t;
typedef long unsigned int uintptr_t;
int a;

int
foo (const int *c)
{
  uintptr_t d = ((intptr_t) c | (intptr_t) &a) & 65535 << 16;
  intptr_t e = (intptr_t) c;
  if (d != (e & 65535 << 16))
    return 1;
  return 0;
}
