# 포인터
## 메모리 주소와 주소연산자 "&"
### 주소(address)
 - 메모리 공간은 바이트마다 고유한 주소가 존재
 - 메모리 주소는 저장 장소인 변수 이름과 함께 기억 장소를 참조하는 또 다른 방법
### 주소연산자 &(ampersand)
 - &가 피연산자인 변수의 메모리 주소를 반환
 - 변수의 주소값은 형식제어문자 %u 또는 %d로 출력
 - 16진수로 출력하려면 형식제어문자 %p 사용
 ```c
 #include <stdio.h>
 
 int main(void)
 {
  int input;
  
  printf("정수 입력: ");
  scanf("%d", &input);
  printf("입력값: %d\n", input);
  printf("주소값: %u(십진수), %p(16진수)\n", &input, &input);
  printf("주소값: %d(십진수), %#p(16진수)\n", &input, &input);
  printf("주소값 크기: %d\n", sizeof(&input));
  
  return 0;
 }
 ```
 
## 포인터 변수 선언
#### 자료형\*변수이름
### 주소 저장 변수
 - 주소연산식 &data는 포인터 변수(pointer variable)에 저장하여 사용
 - 포인터 변수는 주소값을 저장하는 변수
 - 포인터 변수는 변수 선언에서 자료형 뒤에 "*(asterisk)"를 사용
 - 다음 변수 선언에서 ptrint, ptrshort, ptrchar, ptrdouble은 모두 포인터 변수이며 간단히 포인터라고도 부름
 - 변수 자료형에 따라 그 변수의 주소를 저장하는 포인터의 자료형도 다름
 ```c
 int *ptrint;
 short *ptrshort;
 char *prtchar;
 double *prtdouble;
 ```
 보다는 전부
 ```
 int *ptrint;
 ```
 
 ## 포인터에 주소값 저장저장
 ### int \*print= &data;
 - “포인터 변수 ptrint는 변수 data 를 가리킨다” 또는 “참조(reference)한다”라고 표현
 - 포인터 변수는 가리키는 변수의 종류에 관계없이 크기가 모두 4바이트
```c
  #include <stdio.h>
 
 int main(void)
 {
  
  int data = 100;
  int *print;
  
  ptrint = &data;
  printf("십진수 주소값: %u\n", ptrint);
  
  printf("포인터 변수의 크기: %d\n", sizeof (ptrint));
  
  return 0;
  
}
```

## 포인터 선언과 NULL 포인터
### 여러 포인터 선언
여러 개의 포인터 변수를 한 번에 선언하기 위해서는 다음과 같이 변수마다 \*를 앞에 기술
```c
int *ptr1, *ptr2, *ptr3;
```
### NULL 저장
특별한 초기값이 없는 경우에 NULL로 초기값을 저장
```c
int *ptr = NULL;
```
### NULL
- 헤더 파일 stdio.h에 다음과 같이 정의되어 있는 포인터 상수로서 0번지의 주소값을 의미
-  (void *)는 아직 결정되지 않은 자료형의 주소
```c
#define NULL ((void(*)0)
```

## 간접 연산자 \*
### \*포인터
- 포인터 변수가 가리키고 있는 변수를 참조하려면 간접연산자(indirection operator) \*를 사용
- int \*ptrint = &data;
(위 선언으로 포인터 ptrint가 가리키는 변수가 data라면 \*ptrint은 변수 data를 의미)
```c
int data = 100;
int *ptrint = &data;
printf("간접 참조 출력: %d %c\n", *ptrint, *ptrchar);

*ptrint = 200;
ptrint("직접 참조 출력: %d %c\n", data, ch);
```
```c
 #include <stdio.h>
 
 int main(void)
 {
  int data =100;
  char ch = 'A';
  int *ptrint = &data;
  char *ptrchar = &ch;
  printf("간접 참조 출력: %d %c\n", *ptrint, *ptrchar);
  
  *ptrint =200;
  *ptrchar = 'B';
  printf("직접 참조 출력: %d %c\n", data ch);
  
  return 0;
  
}
```

## 포인터 변수의 연산
### 주소 연산
 - 포인터 변수는 간단한 더하기와 뺄셈 연산으로 주소를 수정
 - 포인터의 연산은 절대적인 주소의 계산이 아니며, 포인터가 가리키는 변수 크기에 비례한 연산
```c
#include <stdio.h>
 
 int main(void)
 {
  char *pc = (char *)100; //가능하나 잘 이용하지 않음
  int *pi = (int *)100; //가능하나 잘 이용하지 않음
  double *pd = (double *)100; //가능하나 잘 이용하지 않음
  //double *pd = 100;
  
  printf("%u %u %u\n", pc-1, pc, pc+1);
  printf("%u %u %u\n", pi-1, pi, pi+1);
  printf("%u %u %u\n", pd-1, pd, pd+1);
  
  return 0;
}
```
## 포인터 변수의 이동
### 배열 원소의 참조
 - 포인터 pa에 &a[0]를 저장하면 연산식 \*(pa+i)으로 배열 원소를 참조
 - 특히 포인터 pa로도 배열과 같이 첨자를 이용하여 pa[i]로 배열 원소를 참조
```c
int a[4] = {1, 3, 6};
int *pa = &a[0];

printf("%d %d %d\n", *(pa), *(pa+1), *(pa+2));  //1, 3, 6 출력
printf("%d %d %d\n", pa[0], pa[1], pa[2]);  //1, 3, 6 출력
```

## 참조 연산자의 다양한 연산
간접연산자와 증감연산자의 이용
 - 참조연산자 \*의 우선순위는 ++p의 전위 증감연산자와 같고, 괄호나 p++의 후위 증 감연산자보다 낮음
 - 그러므로 연산식 \*p++는 \*(p++)를 의미
 ( \*p++는 포인터 p가 가리키는 변수를 참조하고 p의 주소를 1 증가)
 ( 반면 (\*p)++는 포인터 p가 가 리키는 변수를 참조하고 그 값을 1 증가시키는 연산식)
