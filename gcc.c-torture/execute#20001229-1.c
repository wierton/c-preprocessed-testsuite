
/* This testcase originally provoked an unaligned access fault on Alpha.

   Since Digital Unix and Linux (and probably others) by default fix
   these up in the kernel, the failure was not visible unless one 
   is sitting at the console examining logs.

   So: If we know how, ask the kernel to deliver SIGBUS instead so
   that the test case visibly fails.  */
void foo(char *a, char *b) { }

void showinfo()
{
    char uname[33] = "", tty[38] = "/dev/";
    foo(uname, tty);
}

int main()
{
  showinfo ();
  exit (0);
}
