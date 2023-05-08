
/* { dg-options "-fnon-call-exceptions" } */
/* With -fnon-call-exceptions 0 / 0 should not be eliminated.  */
/* { dg-additional-options "-DSIGNAL_SUPPRESS" { target { ! signal } } } */
/* { dg-additional-options "-mcheck-zero-division" { target { loongarch*-*-* } } } */
extern void abort (void);
extern void exit (int);



#include <signal.h>


void
sigfpe (int signum __attribute__ ((unused)))
{
  exit (0);
}



/* When optimizing, the compiler is smart enough to constant fold the
   static unset variables i and j to produce 0 / 0, but it can't
   eliminate the assignment to the global k.  */
static int i;
static int j;
int k __attribute__ ((used));

int
main ()
{

  signal (
         8
               , sigfpe);
  k = i / j;
  abort ();



}
