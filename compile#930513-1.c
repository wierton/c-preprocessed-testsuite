
/* The bit-field below would have a problem if __INT_MAX__ is too
   small.  */



struct s {
  int f1 : 26;
  int f2 : 8;
};

f (struct s *x)
{
  return x->f2++ == 0;
}
