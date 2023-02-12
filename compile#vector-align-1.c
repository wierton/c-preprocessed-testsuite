
/* Check to make sure the alignment on vectors is not being lost. */

/* If some target has a Max alignment less than 128, please create
   a #ifdef around the alignment and add your alignment.  */






char x __attribute__((aligned(128),vector_size(2)));


int f[__alignof__(x) == 128?1:-1];
