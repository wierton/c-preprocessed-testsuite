
/* Copyright (C) 2002  Free Software Foundation.

   Test memset with various combinations of pointer alignments and lengths to
   make sure any optimizations in the library are correct.

   Written by Michael Meissner, March 9, 2002.  */

#include <string.h>

static union {
  char buf[((sizeof (long long)) + (10 * sizeof (long long)) + (sizeof (long long)))];
  long long align_int;
  long double align_fp;
} u;

char A = 'A';

main ()
{
  int off, len, i;
  char *p, *q;

  for (off = 0; off < (sizeof (long long)); off++)
    for (len = 1; len < (10 * sizeof (long long)); len++)
      {
 for (i = 0; i < ((sizeof (long long)) + (10 * sizeof (long long)) + (sizeof (long long))); i++)
   u.buf[i] = 'a';

 p = memset (u.buf + off, '\0', len);
 if (p != u.buf + off)
   abort ();

 q = u.buf;
 for (i = 0; i < off; i++, q++)
   if (*q != 'a')
     abort ();

 for (i = 0; i < len; i++, q++)
   if (*q != '\0')
     abort ();

 for (i = 0; i < (sizeof (long long)); i++, q++)
   if (*q != 'a')
     abort ();

 p = memset (u.buf + off, A, len);
 if (p != u.buf + off)
   abort ();

 q = u.buf;
 for (i = 0; i < off; i++, q++)
   if (*q != 'a')
     abort ();

 for (i = 0; i < len; i++, q++)
   if (*q != 'A')
     abort ();

 for (i = 0; i < (sizeof (long long)); i++, q++)
   if (*q != 'a')
     abort ();

 p = memset (u.buf + off, 'B', len);
 if (p != u.buf + off)
   abort ();

 q = u.buf;
 for (i = 0; i < off; i++, q++)
   if (*q != 'a')
     abort ();

 for (i = 0; i < len; i++, q++)
   if (*q != 'B')
     abort ();

 for (i = 0; i < (sizeof (long long)); i++, q++)
   if (*q != 'a')
     abort ();
      }

  exit (0);
}
