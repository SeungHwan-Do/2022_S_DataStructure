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

## 구조체 멤버로 사용되는 구조체
### 구조체 멤버로 다른 구조체 사용
 - 구조체 멤버로 이미 정의된 다른 구조체 형 변수와 구조체 포인터 변수를 사용 가능
## 자료형 재정의 구문
### 키워드 typedef
 - 이미 사용되는 자료형을 다른 새로운 자료형 이름으로 재정의
```c
typedef 기존자료형이름 새로운자료형1, 새로운자료형2, ...;
typedef int profit;
typedef unsigned int budget;
typedef unsigned in size_t;
```
## 자료형 재정의 목적
### 프로그램의 시스템 간 호환성과 편의성
#### 시스템마다 자료형의 크기가 달라 문제 발생
 - 터보 C++ 컴파일러에서 자료형 int는 저장공간의 크기가 2바이트
 - Visual C++에서는 4바이트
#### typedef를 사용하여 새로운 자료형 myint를 정의하여 사용

## 구조체 자료형 재정의
### struct를 제거한 새로운 자료형
 - typedef 사용하여 구조체를 한단어의 새로운 자료형으로 정의하면 사용하기에 편리
 - typedef 사용하여 구조체 struct date를 date로 재정의 가능
 - date가 아닌 datetype 등 다른 이름으로도 재정의 가능
### 구조체 정의와 typedef를 함께 사용 가능
 - 구조체 자료형 software 정의
```c
struct date
{
 int year;
 int month;
 int day;
};

typedef struct date date; // 자료형인 date는 struct date와 함께 동일한 자료형으로 이용이 가능하다.

typedef struct
{
 char title[30];
 char company[30];
 char kinds[30];
 date release;
 }software; // software는 변수가 아니라 새로운 자료형이다
```

## 구조체 포인터
### 구조체 포인터 변수
 - 구조체의 주소값을 저장할 수 있는 변수
 - 다른 포인터 변수와 사용 방법이 동일
```c
struct lecture
{
 char name[20];
 int type;
 int credit;
 int hours;
};
typedef struct lecture lecture;
lecture *p;
```
```c
lecture os = {"운영체제", 2, 3, 3};
lecture *p = &os;
```
## 포인터 변수의 구조체 멤버 접근
### 포인터 p의 구조체 멤버 접근연산자 ->
 - p->name과 같이 사용
 - 포인터 p가 가리키는 구조체 변수의 멤버 name에 접근하는 연산식
 - (\*p).name으로도 사용 가능
### 연산식 \*p.name과 구분
#### \*(p.name) 의미
 - 접근연산자(.)가 간접연산자 (\*)보다 우선순위가 빠르므로
 - p가 포인터이므로 p.name은 문법 오류가 발생
 ![image](https://user-images.githubusercontent.com/79446573/176374639-597ebc0b-d140-4287-b7e6-4bd6d703b8df.png)
## 열거형
### enum
 - 정수형 상수 목록 집합을 정의하는 자료형
 - enum 다음에 열거형 태그명을 기술하고 중괄호를 사용하여 정수형 상수 목록을 쉼표로 분리하여 기술
 - 정의된 열거형은 새로운 자료형으로 사용 가능
 - 열거형은 내부적으로 int형에 해당
```c
enum 열거형태그명 {열거형1, 열거형2, 열거형3, ...};
enum 열거형태그명 변수명;
```
### 열거형태그 이름이 생략된 경우
####  열거형을 정의하면서 변수를 선언한다면 열거형 태그 이름을 생략 가능
 - 그러나 동일한 자료형의 변수를 더 이상 선언 불가능
### typedef 사용 자료형 재정의
```c
enum day7 {sun, mon, tue, wed, thu, fri, sat};
typedef enum day7 day;
day today = fri;
```
## 열거형 사용
- 열거형 정의와 변수 선언 및 사용
- 가계부 항목을 열거형 expense에 정의
- 자료형 enum expense형인 변수 exptype은 상수인 entertainment를 대입하여 반복문에 사용
- 열거형 변수인 exptype을 배열의 첨자로 이용하면 보다 편리하게 관련된 배열 원소 참조가 가능함
```c
#include <stdio.h>

enum expense {entertainment, automobile, utilities, food, clothing, miscellaneous};
typedef enum expense expense;

char *exp[] = {"문화비", "자동차유지비", "공과금", "식비", "의생활비", "기타"};

int main(void)
{
 expense exptype;
 int money[] = {240000, 340000, 400000, 500000, 300000, 300000, 2500000};
 
 puts("2012년 5월 지출 내역\n");
 for(exptype = entertainment; exptype <= miscellaneous; exptype++)
  printf("%16s: %8d\n", exp[exptype], money[exptype]);
  
 printf("\n");
 
 return 0;
}
```
## 열거형 상수 이용
- 열거형 상수값의 지정과 출력
```c
#include <stdio.h>

int main(void)
{
 enum color {yellow=3, red, blue, magenta, green} col;
 
 for (col = yellow; col <= green; col++)
  printf("%2d", col);
 printf("\n");
 
 return 0;
}
```
## 열거형 상수 지정
### 상수목록에서 정수를 지정
#### 상수 목록에 정수값을 부분적으로 직접 지정 가능
 - 성수값을 지정한 상수는 그 값으로, 지정되지 않은 상수는 그 이후로 1씩 증가한 상수값으로 정의
```c
enum shape { circle, tri=3, rect=4, star=7, dia};
typedef enum shape shape;

 enum pl {c=1972, cpp=1983, java=1995, cs=2000};
 typedef enum pl plang;
 
enum bool {false, true};
typedef enum bool boolean;
```
