#include <stdio.h>
#include <stddef.h>

extern void abort (void);
extern int inside_main;
extern size_t strlen(const char *);
int
fputs(const char *string, FILE *stream)
{
  size_t n = strlen(string);
  size_t r;




  r = fwrite (string, 1, n, stream);
  return n > r ? 
                (-1) 
                    : 0;
}

/* Locking stdio doesn't matter for the purposes of this test.  */
int
fputs_unlocked(const char *string, FILE *stream)
{
  return fputs (string, stream);
}
