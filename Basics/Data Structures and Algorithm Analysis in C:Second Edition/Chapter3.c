抽象数据类型（Abstract Data Type）

表ADT
A1,A2,A3,…,An
表长为N，长度为0的是空表
对于Ai，Ai-1是直接前驱，Ai+1是直接后继

链表(Linked List)
struct Node{
  ElementType Element;
  Position Next;
};

双链表（Doubly Linked List）
struct Node{
  ElementType Element;
  Position Prev;
  Position Next;
};
循环链表（A1的Prev和An的Next指针不为0）

##List.h

#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List InitListNode();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L, Position P);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
/*
void PrintList(const List L);
void PrintLots(List L, int A[]);
void SwapWithNext(Position BeforeP, List L);
List IntersectList(List L1, List L2);
List UnionList(Position L1, Position L2);
void ReverseList(List L);
*/

struct Node{
	ElementType Element;
	Position Next;
};

#endif

##

##FalatError.h

#ifndef _FALAT_ERROR_H_
#define _FALAT_ERROR_H_

#include <stdio.h>
#include <stdlib.h>
#define Error(str) FalatError(str)
#define FalatError(str)
fprintf(stderr,"%s\n",str),exit(1);

#endif

##

##list.c

#include <stdlib.h>
#include "List.h"
#include "FalatError.h"

//初始化表聊节点
List InitListNode(){
	struct Node L;
	L = (struct Node *)malloc(sizeof(struct Node));
	if(L == NULL)
		FalatError("Out of memory!");
	L->next = NULL;
	return L;
}
//如果L非空就删除原本的链表，如果是空就重新分配空间
List MakeEmpty(List L){
	if(L != NULL)
		DeleteList(L);

	L = InitListNode();
	return L;	
}

int IsEmpty(List L){
	return L->next == NULL;
}

int IsLast(Position P, List L){
	return P->next == NULL;
}

//找到返回Position，如果没有找到返回NULL
Position Find(ElementType X, List L){
	Position P;

	P = L->next;
	while( P != NULL && P->Element != X )
		P = P->next;
	return P;
}

void Delete(ElementType X, List L){
	Position P, TmpCell;

	P = FindPrevious(X,L);
	if(!IsLast(P,L)){
		TmpCell = P->next;
		P->next = TmpCell->next;
		free(TmpCell);
		TmpCell = NULL;	
	}
}

Position FindPrevious(ElementType X, List L, Position P){
	Position P;

	P = L;
	while(P->next != NULL && P->next->Element != X)
		P = P->next;

	return P;
}

void Insert(ElementType X, List L, Position P){
	Position TmpCell;

	if(P == NULL)
		FatalError("The previous node does not exist!");
	TmpCell = InitListNode();
	TmpCell->Element = X;
	TmpCell->next = P->next;
	P->next = TmpCell;	
}

void DeleteList(List L){
	Position P, Temp;
	
	P = L->next;
	L->next =NULL;
	while(P){
		Temp = P->next;
		free(P);
		P = Temp;
	}
}

Position Header(List L){
	return L;
}

Position First(List L){
	return L->next;
}

//返回P的下一个指针
Position Advance(Position P){
	return P->next;
}

ElementType Retrieve(Position P){
	return P->Element;
}

##

##additionallist.c

#include "list.h"

void PrintList(const List L){
	Position P = Header(L);
	if(IsEmpty(L))
		printf("Empty List!\n");
	else{
		do{
			P = Advance(P);
			printf("%d ",Retrieve(P));
		}while(!IsLast(P,L));
		printf("\n");
	}
}

//数组A以-1
void PrintLots(List L, int A[]){
	int i,count;
	Position Lpos;

	Lpos = First(L);
	for(i = 0, count = 1; A[i] != -1 && Lpos != NULL; Lpos = Advance(Lpos), count++){
		if(count == A[i]){
			printf("%d ",Lpos->Element);
			i++;
		}
	}
}

void SwapWithNext(Position BeforeP, List L){
	Position P, AfterP;
	if(BeforeP != NULL){
		P = Advance(BeforeP);
		if(P != NULL){
			AfterP = Advance(P);
			if(AfterP != NULL){
				BeforeP->next = AfterP;
				P->next = AfterP->next;
				AfterP->next = P;
			}
		}
	}
}

//求交集
List IntersectList(List L1, List L2){
	List ResultList;
	Position L1Pos, L2Pos, ResultPos, ResultNextPos;
	ResultList = MakeEmpty(NULL);
	L1Pos = First(L1);
	L2Pos = First(L2);
	ResultPos = Header(ResultList);
	while(L1Pos != NULL && L2Pos != NULL){
		if(L1Pos->Element < L2Pos->Element)
			L1Pos = Advance(L1Pos);
		else if(L1Pos->Element > L2Pos->Element)
			L2Pos = Advance(L2Pos);
		else{
			ResultPos->next = InitListNode();
			ResultPos = ResultPos->next;
			ResultPos->Element = L1Pos->Element;
			L1Pos = Advance(L1Pos);
			L2Pos = Advance(L2Pos);
		}
	}
	return ResultList;
}

//求并集
List UnionList(Position L1, Position L2){
	List ResultList;
	Element InsertElement;
	Position L1Pos, L2Pos, ResultPos, ResultNextPos;
	ResultList = MakeEmpty(NULL);
	L1Pos = First(L1);
	L2Pos = First(L2);
	ResultPos = Header(ResultList);
	while(L1Pos != NULL && L2Pos != NULL){
		if(L1Pos->Element < L2Pos->Element)
			InsertElement = L1Pos->Element;
			L1Pos = Advance(L1Pos);
		else if(L1Pos->Element > L2Pos->Element)
			InsertElement = L2Pos->Element;
			L2Pos = Advance(L2Pos);
		else{
			InsertElement = L2Pos->Element;
			L1Pos = Advance(L1Pos);
			L2Pos = Advance(L2Pos);
		}
		ResultPos->next = InitListNode();
		ResultPos = ResultPos->next;
		ResultPos->Element = InsertElement;
	}
	
	while(L1Pos != NULL){
		ResultPos->next = InitListNode();
		ResultPos = ResultPos->next;
		ResultPos->Element = L1Pos->Element;
		L1Pos = Advance(L1Pos);
	}
	
	while(L2Pos != NULL){
		ResultPos->next = InitListNode();
		ResultPos = ResultPos->next;
		ResultPos->Element = L2Pos->Element;
		L2Pos = Advance(L2Pos);
	}
	
	return ResultList;
}

//反顺
void ReverseList(List L){
	if(IsEmpty(L) || L->next->next == NULL)
		return;
	Position CurrentPos, PreviousPos, NextPos;
	CurrentPos = First(L);
	PreviousPos = NULL;
	NextPos = L->next->next;
	while(NextPos != NULL){
		CurrentPos->next = PreviousPos;
		PreviousPos = CurrentPos;
		CurrentPos = NextPos;
		NextPos = Advance(NextPos);
	}
	CurrentPos->next = PreviousPos;
	L->next = CurrentPos;
}

##
