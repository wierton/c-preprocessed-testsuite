
/* Test built-in string functions with large sizes.  PR 78460.  */

typedef long unsigned int size_t;






volatile int v1, v2, v3, v4;
void *volatile vp1, *volatile vp2, *volatile vp3, *volatile vp4;

void
test_memchr (const void *a, int b)
{
  vp1 = __builtin_memchr (a, b, ((size_t) -1));
  vp2 = __builtin_memchr (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_memchr (a, b, ((unsigned int) -1));
  vp4 = __builtin_memchr (a, b, (((unsigned int) -1) >> 1));
}

void
test_memcmp (const void *a, const void *b)
{
  v1 = __builtin_memcmp (a, b, ((size_t) -1));
  v2 = __builtin_memcmp (a, b, (((size_t) -1) >> 1));
  v3 = __builtin_memcmp (a, b, ((unsigned int) -1));
  v4 = __builtin_memcmp (a, b, (((unsigned int) -1) >> 1));
}

void
test_memcpy (void *a, const void *b)
{
  vp1 = __builtin_memcpy (a, b, ((size_t) -1));
  vp2 = __builtin_memcpy (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_memcpy (a, b, ((unsigned int) -1));
  vp4 = __builtin_memcpy (a, b, (((unsigned int) -1) >> 1));
}

void
test_memmove (void *a, const void *b)
{
  vp1 = __builtin_memmove (a, b, ((size_t) -1));
  vp2 = __builtin_memmove (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_memmove (a, b, ((unsigned int) -1));
  vp4 = __builtin_memmove (a, b, (((unsigned int) -1) >> 1));
}

void
test_mempcpy (void *a, const void *b)
{
  vp1 = __builtin_mempcpy (a, b, ((size_t) -1));
  vp2 = __builtin_mempcpy (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_mempcpy (a, b, ((unsigned int) -1));
  vp4 = __builtin_mempcpy (a, b, (((unsigned int) -1) >> 1));
}

void
test_memset (void *a, int b)
{
  vp1 = __builtin_memset (a, b, ((size_t) -1));
  vp2 = __builtin_memset (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_memset (a, b, ((unsigned int) -1));
  vp4 = __builtin_memset (a, b, (((unsigned int) -1) >> 1));
}

void
test_stpncpy (char *a, const char *b)
{
  vp1 = __builtin_stpncpy (a, b, ((size_t) -1));
  vp2 = __builtin_stpncpy (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_stpncpy (a, b, ((unsigned int) -1));
  vp4 = __builtin_stpncpy (a, b, (((unsigned int) -1) >> 1));
}

void
test_strndup (const char *a)
{
  vp1 = __builtin_strndup (a, ((size_t) -1));
  vp2 = __builtin_strndup (a, (((size_t) -1) >> 1));
  vp3 = __builtin_strndup (a, ((unsigned int) -1));
  vp4 = __builtin_strndup (a, (((unsigned int) -1) >> 1));
}

void
test_strncasecmp (const char *a, const char *b)
{
  v1 = __builtin_strncasecmp (a, b, ((size_t) -1));
  v2 = __builtin_strncasecmp (a, b, (((size_t) -1) >> 1));
  v3 = __builtin_strncasecmp (a, b, ((unsigned int) -1));
  v4 = __builtin_strncasecmp (a, b, (((unsigned int) -1) >> 1));
}

void
test_strncat (char *a, const char *b)
{
  vp1 = __builtin_strncat (a, b, ((size_t) -1));
  vp2 = __builtin_strncat (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_strncat (a, b, ((unsigned int) -1));
  vp4 = __builtin_strncat (a, b, (((unsigned int) -1) >> 1));
}

void
test_strncmp (const char *a, const char *b)
{
  v1 = __builtin_strncmp (a, b, ((size_t) -1));
  v2 = __builtin_strncmp (a, b, (((size_t) -1) >> 1));
  v3 = __builtin_strncmp (a, b, ((unsigned int) -1));
  v4 = __builtin_strncmp (a, b, (((unsigned int) -1) >> 1));
}

void
test_strncpy (char *a, const char *b)
{
  vp1 = __builtin_strncpy (a, b, ((size_t) -1));
  vp2 = __builtin_strncpy (a, b, (((size_t) -1) >> 1));
  vp3 = __builtin_strncpy (a, b, ((unsigned int) -1));
  vp4 = __builtin_strncpy (a, b, (((unsigned int) -1) >> 1));
}
