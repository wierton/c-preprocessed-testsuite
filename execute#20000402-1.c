#include <limits.h>








typedef unsigned long ull;


#include <stdio.h>


void checkit(int);

main () {
    const ull a = 0x1400000000ULL;
    const ull b = 0x80000000ULL;
    const ull c = a/b;
    const ull d = 0x1400000000ULL / 0x80000000ULL;

    checkit ((int) c);
    checkit ((int) d);

    exit(0);
}

void checkit (int a)
{
  if (a != 40)
    abort();
}
