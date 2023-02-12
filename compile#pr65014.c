
/* PR tree-optimization/65014 */
/* { dg-do compile { target int32plus } } */

extern int x;

unsigned
foo (unsigned int y)
{
  return (y << ((long int) &x)) | (y >> (32 - ((long int) &x)));
}
