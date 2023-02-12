
/* PR rtl-optimization/51447 */
/* { dg-require-effective-target label_values } */
/* { dg-require-effective-target indirect_jumps } */

extern void abort (void);


register void *ptr asm ("rbx");




int
main (void)
{
  __label__ nonlocal_lab;

  void *save = ptr;

  __attribute__((noinline, noclone)) void
    bar (void *func)
      {
 ptr = func;
 goto nonlocal_lab;
      }
  bar (&&nonlocal_lab);
  return 1;
nonlocal_lab:
  if (ptr != &&nonlocal_lab)
    abort ();

  ptr = save; /* Restore the call-saved register.  */

  return 0;
}
