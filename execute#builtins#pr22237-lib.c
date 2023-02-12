
extern void abort (void);

void *
memcpy (void *dst, const void *src, long unsigned int n)
{
  const char *srcp;
  char *dstp;

  srcp = src;
  dstp = dst;

  if (dst < src)
    {
      if (dst + n > src)
 abort ();
    }
  else
    {
      if (src + n > dst)
 abort ();
    }

  while (n-- != 0)
    *dstp++ = *srcp++;

  return dst;
}
