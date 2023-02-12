
static char newshuffle[256 + 16] = {
  0x0f, 0x08, 0x05, 0x07, 0x0c, 0x02, 0x0e, 0x09, 0x00, 0x01, 0x06, 0x0d,
    0x03, 0x04, 0x0b, 0x0a, 0x02, 0x0c, 0x0e, 0x06, 0x0f, 0x00, 0x01, 0x08,
    0x0d, 0x03, 0x0a, 0x04, 0x09, 0x0b, 0x05, 0x07, 0x05, 0x02, 0x09, 0x0f,
    0x0c, 0x04, 0x0d, 0x00, 0x0e, 0x0a, 0x06, 0x08, 0x0b, 0x01, 0x03, 0x07,
    0x0f, 0x0d, 0x02, 0x06, 0x07, 0x08, 0x05, 0x09, 0x00, 0x04, 0x0c, 0x03,
    0x01, 0x0a, 0x0b, 0x0e, 0x05, 0x0e, 0x02, 0x0b, 0x0d, 0x0a, 0x07, 0x00,
    0x08, 0x06, 0x04, 0x01, 0x0f, 0x0c, 0x03, 0x09, 0x08, 0x02, 0x0f, 0x0a,
    0x05, 0x09, 0x06, 0x0c, 0x00, 0x0b, 0x01, 0x0d, 0x07, 0x03, 0x04, 0x0e,
    0x0e, 0x08, 0x00, 0x09, 0x04, 0x0b, 0x02, 0x07, 0x0c, 0x03, 0x0a, 0x05,
    0x0d, 0x01, 0x06, 0x0f, 0x01, 0x04, 0x08, 0x0a, 0x0d, 0x0b, 0x07, 0x0e,
    0x05, 0x0f, 0x03, 0x09, 0x00, 0x02, 0x06, 0x0c, 0x05, 0x03, 0x0c, 0x08,
    0x0b, 0x02, 0x0e, 0x0a, 0x04, 0x01, 0x0d, 0x00, 0x06, 0x07, 0x0f, 0x09,
    0x06, 0x00, 0x0b, 0x0e, 0x0d, 0x04, 0x0c, 0x0f, 0x07, 0x02, 0x08, 0x0a,
    0x01, 0x05, 0x03, 0x09, 0x0b, 0x05, 0x0a, 0x0e, 0x0f, 0x01, 0x0c, 0x00,
    0x06, 0x04, 0x02, 0x09, 0x03, 0x0d, 0x07, 0x08, 0x07, 0x02, 0x0a, 0x00,
    0x0e, 0x08, 0x0f, 0x04, 0x0c, 0x0b, 0x09, 0x01, 0x05, 0x0d, 0x03, 0x06,
    0x07, 0x04, 0x0f, 0x09, 0x05, 0x01, 0x0c, 0x0b, 0x00, 0x03, 0x08, 0x0e,
    0x02, 0x0a, 0x06, 0x0d, 0x09, 0x04, 0x08, 0x00, 0x0a, 0x03, 0x01, 0x0c,
    0x05, 0x0f, 0x07, 0x02, 0x0b, 0x0e, 0x06, 0x0d, 0x09, 0x05, 0x04, 0x07,
    0x0e, 0x08, 0x03, 0x01, 0x0d, 0x0b, 0x0c, 0x02, 0x00, 0x0f, 0x06, 0x0a,
    0x09, 0x0a, 0x0b, 0x0d, 0x05, 0x03, 0x0f, 0x00, 0x01, 0x0c, 0x08, 0x07,
    0x06, 0x04, 0x0e, 0x02, 0x03, 0x0e, 0x0f, 0x02, 0x0d, 0x0c, 0x04, 0x05,
    0x09, 0x06, 0x00, 0x01, 0x0b, 0x07, 0x0a, 0x08,
};
void newpassencrypt (char *, char *, char *);
void
newpassencrypt (char *old, char *new, char *out)
{
  char *p, *bx;
  char copy[8];
  int i, di, ax;
  char cl, dl, ch;
  for (i = 0; i < 16; i++)
    {
      for (bx = old + 7; bx > old; bx--)
        {
          *bx = ((bx[-1] >> 4) & 0x0f) | ((*bx) << 4);
        }
      for (di = 0; di < 16; di++)
        {
          if (newshuffle[di + 0x100] & 1)
            ch = ((copy[newshuffle[di + 0x100] / 2] >> 4) & 0x0f);
          else
            ch = copy[newshuffle[di + 0x100] / 2] & 0x0f;
          out[di / 2] |= ((di & 1) ? ch << 4 : ch);
        }
      memcpy (copy, out, 8);
    }
}
