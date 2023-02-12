
/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */



unsigned int x0 = 0;

typedef struct {
  unsigned int field1 : 20;
  unsigned int field2 : 12;
} XX;

static XX yy;

static void foo (void)
{
  yy.field1 = (unsigned int ) (&x0);
}
