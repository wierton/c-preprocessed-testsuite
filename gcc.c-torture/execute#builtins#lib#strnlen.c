
typedef long unsigned int size_t;

extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
size_t
strnlen (const char *s, size_t n)
{
  size_t i;






  i = 0;
  while (s[i] != 0 && n--)
    i++;

  return i;
}
