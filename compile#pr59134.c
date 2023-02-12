
/* { dg-do compile } */

extern void* malloc(long unsigned int) __attribute__((malloc));

typedef struct {
  char pad;
  int arr[0];
} __attribute__((packed)) str;

str *
foo (void)
{
  str *s = malloc (sizeof (str) + sizeof (int));
  s->arr[0] = 0x12345678;
  return s;
}
