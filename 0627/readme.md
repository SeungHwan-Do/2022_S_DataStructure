# 동적 메모리와 전처리(Cont'd)
## 배열의 장단점
### 배열 장점
 - 첨자(index)를 사용하여 임의 참조(random access)가 가능
### 단점
- 컴파일 전에 배열의 크기가 이미 결정
- 실행 중간에 배열 크기를 늘릴 수 없는 단점
- 중간에 삽입, 삭제의 어려움
## 연결 리스트 개요
### 연결 리스트
- 원소인 노드(node)가 순차적으로 연결된 자료구조
- 자기 참조 구조체로 정의되는 노드
  <br> (자료(data)와 링크(link)로 구성)
- 헤드(head)
<br>(항상 첫 번째 노드를 가리키는 포인터)
- 테일(tail) 포인터
<br> (마지막 노드를 가리키는 포인터)
```c
노드의 구현
struct selfref {
  int n;
  struct selfref *next;
};
```
## 연결 리스트 장단점
### 장점
 -  연결 리스트는 동적으로 노드를 생성
<br>(연결 리스트의 크기의 증가 감소에 따라 효율적으로 대처 가능)
 - 노드의 삽입과 삭제로 자료의 재배치
<br> (빠르게 처리)
### 단점
 - 배열에 비하여 임의 접근(random access)에 많은 시간이 소용
<br>(연결 리스트의 노드 검색은 헤드에서부터 링크를 따라가는 순차적 검색만이 가능)
 - 구현이 배열보다 다소 어려움
## 연결 리스트 연산(1)
### 노드 순회
- 연결 리스트에서 모든 노드를 순서대로 참조하는 방법
- 링크가 NULL이면 마지막 노드
### 추가
 - 새로운 노드를 하나 생성하여 연결 리스트의 마지막 노드로 추가
## 연결 리스트 연산(2)
### 노드 삽입
 #### 기존의 연결 리스트에서 노드“C”와 노드“C++”사이에 노드 “Objective-C”를 삽입하는 과정
- 먼저 삽입 노드를 동적으로 생성하여 적당한 자료를 저장
- 삽입하려는 바로 이전 노드인 노드“C’”로 이동
<br>( 삽입하는“Objective-C”노드의 링크에 노드“C”의 링크를 저장)
- 다음에는 노드“C”의 링크를 새로 삽입하는“Objective-C”노드를 가리키도록 삽입하는“Objective-C”노드의 주소값을 저장
## 연결 리스트 연산(3)
### 노드 삭제
 #### 기존의 연결 리스트에서 노드“C++”를 삭제
- 가장 먼저 삭제하려는 노드 바로 이전 노드“C”로 이동
<br>(삭제하려는 노드“C++”를 포인터 변수에 저장)
- 노드“C”의 링크를 삭제하려는 노드“C++”의 링크 노드값으로 저장 ( 삭제할려는 노드가 가리키는 노드를 저장)
- 마지막으로 삭제 노드 “C++”를 메모리에서 제거
## 사용자 정의 헤더파일 생성과 이용
### 헤더파일 생성
 #### 현재 프로젝트의 [헤더 파일]
- 오른쪽 버튼을 눌러 나온 메뉴 [추가/새항목]을 선택
#### [새 항목 추가] 대화상자
- 헤더 파일을 선택하고 사용자 헤더 파일의 이름 linkedlist를 입력
### 헤더파일 이용
 - 지시자 #include에서 큰따옴표를 사용해서 사용자 정의 헤더 파일을 삽입
## 헤더파일과 main() 함수 구현
### linkedlist.h
- 연결 리스트를 생성하고 출력하는 프로그램을 위한 헤더 파일
### linkedlist.c
- 연결 리스트를 생성하고 출력하는 메인 프로그램
```c
linkedlist.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list {
 char *name;
 struct linked_list *next;
};
typedef struct linked_list NODE;
typedef NODE * LINK;
```
```c
linkedlist.c
#include "linkedlist.h"

LINK createNode(char *name);
LINK append(LINK head, LINK cur);
int printList(LINK head);

int main(void)
{
 char name[30];
 LINK head = NULL;
 LINK cur;
 
 printf("이름을 입력하고 Enter를 누르세요. >> \n");
 whule (gets_s(name, 30) != NULL)
 {
  cur = createNode(name);
  if(cur == NULL) exit(1);
   head = append (head,cur);
  printList(head);
 }
 
 return 0;
}
```
## 함수 구현
### 함수 구현 소스 listlib.c
- 연결 리스트를 생성하고, 추가, 출력하는 함수 3개를 구현한 소스
```c
#include "linkedlist.h"

LINK createNote(char *name)
{
 LINK cur;
 cur = (NODE *) malloc(sizeof(NODE));
 if (cur == NULL)
 {
  pritnf("노드 생성을 위한 메모리 할당에 문제가 있습니다.\n");
  return NULL;
 }
 //언어 이름을 저장할 문자 배열을 동적 할당하여 name에 저장
 cur->name = (char *)malloc(sizeof(char) * (strlen(name)+1));
 strcpy(cur->name, name);
 cur->next = NULL;
 
 return cur;
}

//노드를 추가하는 함수
LINK append(LINK head, LINK cur)
{
 LINK nextNode = head;
 if( head == NULL)
  {
   head = cur;
   return head;
  }
  while (nextNode->next != NULL)
  {
   nextNode = nextNode->next;
   }
  nextNode->next = cur;
  
  return head;
}

//연결 리스트의 모든 노드 출력 함수
int printlist(LINK head)
{
 int cnt =0;
 LINK nextNode = head;
 while (nextNode != NULL)
 {
  printf("%3d번째 노드는 %s\n", ++cnt, nextNode->name);
  nextNode = nextNode->next;
 }
 
 return cnt;
}
```
## 전처리 지시자 종류
### \#으로 시작하는 전처리 지시어
![image](https://user-images.githubusercontent.com/79446573/175972945-4ab826c7-db59-46d6-b8a9-1da50c38314b.png)
