
/* PR middle-end/23484 */

extern void abort (void);
typedef long unsigned int size_t;
extern size_t strlen (const char *);
extern void *memcpy (void *, const void *, size_t);
extern void *mempcpy (void *, const void *, size_t);
extern void *memmove (void *, const void *, size_t);
extern int snprintf (char *, size_t, const char *, ...);
extern int memcmp (const void *, const void *, size_t);

#include "chk.h"

static char data[8] = "ABCDEFG";

int l1;

void
__attribute__((noinline))
test1 (void)
{
  char buf[8];

  /* All the checking calls in this routine have a maximum length, so
     object size checking should be done at compile time if optimizing.  */
  chk_calls = 0;

  __builtin___memset_chk (buf, 'I', sizeof (buf), __builtin_object_size (buf, 0));
  if (__builtin___memcpy_chk (buf, data, l1 ? sizeof (buf) : 4, __builtin_object_size (buf, 0)) != buf
      || memcmp (buf, "ABCDIIII", 8))
    abort ();

  __builtin___memset_chk (buf, 'J', sizeof (buf), __builtin_object_size (buf, 0));
  if (__builtin___mempcpy_chk (buf, data, l1 ? sizeof (buf) : 4, __builtin_object_size (buf, 0)) != buf + 4
      || memcmp (buf, "ABCDJJJJ", 8))
    abort ();

  __builtin___memset_chk (buf, 'K', sizeof (buf), __builtin_object_size (buf, 0));
  if (__builtin___memmove_chk (buf, data, l1 ? sizeof (buf) : 4, __builtin_object_size (buf, 0)) != buf
      || memcmp (buf, "ABCDKKKK", 8))
    abort ();

  __builtin___memset_chk (buf, 'L', sizeof (buf), __builtin_object_size (buf, 0));

  if (__builtin___snprintf_chk (buf, l1 ? sizeof (buf) : 4, 0, __builtin_object_size (buf, 0), "%d", l1 + 65536) != 5
      || memcmp (buf, "655\0LLLL", 8))
    abort ();






  if (chk_calls)
    abort ();
}

void
main_test (void)
{

  /* Object size checking is only intended for -O[s123].  */
  return;

  __asm ("" : "=r" (l1) : "0" (l1));
  test1 ();
}
