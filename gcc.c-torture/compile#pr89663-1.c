
/* PR middle-end/89663 */
/* { dg-require-effective-target non_strict_prototype } */

int irint ();
long lrint ();
long long llrint ();
int iround ();
long lround ();
long long llround ();
int iceil ();
long lceil ();
long long llceil ();
int ifloor ();
long lfloor ();
long long llfloor ();
int irintf ();
long lrintf ();
long long llrintf ();
int iroundf ();
long lroundf ();
long long llroundf ();
int iceilf ();
long lceilf ();
long long llceilf ();
int ifloorf ();
long lfloorf ();
long long llfloorf ();
int irintl ();
long lrintl ();
long long llrintl ();
int iroundl ();
long lroundl ();
long long llroundl ();
int iceill ();
long lceill ();
long long llceill ();
int ifloorl ();
long lfloorl ();
long long llfloorl ();

void
foo (long long *p)
{
  int n = 0;

  p[n++] = irint (1);
  p[n++] = lrint (1);
  p[n++] = llrint (1);
  p[n++] = iround (1);
  p[n++] = lround (1);
  p[n++] = llround (1);
  p[n++] = iceil (1);
  p[n++] = lceil (1);
  p[n++] = llceil (1);
  p[n++] = ifloor (1);
  p[n++] = lfloor (1);
  p[n++] = llfloor (1);
  p[n++] = irintf (1);
  p[n++] = lrintf (1);
  p[n++] = llrintf (1);
  p[n++] = iroundf (1);
  p[n++] = lroundf (1);
  p[n++] = llroundf (1);
  p[n++] = iceilf (1);
  p[n++] = lceilf (1);
  p[n++] = llceilf (1);
  p[n++] = ifloorf (1);
  p[n++] = lfloorf (1);
  p[n++] = llfloorf (1);
  p[n++] = irintl (1);
  p[n++] = lrintl (1);
  p[n++] = llrintl (1);
  p[n++] = iroundl (1);
  p[n++] = lroundl (1);
  p[n++] = llroundl (1);
  p[n++] = iceill (1);
  p[n++] = lceill (1);
  p[n++] = llceill (1);
  p[n++] = ifloorl (1);
  p[n++] = lfloorl (1);
  p[n++] = llfloorl (1);
}
