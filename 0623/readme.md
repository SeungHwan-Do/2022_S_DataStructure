## 배열
여러 변수들이 같은 배열 이름으로 일정한 크기의 연속된 메모리에 저장되는 구조
 
## 배열 선언
 - 배열의 크기를 지정하는 부분에는 양수의 정수 상수와 기호 상수 또는
이들의 연산식이 가능
 - 원소 자료형으로는 모든 자료형이 가능
 - 배열 선언 시 초기값 지정이 없다면 반드시 배열 크기는 명시
```c
#define SIZE 5

int score[10];
double point[20];
char ch[80];
float grade[SIZE];
int score[SIZE+1];
int degree[SIZE+2];
```
```c
int n = 5;
int score[n];
double point[-3];
char ch[0];
float grade[3.2];
int score[n+2];
int degree[n*2];
잘못된 구문
```

## 배열 원소 접근
### 첨자
#### 배열 선언 후 배열 원소에 접근하려면 배열 이름 뒤에 대괄호 사이 첨자(index) 를 이용
 - 첫 번째 배열 원소에 접근하는 첨자값은 0
 - 다음 두 번째 원소는 1, 그리고 그 다음 원소를 접근하려면 순차적으로 1씩 증가 그러므로 유효한 첨자의 범위는 0부터 (배열 크기-1)까지
#### 첨자의 유효범위를 벗어나 원소를 참조하면 실행오류가 발생
```c
int score[5];

// 배열 원소에 값 저장
score[0] = 78;
score[1] = 97;
score[2] = 85;
// 배열 4번째 원소에 값 저장하지 않아 쓰레기값 저장
score[4] = 91;
score[5] = 50; // 문법 오류는 발생하지 않으나 실행 오류 발생
```

