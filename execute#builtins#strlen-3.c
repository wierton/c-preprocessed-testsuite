
/* Copyright (C) 2004  Free Software Foundation.

   Test strlen on const variables initialized to string literals.

   Written by Jakub Jelinek, 9/14/2004.  */

extern void abort (void);
extern long unsigned int strlen (const char *);
extern char *strcpy (char *, const char *);
static const char bar[] = "Hello, World!";
static const char baz[] = "hello, world?";
static const char larger[20] = "short string";
extern int inside_main;

int l1 = 1;
int x = 6;

void
main_test(void)
{
  inside_main = 1;






  if (strlen (bar) != 13)
    abort ();

  if (strlen (bar + 3) != 10)
    abort ();

  if (strlen (&bar[6]) != 7)
    abort ();

  if (strlen (bar + (x++ & 7)) != 7)
    abort ();
  if (x != 7)
    abort ();
  if (strlen (larger) != 12)
    abort ();
  if (strlen (&larger[10]) != 2)
    abort ();

  inside_main = 0;
  /* The following call may or may not be folded depending on
     the optimization level, and when it isn't folded (such
     as may be the case with -Og) it may or may not result in
     a library call, depending on whether or not it's expanded
     inline (e.g., powerpc64 makes a call while x86_64 expands
     it inline).  */
  if (strlen (larger + (x++ & 7)) != 5)
    abort ();
  if (x != 8)
    abort ();
  inside_main = 1;
}
