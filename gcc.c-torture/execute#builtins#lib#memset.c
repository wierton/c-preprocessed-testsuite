
extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
void *
memset (void *dst, int c, long unsigned int n)
{
  while (n-- != 0)
    n[(char *) dst] = c;

  /* Single-byte memsets should be done inline when optimisation
     is enabled.  Do this after the copy in case we're being called to
     initialize bss.  */





  return dst;
}
