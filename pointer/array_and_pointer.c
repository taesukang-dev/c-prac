#include <stdio.h>

int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  int i;

  for(i = 0; i < 10; i++){
    printf("arr[%d]의 주소 값 : %p \n", i, &arr[i]);
    // int 4byte만큼 주소값이 더해진다.
  }

  return 0;
}