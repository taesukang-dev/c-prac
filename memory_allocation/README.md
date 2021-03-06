## 메모리 할당

- 프로그램 : 프로그래머가 만든 프로그램 실행 파일

- 프로세스

  - CPU가 실행 파일에 있는 명령들을 실행할 수 있도록 운영체제가 실행 파일의 명령들을 읽어서 메모리에 재구성한 것

  - '실행 중인 프로그램'

  - 세그먼트의 집합으로 구성

- 세그먼트

  - 여러 가지 정보나 사용자가 입력한 데이터를 기억하는 메모리 공간

  - 코드 세그먼트, 데이터 세그먼트, 스택 세그먼트

<br>

### 정적 메모리 할당

- 컴파일러가 소스 코드를 기계어로 번역하는 시점에 변수에 크기에 맞게 메모리를 할당하는 것

- 프로그램이 실행될 때 메모리의 위치가 결정됨

- 프로그램 실행 중에 할당된 메모리의 크기는 변경이 불가!

<br>

### 변수가 메모리에서 유지되는 시간

- 전역 변수

  - 프로그램이 시작해서 종료할 떄까지 유지

  - 프로그램 실행 중에 전역 변수를 추가 혹은 삭제 불가

  - 프로세스의 데이터 세그먼트에 저장 됨

- 지역 변수

  - 함수가 호출될 때 메모리에 할당되었다가 함수가 끝나면 사라짐

  - 프로세스의 스텍 세그먼트에 저장됨

<br>

### 정적으로 할당된 메모리를 관리하는 법

- 지역 변수를 사용하려던 그 변수의 현재 주소를 알아야 한다.

- 각 지역 변수의 현재 주소를 기억하려면 지역 변수의 개수만큼 메모리가 더 필요하다

- 같은 함수에 선언한 지역 변수들을 하나의 메모리 그룹으로 관리 가능

- 지역 변수를 시작 위치 포인터와 끝 위치 포인터를 사용하여 관리 가능

- END 포인터가 필요한 이유가 무엇일까?
  - 다음에 호출될 함수의 메모리 시작 위치를 결정하기 위해

<br>

### 스택에 대하여

- 스택은 자료구조의 한 종류

- 두개의 포인터로 많은 양의 데이터를 효과적으로 관리하는 이론

- 베이스 포인터(start pointer)를 기준으로 데이터를 추가할 때마다 순서대로 데이터를 쌓아 올림

- 스택 포인터로 새로운 데이터가 추가될 위치를 가리킴

<br>

<img src="https://blog.kakaocdn.net/dn/brh2mI/btro311mN9J/B8x3tkfPAVhL9GXkuryd5K/img.png">

<br>

### 컴파일러가 스택에 할당된 변수를 사용하는 원리 (이걸로 안함)

- c 언어 컴파일러는 지역 변수가 선언된 순서대로 메모리를 할당

- 최근에 저장된 스택 포인터 바로 아래의 데이터 부터 차례대로 꺼낼 수 있다.

<br>

### 베이스 포인터를 사용하여 스택에 할당된 지역 변수 사용하기 (이걸로 함)

- 스택 메모리도 간접 주소 지정 방식(포인터) 개념을 이용하여 값을 읽거나 저장할 수 있다.

<br>

### 스택 프레임

- 스택 프레임 : 함수를 호풀할 때 일어나는 스택의 변화

- 스택 프레임은 컴파일러가 C 언어 코드를 기계어로 번역하는 시점에 결정됨

- 지역 변수를 추가 및 삭제하거나 배열 크기를 변경하려면 스택 프레임이 수정되어야 하기 때문에 C 언어 코드를 다시 컴파일 해야 함

<br>

### 정적 메모리 할당의 한계

- 프로세스 안에서 지역 변수가 저장되는 기본 스택 메모리 크기는 1mb

- 단일 변수의 크기가 1mb를 넘는 경우에 오류 메세지를 출력

- 함수 내의 모든 변수의 크기를 합산하여 1mb 를 넘는 경우에 프로그램 실행 시 오류 발생

<br>

## 동적 메모리 할당

- 원하는 시점에 원하는 크기만큼 힙에 메모리 할당 가능

- 메모리 사용이 끝나면 언제든지 할당한 메모리 해제 가능

- Giga Byte 단위까지 할당 가능

- C 표준 함수인 malloc 함수를 사용해서 메모리 할당 가능

- 할당된 메모리 주소를 받는 시점에 미리 형 변환하여 사용

<br>

### free 함수로 할당된 메모리 해제하기

- 힙에 할당된 메모리는 프로그램이 끝날 떄 까지 자동 해제되지 않음

- free 함수를 이용하여 명시적으로 메모리 해제

- malloc, free 함수가 선언된 malloc.h 파일을 포함해야 함

```c
#include <stdio.h>
#include <stdlib.h> // malloc, free 함수를 사용하기 위해 추가

void main()
{
  char *p_name;
  p_name = (char *)malloc(32); // 32byte 메모리를 동적 할당
  if(p_name != NULL){ // 메모리 할당에 성공
    printf("Your name : ");
    gets(p_name);
    printf("Hi ~ %s \n", p_name);
    free(p_name)
  } else {
    printf("Memory allocation error!!"); // 메모리 할당에 실패!
  }
}
```

<br>

### 동적 메모리 할당의 장단점

- 장점

  - 스택에 비해 큰 크기의 메모리 할당 가능

  - 메모리를 할당하고 해제하는 시점을 지정 가능

  - 할당되는 메모리의 크기를 프로그램 실행 중에 변경 가능

- 단점

  - 코드가 복잡해짐

  - 작은 메모리를 사용할 때에는 비효율 적

<br>

### 배열과 비슷한 형식으로 동적 메모리 사용하기

<img src="https://blog.kakaocdn.net/dn/bhdd7j/btroSs7YICn/jBY7LX9e7jIm3XFom8T4qk/img.png">

```c
int *p = (int *)malloc(sizeof(int)*3); // 12 byte 동적 할당
short *p = (short *)malloc(sizeof(short)*6); // 12 byte 동적 할당
```
