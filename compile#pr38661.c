
/* We used to ICE because we would wrap INT_MAX
   into INT_MIN while doing the switch converison. */

const char *func(int val) {
 switch (val) {
   case 0x7fffffff: return "foo";
   default: return "";
 }
}
