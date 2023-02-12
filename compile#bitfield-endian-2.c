
/* { dg-require-effective-target int128 } */



typedef struct __attribute((scalar_storage_order ("little-endian")))
{
  __uint128_t t:124;
  __uint128_t t1:4;
}f;

f g(void)
{
  f t = {1, 2};
  return t;
}
