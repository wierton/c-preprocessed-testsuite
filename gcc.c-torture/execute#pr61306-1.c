

typedef int int32_t;





typedef unsigned int uint32_t;
/* Previous version of bswap optimization failed to consider sign extension
   and as a result would replace an expression *not* doing a bswap by a
   bswap.  */

__attribute__ ((noinline, noclone)) uint32_t
fake_bswap32 (uint32_t in)
{
  return ((uint32_t)( (((uint32_t)(in) & (uint32_t)0x000000ffUL) << 24) | (((uint32_t)(in) & (uint32_t)0x0000ff00UL) << 8) | (((uint32_t)(in) & (uint32_t)0x00ff0000UL) >> 8) | (( (int32_t)(in) & (int32_t)0xff000000UL) >> 24)));
}

int
main(void)
{
  if (sizeof (int32_t) * 8 != 32)
    return 0;
  if (sizeof (uint32_t) * 8 != 32)
    return 0;
  if (fake_bswap32 (0x87654321) != 0xffffff87)
    __builtin_abort ();
  return 0;
}
