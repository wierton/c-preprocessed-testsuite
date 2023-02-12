
/* Copyright (C) 2002  Free Software Foundation.

   Test strlen with various combinations of pointer alignments and lengths to
   make sure any optimizations in the library are correct.

   Written by Michael Meissner, March 9, 2002.  */

#include <string.h>
#include <stddef.h>

static union {
  char buf[((sizeof (long long)) + (8 * sizeof (long long)) + (sizeof (long long)) + 1)];
  long long align_int;
  long double align_fp;
} u;

main ()
{
  size_t off, len, len2, i;
  char *p;

  for (off = 0; off < (sizeof (long long)); off++)
    for (len = 0; len < (8 * sizeof (long long)); len++)
      {
 p = u.buf;
 for (i = 0; i < off; i++)
   *p++ = '\0';

 for (i = 0; i < len; i++)
   *p++ = 'a';

 *p++ = '\0';
 for (i = 0; i < (sizeof (long long)); i++)
   *p++ = 'b';

 p = u.buf + off;
 len2 = strlen (p);
 if (len != len2)
   abort ();
      }

  exit (0);
}
