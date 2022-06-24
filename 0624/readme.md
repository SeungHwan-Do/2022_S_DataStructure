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
#define NULL ((void*)0)
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
 <br>( \*p++는 포인터 p가 가리키는 변수를 참조하고 p의 주소를 1 증가)
 <br>( 반면 (\*p)++는 포인터 p가 가 리키는 변수를 참조하고 그 값을 1 증가시키는 연산식)
```c
#include <stdio.h>
 
 int main(void)
 {
  int a[4] = {1, 3, 6, 8};
  int *pa = &a[0];
  
  printf("%d %d %d %d\n", *(pa), *(pa+1), *(pa+2), *(pa+3)); // 1, 3, 6, 8
  printf("%d %d %d %d\n", pa[0], pa[1], pa[2], pa[3]); // 1, 3, 6, 8
  printf("%d ", ++*pa); //++(*pa) // 2: 값에다가 연산
  printf("%d ", *++pa); //*(++pa) // 3: 연산된 주소
  printf("%d ", *pa++); //*(pa++) // 3: 연산된 주소
  printf("%d ", --*pa++); //--(*(pa++)) //5: 주소 연산 후 값 연산
  printf("%d\n ", (*pa)--); // 8 : 값 연산
  printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]); // 계산 후 변화 출력 2 3 5 7
  
  return 0;
}
```

## 포인터 변수의 형변환
### 명시적 형변환
 - 포인터 변수는 동일한 자료형끼리만 대입이 가능
 - 만일 대입문에서 포인터의 자료형이 다르면 경고가 발생
 - 포인터 변수는 자동으로 형변환(type cast)이 불가능하며 필요하면 명시적으로 형변환을 수행가능
 - \*pi로 수행하는 간접 참조는 pi가 가리키는 주소에서부터 4바이트 크기의int형 자료를 참조한다는 것을 의미
```c
char c[4] = {'A', '\0', '\0', '\0'}; // 문자 'A'코드값 : 65
int *pi = (int *) &c[0];
printf("%d %c\n", (int) *pi, (char) *pi); //정수값 65와 문자 'A'가 출력
```
## 다중 포인터
### 이중 포인터
 - 포인터 변수의 주소값을 갖는 변수
 - 다시 이중 포인터의 주소값을 갖는 변수는 삼중 포인터
 - 이러한 포인터의 포인터를 모두 다중 포인터
 - 변수 선언에서 \*를 여러 번 이용하여 다중 포인터 변수를 선언
```c
int i = 20;
int *pi = &i;
int **dpi = &pi;
```
```c
#include <stdio.h>
 
 int main(void)
 {
  int i = 20;
  int *pi = &i;
  int **dpi = &pi;
  
  printf("%p %p %p\n", &i, pi, *dpi);
  
  *pi = i+2; // i = i+2와 같음
  printf("%p %p %p\n", i, *pi, **dpi);

  **dpi = *pi + 2;
  printf("%p %p %p\n", i, *pi, **dpi);
  
  return 0;
}
```
## 포인터 배열
### 여러 포인터 모임
 - 주소값을 저장하는 포인터를 배열 원소로 하는 배열
 - 일반 배열 선언에서 변수 이름 앞에 \*를 붙이면 포인터 배열 변수 선언
### 포인터 배열 선언 시 초기값을 지정
 - 문장 double \*dary[5] = {NULL};
#### 자료형\*변수이름[배열크기];

