
/* PR tree-optimization/104196 */

int a = 6;

int
main ()
{
  while (1)
    {
      int b = a < 0 && 0 < -0x7fffffff - a ? 0 : a;
      if (b != 4096 - 0x7fffffff)
 {
   if (a < 6)
     __builtin_abort ();
   break;
 }
    }
  return 0;
}
