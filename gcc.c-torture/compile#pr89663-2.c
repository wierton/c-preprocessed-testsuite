
/* PR middle-end/89663 */
/* { dg-require-effective-target indirect_calls } */
/* { dg-require-effective-target non_strict_prototype } */

int irint (double);
long lrint (double);
long long llrint (double);
int iround (double);
long lround (double);
long long llround (double);
int iceil (double);
long lceil (double);
long long llceil (double);
int ifloor (double);
long lfloor (double);
long long llfloor (double);
int irintf (float);
long lrintf (float);
long long llrintf (float);
int iroundf (float);
long lroundf (float);
long long llroundf (float);
int iceilf (float);
long lceilf (float);
long long llceilf (float);
int ifloorf (float);
long lfloorf (float);
long long llfloorf (float);
int irintl (long double);
long lrintl (long double);
long long llrintl (long double);
int iroundl (long double);
long lroundl (long double);
long long llroundl (long double);
int iceill (long double);
long lceill (long double);
long long llceill (long double);
int ifloorl (long double);
long lfloorl (long double);
long long llfloorl (long double);

void
foo (long long *p)
{
  int (*fn) (int);
  int n = 0;

  fn = (int (*) (int)) irint; p[n++] = fn (1);
  fn = (int (*) (int)) lrint; p[n++] = fn (1);
  fn = (int (*) (int)) llrint; p[n++] = fn (1);
  fn = (int (*) (int)) iround; p[n++] = fn (1);
  fn = (int (*) (int)) lround; p[n++] = fn (1);
  fn = (int (*) (int)) llround; p[n++] = fn (1);
  fn = (int (*) (int)) iceil; p[n++] = fn (1);
  fn = (int (*) (int)) lceil; p[n++] = fn (1);
  fn = (int (*) (int)) llceil; p[n++] = fn (1);
  fn = (int (*) (int)) ifloor; p[n++] = fn (1);
  fn = (int (*) (int)) lfloor; p[n++] = fn (1);
  fn = (int (*) (int)) llfloor; p[n++] = fn (1);
  fn = (int (*) (int)) irintf; p[n++] = fn (1);
  fn = (int (*) (int)) lrintf; p[n++] = fn (1);
  fn = (int (*) (int)) llrintf; p[n++] = fn (1);
  fn = (int (*) (int)) iroundf; p[n++] = fn (1);
  fn = (int (*) (int)) lroundf; p[n++] = fn (1);
  fn = (int (*) (int)) llroundf; p[n++] = fn (1);
  fn = (int (*) (int)) iceilf; p[n++] = fn (1);
  fn = (int (*) (int)) lceilf; p[n++] = fn (1);
  fn = (int (*) (int)) llceilf; p[n++] = fn (1);
  fn = (int (*) (int)) ifloorf; p[n++] = fn (1);
  fn = (int (*) (int)) lfloorf; p[n++] = fn (1);
  fn = (int (*) (int)) llfloorf; p[n++] = fn (1);
  fn = (int (*) (int)) irintl; p[n++] = fn (1);
  fn = (int (*) (int)) lrintl; p[n++] = fn (1);
  fn = (int (*) (int)) llrintl; p[n++] = fn (1);
  fn = (int (*) (int)) iroundl; p[n++] = fn (1);
  fn = (int (*) (int)) lroundl; p[n++] = fn (1);
  fn = (int (*) (int)) llroundl; p[n++] = fn (1);
  fn = (int (*) (int)) iceill; p[n++] = fn (1);
  fn = (int (*) (int)) lceill; p[n++] = fn (1);
  fn = (int (*) (int)) llceill; p[n++] = fn (1);
  fn = (int (*) (int)) ifloorl; p[n++] = fn (1);
  fn = (int (*) (int)) lfloorl; p[n++] = fn (1);
  fn = (int (*) (int)) llfloorl; p[n++] = fn (1);
}
