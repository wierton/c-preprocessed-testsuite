
/* Test to make sure strcpy works correctly. */


const char a[] = "Hi!THE";

void f(char *a) __attribute__((noinline));
void f(char *a)
{
  __builtin_strcpy (a, "Hi!THE");
}


int main(void)
{
  int i;
  char b[sizeof(a)] = {};
  f(b);
  for(i = 0; i < sizeof(b); i++)
    {
      if (a[i] != b[i])
 __builtin_abort ();
    }
  return 0;
}
