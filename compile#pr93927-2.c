
/* PR tree-optimization/93927 */

long unsigned int strchr (const char *, int);

char *
foo (char *x)
{
  return !!strchr (x, 0) ? "0" : "1";
}
