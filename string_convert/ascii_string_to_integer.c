#include <stdio.h>
#include <stdlib.h> // atoi 함수가 선언된 헤더 파일

int main()
{
  char *s1 = "283"; // 문자열
  int num1;

  num1 = atoi(s1); 
  // 문자열을 정수로 변환하여 num1에 할당
  // atoi는 처음부터 숫자가 포함되어 있어야함, 아니면 0을 반환

  printf("%d \n", num1);

  return 0;
}