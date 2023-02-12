
/* PR middle-end/28151 */
/* Testcase by Steven Bosscher <stevenb.gcc@gmail.com> */

_Complex float b;

void foo (void)
{
  _Complex float a = 3.40282346638528859811704183484516925e+38F;
  b = 3.40282346638528859811704183484516925e+38F + a;
}
