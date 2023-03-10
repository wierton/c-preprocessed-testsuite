
/* { dg-add-options stack_size } */
/* { dg-require-stack-size "[dg-effective-target-value stack_size]*2" } */

void
bcopy1 (s, d, c)
     long long *s;
     long long *d;
     int c;
{
  int i;
  c = c / 8;
  for (i = 0; i < c; i++)
    d[i] = s[i];
}

void
bcopy2 (s, d, c)
     long *s;
     long *d;
     int c;
{
  int i;
  c = c / 4;
  for (i = 0; i < c; i++)
    d[i] = s[i];
}


void
bcopy3 (s, d, c)
     char *s;
     char *d;
     int c;
{
  long long z0, z1;
  int r = d - s;

  int i;

  c /= 16;

  z0 = *((long long *) s);
  s += 8;
  z1 = *((long long *) s);
  s += 8;
  for (i = 0; i < c; i++)
    {
      *(long long *)(s + r) = z0;
      z0 = *((long long *) s);
      s += 8;
      *(long long *)(s + r) = z1;
      z1 = *((long long *) s);
      s += 8;
    }
}







main ()
{
  long long s[16384 / 8];
  long long d[16384 / 8];
  int i;

  for (i = 1; i < 67108864 / 16384; i++)
    bcopy (s, d, 16384);
}
