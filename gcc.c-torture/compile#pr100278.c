

void a()
{



  register int b asm("eax");



  if (b)
    b = 1;
  for (; b;)
    ;
}
