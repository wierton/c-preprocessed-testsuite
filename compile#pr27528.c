
/* Check that constant constraints like "i", "n" and "s" can be used in
   cases where the operand is an initializer constant.  */
/* { dg-require-effective-target nonpic } */

int x[2] = { 1, 2 };
void
foo (void)
{
  asm volatile ("" :: "s" (x), "i" (x));
  /* At the time of writing, &x[1] is decomposed before reaching expand
     when compiling with -O0.  */
  asm volatile ("" :: "s" ("string"), "i" ("string"));
  asm volatile ("" :: "s" ("compile/pr27528.c"), "i" ("compile/pr27528.c"));
  asm volatile ("" :: "s" (__FUNCTION__), "i" (__FUNCTION__));
}
