


void foo (unsigned long *res, unsigned long in)
{
  for (unsigned long a = 0; a < 98; a++)
    for (unsigned long b = 0; b < 98; b++)
      for (unsigned long c = 0; c < 98; c++)
        for (unsigned long d = 0; d < 98; d++)
          for (unsigned long e = 0; e < 98; e++)
            for (unsigned long f = 0; f < 98; f++)
              for (unsigned long g = 0; g < 98; g++)
                *res += a * in;
}
