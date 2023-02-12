
/* { dg-require-effective-target indirect_jumps } */

f(int*x){goto*(void*)(long int)(char)*x;}
