
/* { dg-options "-fgnu89-inline" } */
/* { dg-require-weak "" } */
/* { dg-require-alias "" } */




extern inline int foo (void) { return 23; }
int xxx(void) __asm__("" "xxx");
int xxx(void) { return 23; }
extern int foo (void) __attribute__ ((weak, alias ("xxx")));
