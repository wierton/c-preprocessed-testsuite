
/* PR tree-optimization/89703 */

typedef long unsigned int size_t;
extern void *memcpy (void *, const void *, size_t);
extern char *strlen (const char *);
extern char c[2];

void
foo (char **q)
{
  memcpy (c, "a", 2);
  q[0] = strlen (c);
}