## 배열 선언과 원소의 출력
배열 선언 후 배열 원소에 값을 저장한 후 순차적으로 출력
```c
#include <stdio.h>

#define SIZE 5

int main(void)
{
  int i=0;
  
  //배열 선언
  int score[SIZE];//int score[5];
  
  //배열 원소에 값 저장
  score[0] = 78;
  score[1] = 97;
  score[2] = 85;
  //배열 4번째 원소에 값을 저장하지 않아 쓰레기값 저장
  score[4]=91;
  //score[5]=50; // 문법 오류는 발생하지 않으나 실행 오류 발생
  
  //배열 원소 출력
  for(i=0;i<SIZE; i++);
    printf("%d", score[i]);
   print("\n");
   
   return 0;
}
```
## 배열 선언 초기화
배열 선언을 하면서 대입연산자를 이용
원소자료형 배열이름[배열크기]={원소값1, 원소값2, 원소값3, 원소값4, 원소값5,...};
```c
int grade[4] = {98, 88, 92, 95};
double output[] = {78.4, 90.2, 32.3, 44.6, 59.7, 98.9};
int cpoint[] = {99, 76, 84, 76, 68};
```
초기 값이 없는 원소는 기본값으로 저장
 - 만일 배열 크기가 초기값 원소의 수보다 크면 지정하지 않은 원소의 초기값은 자동으로 모두 기본값으로 저장
 - 여기서 기본값이란 자료형에 맞는 0 (즉 정수형은0, 실수형은 0.0, 그리고 문자형은 '\0'인 널문자
 ```c
 int dist[5] = {12, 23, 17, 55, 57, 71}; ->error C2078 : 이니셜라이저가 너무 많습니다.
 ```
 ## 배열의 사용
### 주의
초기화 방법은 반드시 배열 선언 시에만 이용이 가능하며 배열 선언 이후에는 사용 불가능
```c
int n = 5;
int score[n] = {89, 92, 91};
int grade[3] = {98, 88, 92, 95};
int cpoint[] = {99, 76, 84, 76, 68, 93};
char ch[] = {a, b, c};
double wideth[4]; width = {23.5, 32.1};
```
```c
#include <stdio.h>

#define SIZE 6
int mian(void)
{
  int i,sum=0;
  //배열 cpoint의 선언과 초기화
  int cpoint[] = {99, 76, 84, 76, 68, 93};
  
  //for 문을 이용하여 합을 구함
  for ( i=0 ; i<SIZE; i++)
  {
    sum += cpoint[i];
    printf("cpoint[%d] = %d\n", (double) sum/SIZE);
    
    return 0;
}
```
##  이차원 배열
### 행과 열의 구조
 - 이차원 배열 선언은 2개의 대괄호가 필요
 - 첫 번째 대괄호에는 배열의 행 크기, 두 번째는 배열의 열 크기를 지정
 - 배열 선언 시 초기값을 저장하지 않으면 반드시 행과 열의 크기는 명시
원소자료형 배열이름[배열형크기][배열열크기];
```c
#define RSIZE5
#define CSIZE 2

int score[RSIZE][CSIZE];

double point[2][3];
char ch[5][80];
float grade[7][CSIZE];
```
## 이차원 배열 선언과 원소 참조
### 2개의 첨자 필요
 - 행 첨자는 0에서 (행크기-1)까지 유효
 - 마찬가지로 열 첨자는 0에서 (열크기-1)까지 유효
```c
#define ROWSIZE 2
#define COLSIZE 3

// 이차원 배열 선언
int td[ROWSIZE][COLSIZE];

//이차원 배열 원소에 값 저장
```c
td[0][0] = 1; td[0][1] = 2; td[0][2] = 3;
td[1][0] = 4; td[1][1] = 5; td[1][2] = 6;
```

### Row Major Array
첫 번째 행의 모든 원소가 메모리에 할당된 이후에 두 번째 행의 원소가 순차적으로 할당
```c
#include <stdio.h>

#define ROWSIZE 2
#define ROWSIZE 3

int main(void)
{
  int i=0, j=0;
  
  //이차원 배열 선언
  int td[ROWSIZE][COLSIZE];
  
  //이차원 배열 원소에 값 저장
  td[0][0] = 1; td[0][1] = 2; td[0][2] = 3;
  td[1][0] = 4; td[1][1] = 5; td[1][2] = 6;
  
  printf("for 문을 이용하여 출력\n");
  for (i= 0; i <ROWSIZE; i++)
  {
    for(j=0; j < COLSIZE; j++)
      printf("%d", td[i][j]);
     printf("\n");
   }
  
  return 0;
}
```
## 이차원 배열 선언 초기화
### 이중 중괄호 또는 중괄호
 - 중괄호를 중첩되게 이용하는 방법
 - 일차원 배열과 같이 하나의 중괄호로 모든 초기값을 쉼표로 분리하는 방법
 - 첫 번째 대괄호 내부의 행의 크기는 명시하지 않을 수 있음
 - 그러나 두 번째 대괄호 내부의 열의 크기는 반드시 명시
```c
int score[2][3] = {[30, 44, 67}, {87, 43, 56}};
int score[2][3] = {30, 44, 67, 87, 43, 56};
int score[][3] = {30, 44, 67, 87, 43, 56};
```
### 명시되지 않은 행의 크기
 - ( (배열원소수) / (열수) )에서, 소수점인 경우 무조건 올림하면 행의 수
 - 행 크기는 생략할 수 있어도 열 크기는 생략할 수 없다는 것에 주의
 ```c
 int a[2][4] = {10, 30, 40, 50, 1, 3, 0, 0};
 int a[2][4] = {10, 30, 40, 50, 1, 3};
 int a[][4] = {10, 30, 40, 50, 1, 3};
 int a[2][4] = {{10, 30, 40, 50},{1, 3}};
 int a[][4] = {{10, 30, 40, 50},{1, 3}};
 ```
 ## 함수에서 배열 전달
 ### 배열 전체 전달
 - 함수의 매개변수로 배열을 전달한다면 한 번에 여러 개의 변수를 전달하는 효과
 - double ary[5]보다는 double ary[]라고 기술하는 것을 권장
 - 실제로 함수 내부에서 실매개변수로 전달되는 배열 크기를 알 수 없음
 - 그러므로 배열 크기를 두 번째 인자로 사용
```c
double sum(double ary[], int n);
//double sum(double [],int); //가능
...
double data[] = {2.3, 3.4, 4.5, 6.7, 9.2};

...sum(data, 5);
```
```c
double sum(double ary[], int n)
{
 int i=0;
 double total = 0.0;
 for(i=0; i<n; i++)
  total += ary[i];
  
 return total;
}
```
## 배열 크기 계산
연산자 sizeof를 이용하여 배열 크기를 계산
#### 배열 크기(배열원소수) = sizeof(배열이름) / sizeof(배열원소)
#### int arraysize = sizeof(data) / sizeof(data[0]);
```c
//이차원 배열값을 모두 더하는 함수원형
double sum(double data[][3], int, int);
//이차원 배열값을 모두 출력하는 함수원형
void printarray(double data[][3], int, int);
...
double x[][3] = { {1, 2, 3}, {7, 8, 9}, {4, 5, 6}, {10, 11, 12} };

int rowsize = sizeof(x) / sizeof(x[0]);
int colsize = sizeof(x[0]) / sizeof(x[0][0]);

printarray(x, rowsize, colsize);
...
sum(x, rowsize, colsize);...
...
```
```c
//이차원 배열값을 모두 출력하는 함수
void printarray(double area[][3], int rowsize, int colsize)
{
 ...
}

//이차원 배열값을 모두 더하는 함수

double sum(double data[][3], int rowsize, int colsize)
{
 ...
  for(i=0; i<rowsize; i++)
   for(j=0, j<colsize; j++)
    total += data[i][j];
   return total;
}
```
