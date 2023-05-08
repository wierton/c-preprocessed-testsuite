
/* PR rtl-optimization/39588 */
/* Testcase by Olivier ROUSSEL <olivier.roussel@cril.univ-artois.fr> */



void init_clause(int *literals, int size, int *lits)
{
  int i;
  for(i=0; i < size; i++)
    lits[i] = ((literals[i]<0)?(((-literals[i])<<1)|1):(literals[i]<<1));
}
