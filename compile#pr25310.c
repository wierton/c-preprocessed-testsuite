
/* { dg-skip-if "Array too big" { "pdp11-*-*" } { "-mint32" } } */
/* { dg-require-stack-size "65536+20" } */

/* Prevent spurious test failures on 16-bit targets.  */


extern int f (char *, int);

void test (void)
{
  char buffer[65536];
  char *bufptr;
  char *bufend;
  int bytes;

  bufptr = buffer;
  bufend = buffer + sizeof(buffer) - 1;

  while ((bytes = f (bufptr, bufend - bufptr)) > 0)
    bufptr += bytes;
}
