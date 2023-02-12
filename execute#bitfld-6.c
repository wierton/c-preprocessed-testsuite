
/* { dg-require-effective-target int32plus } */
union U
{
  const int a;
  unsigned b : 20;
};

static union U u = { 0x12345678 };

/* Constant folding used to fail to account for endianness when folding a
   union.  */

int
main (void)
{


  return u.b - 0x45678;




  return 0;
}