## 포인터 배열 이용
```c
#include <stdio.h>
 
 int main(void)
 {
 //포인터 배열 변수 선언
 int *pary[3] = { NULL };
 int i, a=10, b=20, c=30;
 
 pary[0] = &a;
 pary[1] = &b;
 pary[2] = &c;
 for(i = 0; i < 3; i++ )
  printf("pAry[%d] = %d\n", i, *part[i]);
  
 for ( i = 0 ; i < 3; i++)
 {
  scanf("%d, pary[i]); // pari[i] 자체가 주소값이므로 &없이 그대로 기술한다.
  printf("%d, %d, %d\n", a, b, c); // 반복 순서대로 첫 번째 입력값은 a에, 다음 순으로 각각 b,c 에 각각 저장된다.
 }
 
 return 0;
}
```
## 배열 포인터
### 배열 주소를 저장
 - int 형인 일차원 배열 int a[]의 주소는 (int \*)인 포인터 변수에 저장
 - 열이 4인 이차원 배열 ary[][4]의 주소를 저장하려면 -> 포인터 변수 ptr을 문장 int (\*ptr)[4];로 선언
 일차원 배열 포인터 선언
 ```c
 원소자료형*변수이름;
 변수이름=배열이름; 또는
 원소자료형*변수이름 = 배열이름;
 ```
 ```c
 int a[] = {8, 2, 8, 1, 3};
 int *p = a;
 ```
 2차원 배열 포인터 선언
 ```c
 원소자료형 (*변수이름)[배열 열 크기];
 변수이름 = 배열이름; 또는
 원소자료형(*변수이름)[배열 열 크기] = 배열이름;
 ```
 ```c
 int art[][4] = {5, 7, 6, 2, 7, 8, 1, 3};
 int (*ptr)[4] = ary; // 열이 4인 배열을 가리키는 포인터
 //int *ptr[4] = ary; // 포인터 배열
 ```
 
 ## 배열 포인터와 포인터 배열
 ### 배열 포인터
 `int (\*ptr)[4];`
 <br> 열이 4인 이차원 배열 포인터 선언 문장
 <br> 괄호(\*ptr)은 반드시 필요
 <br>변수 ptr은 포인터로 열의 수가 4인 이차원의 배열의 주소를 가질 수 있다.
 ### 포인터 배열
 `int \*ptr[4];`
 <br> 변수 ptr은 int형 변수의 주소를 저장할 수 있는 포인터 변수가 연속 4개인 배열이다.
 
 ## 배열 포인터 이용
 - 배열 이름 a는 포인터 상수
 - 변수 p는 포인터 변수
 - 배열 첫 원소를 참조하려면 \*\*ptr을 이용
 - 연산식 \*\*ptr++
 <br>  연산 우선순위에 따라 \*\*(ptr++)와 같으며
 <br>  현재 포인터가 가리키는 원소를 참조하고 다음 원소로 이동하는 연산
 ```c
 #include <stdio.h>
 
 int main(void)
 {
  int a[] = {8, 2, 8, 1, 3};
  int *p = a;
  
  int ary[][4] = {5, 7, 6, 2, 7, 8, 1, 3};
  int (*ptr)[4] = ary; //열이 4인 배열을 가리키는 포인터
  //int *ptr[4] = ary; // 포인터 배열
  
  printf("%2d, %2d\n", *(p+1), *(p+4));
  printf("%2d, %2d\n", p[0], p[4]);
  printf("sizeof(a) = %d, sizeof(p) = %d\n", sizeof(a), sizeof(p));
  
  printf("%2d, %2d\n", **ary, **ptr++);
  printf("%2d, %2d\n", **(ary+1), **(ptr++1));
  ptr = ary;
  printf("%2d, %2d\n", *(ary[1]+1), *(ptr[1]+1));
  printf("%2d, %2d\n", *(*(ary+1) + 3), *(*(ptr+1) + 3));
  printf("sizeof(ary) = %d, sizeof(ptr) = %d\n", sizeof(ary), sizeof(ptr));
  
  return 0; // 좀 이상한데?? 검증필요
}
```
## 일차원 배열과 포인터
### 배열 이름을 이용한 참조
 - 배열 score에서 배열 이름 score 자체가 배열 첫 원소의 주소값
### 일차원 배열에서 배열 원소와 주소값을 참조
![image](https://user-images.githubusercontent.com/79446573/175489982-057ab40a-112a-48a4-8f46-c0fbcfd51b50.png)
## 이차원 배열과 포인터
### 배열 이름과 행 이름으로 참조
```c
int td[][COL] = {{8, 5, 4}, {2, 7, 6}};
int i = 0, j = 0, cnt = 0;

printf("%d, %d, %d\n", sizeof(td), sizeof(td[0]), sizeof(td[1]));
printf("%u, %u, %u\n", td, td[0], td[1]);
printf("%u, %u\n", &td[0][0], &td[1][0]);

**td = 10; // td[0][0] = 10
*td[1] = 20; // td[1][0] = 20;
```
### 연산식(\*td+n)
 - 배열의 (n+1)번째 원소의 주소값
 - 역참조연산자를 이용한 연산식 \*(\*td+n)은 배열의 (n+1)번째 원소 자
```

 
