
/* { dg-add-options stack_size } */

#include <string.h>

void *copy (void *o, const void *i, unsigned l)
{
  return memcpy (o, i, l);
}

main ()
{
  unsigned i;
  unsigned char src[(1 << 17)];
  unsigned char dst[(1 << 17)];

  for (i = 0; i < (1 << 17); i++)
    src[i] = (unsigned char) i, dst[i] = 0;

  (void) memcpy (dst, src, (1 << 17) / 128);

  for (i = 0; i < (1 << 17) / 128; i++)
    if (dst[i] != (unsigned char) i)
      abort ();

  (void) memset (dst, 1, (1 << 17) / 128);

  for (i = 0; i < (1 << 17) / 128; i++)
    if (dst[i] != 1)
      abort ();

  (void) memcpy (dst, src, (1 << 17));

  for (i = 0; i < (1 << 17); i++)
    if (dst[i] != (unsigned char) i)
      abort ();

  (void) memset (dst, 0, (1 << 17));

  for (i = 0; i < (1 << 17); i++)
    if (dst[i] != 0)
      abort ();

  (void) copy (dst, src, (1 << 17) / 128);

  for (i = 0; i < (1 << 17) / 128; i++)
    if (dst[i] != (unsigned char) i)
      abort ();

  (void) memset (dst, 0, (1 << 17));

  (void) copy (dst, src, (1 << 17));

  for (i = 0; i < (1 << 17); i++)
    if (dst[i] != (unsigned char) i)
      abort ();

  exit (0);
}
