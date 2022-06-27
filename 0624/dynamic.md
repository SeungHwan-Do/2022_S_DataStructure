# 동적 메모리와 전처리
## 동적 메모리 개요
### 동적 메모리 할당
 - 실행 중에 메모리를 할당하는 방식
 - 메모리 사용 예측이 정확하지 않고 실행 중에 메모리 할당이 필요하다면 동적 메모리 방식이 적합
```c
정적 메모리 할당
int i;
long prod =1;
int facto[6];
char *st[] = {"algol", "pascal", "C", "C++", "Java", "C#"};
```
```c
동적 메모리 할당
int *pi = NULL;

if((pi = (int *)malloc( sizeof(int) )) == NULL)
{
  printf("메모리 할당에 문제가 있습니다.");
  exit(1);
};
*pi = 3;
```
### 함수 malloc() 와 free()
 - 함수 malloc() 의 호출로 힙 영역에 확보
 - 할당된 메모리는 사용 후 함수 free()를 사용해 해제
## 동적 메모리 관련 함수
### 함수는 malloc(), calloc(), realloc() 3가지
![image](https://user-images.githubusercontent.com/79446573/175943081-a6c4469a-848f-467b-bcf4-e812ea220743.png)
## 동적 메모리 함수 malloc()
### 헤더 파일 stdlib.h에 다음 함수원형으로 정의
반환값의 유형은 모든 자료형의 포인터로 이용할 수 있도록 void *
```c
malloc() 함수원형
void * malloc(size_t size);
```
자료형 size_t는 자료형의 크기를 의미하며, unsigned int형
<br> 함수 malloc()은 인자인 자료형 크기 size 만큼의 메모리를 할당하여 성공하면 할당된 공간의 void 포인터를 반환하며, 실패하면 null을 반환
```c
int *pi = (int *) malloc( sizeof(int) );
*pi = 3;
```
## 함수 malloc()의 이용
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *pi = NULL;
  
  if ((pi = (int*) malloc(sizeof(int))) == NULL) {
    printf("메모리 할당에 문제가 있습니다.");
    exit(1);
  };
  *pi = 3;
  printf("*pi = %d\n", *pi);
  printf("pi = %d\n", pi);
  free(pi);
  
  return 0;
}
```
## 함수 malloc()에 의한 배열 공간 할당
### malloc()의 인자
 - sizeof(int) * (확보하려는 배열의 원소의 개수)로 지정
### arraymalloc.c
 - 표준입력으로 입력될 성적의 갯수를 먼저 입력받아 그 수만큼 메모리를 동적으로 할당하는 프로그램
 - 동적 메모리에 여러 성적을 저장하여 합과 평균을 구하여 출력
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *ary = NULL;
  int i = 0, n = 0, sum =0;
  
  printf("입력할 정수의 개수를 입력>> ");
  scanf_s("%d", &n);
  
  if ((ary = (int *) malloc(sizeof(int)*n)) == NULL)
  {
    printf("메모리 할당 문제가 있습니다.");
    exit(1);
   };
   
   printf("%d개의 정수 입력>>", n);
   for (i = 0; i<n; i++)
   {
    scanf_s("%d", (ary + i ));
    sum += *(ary + i); // sum += ary[i];
   }
   printf("합 : %d 평균 : %.1f\n, sum, (double)sum/n);
   free(ary);
   
   return 0;
}
```
## 함수 calloc()
### 인자가 2개, 메모리 공간을 확보
 - 초기값을 자료형에 알맞게 0을 저장
```c
calloc() 함수원형
void * calloc(size_t num, size_t size);
```
함수  calloc()은 원소 크기가 size인 배열 크기 num개의 공간을 할당하여 포인터를 반환하고 원소 값은 모두 0으로 저장
```c
int ary* = NULL;
ary = (int *) calloc(3, sizeof(int))
```
## 함수 realloc()
### 이미 확보한 저장공간을 새로운 크기로 변경
 - 성공적으로 메모리를 할당하면 변경된 저장공간의 시작 주소를 반환하고 실패하면 NULL을 반환
### 2개의 인자
 - 첫 번째 인자는 변경할 저장공간의 주소이며
 - 두 번째 인자는 변경하고 싶은 저장공간의 총 크기
```c
realloc() 함수원형
void * realloc(void *p, size_t size);
```
함수 realloc()은 이미 확보된 메모리 p를 다시 지정한 크기 size로 변결하는 함수이며, 이미 확보한 p가 NULL이면 malloc()과 같은 기능을 수행
```c
int *ary = (int *) malloc( sizeof(int));
int *p = (int*) realloc( ary, sizeof(int)*4);
```
## 함수 realloc()의 이해
### cary는 int형 3개의 저장공간의 시작 주소를 저장
 - 모든 변수의 값은 기본값인 0으로 저장
### reary
 - realloc()을 이용하여 변수 cary가 가리키는 메모리의 내용을 다시 크기가 4인 배열로 재할당
 - 함수 realloc()에 의하여 확장되는 공간은 malloc()과 같이 기본값 0이 저장되지 않음
```c
int *reary, *cary;
cary = (int *) calloc(3, sizeof(int));
reary = (int *) realloc(cary, 4*sizeof(int));
```
## 함수 realloc()의 이용
함수 realloc() 을 이용하여 이미 할당된 메모리 변경
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
 int *reary, *cary;
 int i =0;
 
 if ((cary = (int *) calloc( 3, sizeof(int))) == NULL)
 {
  printf("메모리 할당이 문제가 있습니다.\n");
  exit(EXIT_FAILURE);
 }
 for(i = 0; i<4; i++)
  printf("reary[%d] = %d\n", i, *(reary + i));
 free(reary);
 
 return 0;
}
```
## 자기 참조 구조체와 연결 리스트
### 자기 참조 구조체
 - 구조체의 멤버 중의 하나가 자기 자신의 구조체 포인터 변수를 갖는 구조체
 - 자기 참조 구조체는 동일 구조체의 표현을 여러 개 만들어 연결할 수 있는 기능
### 연결 리스트(Linked List)
 - 동일한 구조체가 연결되어 있는 구조
```c
struct selfref {
 int n;
 struct selfref *next;
 //struct selfref one; //컴파일 오류 발생
};
```
## 자기참조 구조체 구현
```c
#include <stdio.h>
#include <stdlib.h>

struct selfref {
 int n;
 struct selfref *next;
 //struct selfref one; //컴파일 오류 발생
};
typedef struct selfref list;

int main(void)
{
 list *first = NULL, *second = NULL;
 first = (list *)malloc(sizeof(list));
 second = (list *)malloc(sizeof(lsit));
 first->n = 100;
 first->next = NULL;
 second->n =200;
 second->next = NULL;
 first->next = second;
 
 printf("구조체 크기 = %d\n\n", sizeof(list));
 printf("첫 번째 구조체: ");
 pritnf("\t자료의 주소값(first) = %u\n", first);
 printf("\t자료값(first->n) = %d\n", first->n);
 printf("\t자료값(first->next) = %u\n", first->next);
 printf("\t자료값(first->next->n) = %d\n\n", first->next->n);
 
 printf("두 번째 구조체: ");
 printf("\t자료의 주소값(second) = %u\n", second);
 printf("\t자료값(second->n) = $d\n", second->n);
 printf("\t자료값(second->next) = %u\n", sceond->next);
 
 free(first);
 free(second);
 
 return 0;
}
```
