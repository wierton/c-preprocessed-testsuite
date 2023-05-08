
/* PR target/100305 */

typedef double v2df __attribute__((vector_size(16)));


void consume (void *);
v2df
foo (void)
{
  double x[4096 +2];
  consume (x);
  return (v2df) { x[4096], x[4096 + 1] };
}
