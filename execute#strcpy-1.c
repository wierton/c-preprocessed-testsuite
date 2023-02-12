
/* Copyright (C) 2002  Free Software Foundation.

   Test strcpy with various combinations of pointer alignments and lengths to
   make sure any optimizations in the library are correct.  */

#include <string.h>

/* Use a sequence length that is not divisible by two, to make it more
   likely to detect when words are mixed up.  */


static union {
  char buf[((sizeof (long long)) + (10 * sizeof (long long)) + 1 + (sizeof (long long)))];
  long long align_int;
  long double align_fp;
} u1, u2;

main ()
{
  int off1, off2, len, i;
  char *p, *q, c;

  for (off1 = 0; off1 < (sizeof (long long)); off1++)
    for (off2 = 0; off2 < (sizeof (long long)); off2++)
      for (len = 1; len < (10 * sizeof (long long)); len++)
 {
   for (i = 0, c = 'A'; i < ((sizeof (long long)) + (10 * sizeof (long long)) + 1 + (sizeof (long long))); i++, c++)
     {
       u1.buf[i] = 'a';
       if (c >= 'A' + 31)
  c = 'A';
       u2.buf[i] = c;
     }
   u2.buf[off2 + len] = '\0';

   p = strcpy (u1.buf + off1, u2.buf + off2);
   if (p != u1.buf + off1)
     abort ();

   q = u1.buf;
   for (i = 0; i < off1; i++, q++)
     if (*q != 'a')
       abort ();

   for (i = 0, c = 'A' + off2; i < len; i++, q++, c++)
     {
       if (c >= 'A' + 31)
  c = 'A';
       if (*q != c)
  abort ();
     }

   if (*q++ != '\0')
     abort ();
   for (i = 0; i < (sizeof (long long)); i++, q++)
     if (*q != 'a')
       abort ();
 }

  exit (0);
}
