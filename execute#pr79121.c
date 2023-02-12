



  
 typedef unsigned uint32_t;
  typedef int int32_t;


extern void abort (void);

__attribute__ ((noinline, noclone)) unsigned long long f1 (int32_t x)
{
  return ((unsigned long long) x) << 4;
}

__attribute__ ((noinline, noclone)) long long f2 (uint32_t x)
{
  return ((long long) x) << 4;
}

__attribute__ ((noinline, noclone)) unsigned long long f3 (uint32_t x)
{
  return ((unsigned long long) x) << 4;
}

__attribute__ ((noinline, noclone)) long long f4 (int32_t x)
{
  return ((long long) x) << 4;
}

int main ()
{
  if (f1 (0xf0000000) != 0xffffffff00000000)
    abort ();
  if (f2 (0xf0000000) != 0xf00000000)
    abort ();
  if (f3 (0xf0000000) != 0xf00000000)
    abort ();
  if (f4 (0xf0000000) != 0xffffffff00000000)
    abort ();
  return 0;
}
