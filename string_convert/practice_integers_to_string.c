#include <stdio.h>

int main()
{
  char s1[50];

  float num1 = 98.415237f;
  int num2 = 0x3fce1920;

  sprintf(s1, "%f 0x%x", num1, num2);

  printf("%s\n", s1);

  return 0;
}