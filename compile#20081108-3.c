
/* Test boolean conversion of an overflowing integer return value does
   not lead to an ICE.  */

_Bool f(void) { return 0x7fffffff + 1; }
