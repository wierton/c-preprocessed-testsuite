
/* { dg-skip-if "requires io" { freestanding } }  */

#include <stdio.h>
#include <stdlib.h>


int
main (void)
{




  fprintf (
 stdout
 , "hello"); if (fprintf (
 stdout
 , "hello") != 5) abort ();;
  fprintf (
 stdout
 , "hello\n"); if (fprintf (
 stdout
 , "hello\n") != 6) abort ();;
  fprintf (
 stdout
 , "a"); if (fprintf (
 stdout
 , "a") != 1) abort ();;
  fprintf (
 stdout
 , ""); if (fprintf (
 stdout
 , "") != 0) abort ();;
  fprintf (
 stdout
 , "%s", "hello"); if (fprintf (
 stdout
 , "%s", "hello") != 5) abort ();;
  fprintf (
 stdout
 , "%s", "hello\n"); if (fprintf (
 stdout
 , "%s", "hello\n") != 6) abort ();;
  fprintf (
 stdout
 , "%s", "a"); if (fprintf (
 stdout
 , "%s", "a") != 1) abort ();;
  fprintf (
 stdout
 , "%s", ""); if (fprintf (
 stdout
 , "%s", "") != 0) abort ();;
  fprintf (
 stdout
 , "%c", 'x'); if (fprintf (
 stdout
 , "%c", 'x') != 1) abort ();;
  fprintf (
 stdout
 , "%s\n", "hello\n"); if (fprintf (
 stdout
 , "%s\n", "hello\n") != 7) abort ();;
  fprintf (
 stdout
 , "%d\n", 0); if (fprintf (
 stdout
 , "%d\n", 0) != 2) abort ();;
  return 0;
}
