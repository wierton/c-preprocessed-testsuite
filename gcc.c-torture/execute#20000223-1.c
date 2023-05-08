
/* Copyright (C) 2000 Free Software Foundation, Inc.
   Contributed by Nathan Sidwell 23 Feb 2000 <nathan@codesourcery.com> */

/* __alignof__ should never return a non-power of 2
   eg, sizeof(long double) might be 12, but that means it must be alignable
   on a 4 byte boundary. */

void check (char const *type, int align)
{
  if ((align & -align) != align)
    {
      abort ();
    }
}






// This struct should have an alignment of the lcm of all the types. If one of
// the base alignments is not a power of two, then A cannot be power of two
// aligned.
struct A
{
  char c;
  signed short ss;
  unsigned short us;
  signed int si;
  unsigned int ui;
  signed long sl;
  unsigned long ul;
  signed long long sll;
  unsigned long long ull;
  float f;
  double d;
  long double ld;
  void *dp;
  void (*fp)();
};

int main ()
{
  check("void", __alignof__(void));
  check("char", __alignof__(char));
  check("signed short", __alignof__(signed short));
  check("unsigned short", __alignof__(unsigned short));
  check("signed int", __alignof__(signed int));
  check("unsigned int", __alignof__(unsigned int));
  check("signed long", __alignof__(signed long));
  check("unsigned long", __alignof__(unsigned long));
  check("signed long long", __alignof__(signed long long));
  check("unsigned long long", __alignof__(unsigned long long));
  check("float", __alignof__(float));
  check("double", __alignof__(double));
  check("long double", __alignof__(long double));
  check("void *", __alignof__(void *));
  check("void (*)()", __alignof__(void (*)()));
  check("struct A", __alignof__(struct A));
  return 0;
}
