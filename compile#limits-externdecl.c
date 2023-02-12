
/* { dg-skip-if "Array too big" { "pdp11-*-*" } { "-mint32" } } */

/* { dg-require-effective-target int32plus } */
/* Inspired by the test case for PR middle-end/52640.  */

typedef struct
{
    char *value;
} REFERENCE;

/* Add a few "extern int Xxxxxx ();" declarations.  */

/* Add references to them, or GCC will simply ignore the extern decls.  */
REFERENCE references[] = {
  0
};