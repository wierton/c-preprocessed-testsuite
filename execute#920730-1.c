
/* 920730-1.c */
#include <limits.h>

f1()
{
 int b=
      (-0x7fffffff - 1)
             ;
 return b>=
          (-0x7fffffff - 1)
                 ;
}

f2()
{
 int b=
      (-0x7fffffff - 1)
             +1;
 return b>= (unsigned)(0x7fffffff +2);
}

f3()
{
 int b=0x7fffffff;
 return b>=0x7fffffff;
}

f4()
{
 int b=-1;
 return b>=
          (0x7fffffff * 2U + 1U)
                  ;
}

main ()
{
 if((f1()&f2()&f3()&f4())!=1)
  abort();
  exit(0);
}
