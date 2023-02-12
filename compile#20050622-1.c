
/* { dg-skip-if "Array too big" { "pdp11-*-*" } { "-mint32" } } */


struct S { char buf[72*1024*1024]; };




extern void bar (struct S);

struct S s;

int
foo (void)
{
  bar (s);
  return 0;
}
