# 구조체와 공용체
## 구조체 개념
 - 연관성이 있는 서로 다른 개별적인 자료형의 변수들을 하나의 단위로 묶은 새로운 자료형
 - 연관된 멤버로 구성되는 통합 자료형으로 대표적인 유도 자료형
## 구조체 정의
### 키워드 struct 사용
 - 키워드 struct 다음에 구조체 태그 이름을 기술
 - 중괄호 사이에 원하는 멤버를 여러 개의 변수로 선언하는 구조
 - 변수 선언에서 이용될 새로운 구조체 자료형을 정의하는 구문
### 구조체 멤버
- 구조체를 구성하는 하나하나의 항목
- 초기값 대입 불가능
```c
struct 구조체 태그 이름
{
  자료형 변수명1;
  자료형 변수명2;
  ...
 };
 ```
## 구조체 변수 선언
### struct 구조체_태그가 새로운 자료형으로 이용
```c
struct 구조체태그이름 변수명;
struct 구조체태그이름 변수명1, 변수명2, 변수명3, ...;

struct 구조체태그이름 변수명 = {초기값1, 초기값2, 초기값3, ...};
```
### 구조체 정의와 변수 선언을 함께하는 방법
```c
struct account
{
  char name[12];
  int actnum;
  double balance;
 } myaccount; // 변수 myaccount는 struct account형 변수로 선언된다.
 
 struct account youraccount; // 변수 youraccount도 struct account형 변수로 선언된다
 ```
 ## 구조체 변수의 크기와 접근 연산자
 ### sizeof
  - 실제 구조체의 크기는 멤버의 크기의 합보다 크거나 같음.
 ### 구조체 멤버 접근 방법
  - 참조연산자 사용
 ```c
 구조체변수이름.멤버
 mine.actnum = 1001; mine.balance = 300000;
 ```
 ## 구조체 이용
  - 구조체 정의와 구조체 변수 선언
 ```c
 #include <stdio.h>
 #include <string.h>
 
 struct account
 {
  char name[12];
  int actnum;
  double balance;
 };
 
 int main(void)
 {
  struct account mine = {"홍길동", 1001, 300000};
  struct account yours;
  
  strcpy_s(yours.name, 12, "이동원");
  yours.actnum = 1002;
  yours.balance = 500000;
  
  printf("구조체 크기: %d\n", sizeof(mine));
  printf("%s %d %.2f\n", mine.name, mine.actnum, mine.balance);
  printf("%s %d %.2f\n", yours.name, yours.actnum, yours.balance);
  
 }
 ```
 
 
