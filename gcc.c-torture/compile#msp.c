
/* { dg-add-options stack_size } */






foo ()
{
  int a[16384];
  bar (a);
}
