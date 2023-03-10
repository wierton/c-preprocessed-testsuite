#include <limits.h>





feq (float x, float y)
{
  if (x == y)
    return 13;
  else
    return 140;
}

fne (float x, float y)
{
  if (x != y)
    return 13;
  else
    return 140;
}

flt (float x, float y)
{
  if (x < y)
    return 13;
  else
    return 140;
}

fge (float x, float y)
{
  if (x >= y)
    return 13;
  else
    return 140;
}

fgt (float x, float y)
{
  if (x > y)
    return 13;
  else
    return 140;
}

fle (float x, float y)
{
  if (x <= y)
    return 13;
  else
    return 140;
}

float args[] =
{
  0.0F,
  1.0F,
  -1.0F,
  3.40282346638528859811704183484516925e+38F,
  1.17549435082228750796873653722224568e-38F,
  0.0000000000001F,
  123456789.0F,
  -987654321.0F
};

int correct_results[] =
{
 13, 140, 140, 13, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 13, 140, 140, 13, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 13, 140, 140, 13, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 13, 140, 140, 13, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 13, 140, 140, 13, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 13, 140, 140, 13, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 140, 13, 13, 140,
 13, 140, 140, 13, 140, 13,
 140, 13, 140, 13, 13, 140,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 140, 13, 13, 140, 140, 13,
 13, 140, 140, 13, 140, 13,
};

int
main (void)
{
  int i, j, *res = correct_results;

  for (i = 0; i < 8; i++)
    {
      float arg0 = args[i];
      for (j = 0; j < 8; j++)
 {
   float arg1 = args[j];

   if (feq (arg0, arg1) != *res++)
     abort ();
   if (fne (arg0, arg1) != *res++)
     abort ();
   if (flt (arg0, arg1) != *res++)
     abort ();
   if (fge (arg0, arg1) != *res++)
     abort ();
   if (fgt (arg0, arg1) != *res++)
     abort ();
   if (fle (arg0, arg1) != *res++)
     abort ();
 }
    }
  exit (0);
}
