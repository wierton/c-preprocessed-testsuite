
/* { dg-require-effective-target alloca } */
/* { dg-skip-if "too many arguments in function call" { bpf-*-* } } */


x (a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y)
{
  foo (__builtin_alloca (8));
  return a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+y;
}
