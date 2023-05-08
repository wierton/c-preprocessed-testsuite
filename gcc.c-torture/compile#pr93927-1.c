
/* PR tree-optimization/93927 */

long unsigned int strstr (const char *, const char *);

char *
foo (char *x)
{
  return !!strstr (x, "0") ? "0" : "1";
}
