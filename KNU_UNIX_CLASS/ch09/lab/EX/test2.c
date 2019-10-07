#include <string.h>
#include <stdio.h>

int main(void)
{
  const char str[256] = "sleep 5 & echo Hello & sleep 5; echo Hello";
  size_t length = strlen(str);

  const char* s1 = str;
  const char* s2;
  const char delim = '&';

  while(s1 < str+length)
  {
    s2 = strchr(s1, delim);
    if(s2 == NULL)
    {
      s2 = &str[length]; // point at null term
    }
    else
    {
      s2++; // point at space
    }
    printf("%.*s\n", s2-s1, s1); // print (s2-s1) characters
    s1 = s2+1; // point at next char after space, or 1 past null term
  }
}
