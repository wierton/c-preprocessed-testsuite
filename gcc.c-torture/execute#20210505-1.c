
/* PR target/100402 */
/* Testcase by Hannes Domani <ssbssa@yahoo.de> */

/* { dg-require-effective-target indirect_jumps } */

#include <setjmp.h>
#include <stdbool.h>


static jmp_buf buf;
static _Bool stop = 
                   0
                        ;

void call_func (void(*func)(void))
{
  func ();
}

void func (void)
{
  stop = 
        1
            ;
  longjmp (buf, 1);
}

int main (void)
{
  
 _setjmp (
 buf
 )
             ;

  while (!stop)
    call_func (func);

  return 0;
}
