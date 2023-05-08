
/* { dg-require-profiling "-fprofile-generate" } */
/* { dg-options "-fipa-pta -fprofile-generate" } */
void *
memcpy (void *a, const void *b, long unsigned int len)
{
  if (a == b)
    __builtin_abort ();
}
