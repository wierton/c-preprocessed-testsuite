
/* PR middle-end/67485 */

long int
foo (long int x)
{
  return x * 0x7fffffffffffffffL;
}
