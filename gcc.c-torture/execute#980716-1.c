#include <stdarg.h>


void
stub(int num, ...)
{
    va_list ap;
    char *end;
    int i;

    for (i = 0; i < 2; i++) {
        
       __builtin_va_start(
       ap
       ,
       num
       )
                        ;
        while ( 1 ) {
            end = 
                 __builtin_va_arg(
                 ap
                 ,
                 char *
                 )
                                   ;
            if (!end) break;
        }
        
       __builtin_va_end(
       ap
       )
                 ;
    }
}

int
main()
{
    stub(1, "ab", "bc", "cx", (char *)0);
    exit (0);
}
