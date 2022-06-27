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
 
