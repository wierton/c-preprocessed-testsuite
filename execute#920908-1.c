
/* REPRODUCED:RUN:SIGNAL MACHINE:mips OPTIONS: */

#include <stdarg.h>


typedef struct{int A;}T;

T f(int x,...)
{
va_list ap;
T X;

__builtin_va_start(
ap
,
x
)
             ;
X=
 __builtin_va_arg(
 ap
 ,
 T
 )
             ;
if(X.A!=10)abort();
X=
 __builtin_va_arg(
 ap
 ,
 T
 )
             ;
if(X.A!=20)abort();

__builtin_va_end(
ap
)
         ;
return X;
}

main()
{
T X,Y;
int i;
X.A=10;
Y.A=20;
f(2,X,Y);
exit(0);
}
