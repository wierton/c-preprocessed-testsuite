
/* PR middle-end/83164 */

long int
foo (void)
{
  return (char *) foo - (char *) 0x1230;
}
