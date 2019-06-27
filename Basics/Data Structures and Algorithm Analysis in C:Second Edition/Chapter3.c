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

//声明
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

//初始化链表节点
List InitListNode(){
	//声明Node指针
	struct Node L;
	//分配堆空间
	L = (struct Node *)malloc(sizeof(struct Node));
	//空间分配失败，FalatError
	if(L == NULL)
		FalatError("Out of memory!");
	//next指针赋值NULL
	L->next = NULL;
	//返回Node指针
	return L;
}
//如果L非空就删除原本的链表，如果是空就重新分配空间
List MakeEmpty(List L){
	if(L != NULL)
		DeleteList(L);

	L = InitListNode();
	return L;	
}

//判断链表是否是空
int IsEmpty(List L){
	//判断头指针的next的指针是否是NULL
	return L->next == NULL;
}

//判断P指针是否是尾指针
int IsLast(Position P, List L){
	return P->next == NULL;
}

//返回相同元素的指针
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

//交换指针
void SwapWithNext(Position BeforeP, List L){
	/*
	**传入BeforeP指针
	**交换P和AfterP指针
	*/
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
	/**
	**两个Position都不是NULL
	**当某一个指针指向的元素小于另一个指针指向的元素时，该指针指向next
	**如果相同就将该Node的元素给ResultPos
	**/
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
	
	/*
	**在原有基础上将比原本大的所有元素导入ResultPos
	*/
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
	//没有节点或者只有一个节点
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

Example 1 Polynomial ADT

//使用数组表
typedef struct{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
}* Polynomial;

void
ZeroPolynomial(Polynomial Poly){
	int i;
	
	for(i = 0; i <= MaxDegree; i++)
		Polynomial -> CoeffArray[i] = 0;
	Polynomial -> HighPower = 0;
}

void
AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum){
	int i;
	
	ZeroPolynomial(PolySum);
	PolySum -> HighPower = Max(Poly1 -> HighPower, Poly2 -> HighPower);
	for(i = 0; i <= HighPower; i++){
		PolySum -> CoeffArray[i] = Poly1 -> CoeffArray[i] + Poly2 -> CoeffArray[i];
	}
}

void
MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd){
	int i, j;
	
	PolyProd -> HighPower = Poly1 -> HighPower + Poly2 -> HighPower;
	if(PolyProd -> HighPower > MaxDegree)
		Error("Exceeded array size!");
	else{
		for(i = 0; i <= MaxDegree; i++)
			for(j = 0; j <= MaxDegree; j++){
				PolyProd[i + j] += Poly1[i] * Poly2[j];
			}
	}
}

//使用单链表
struct node;
typedef struct node *PtrToNode;
struct node{
	int Coefficient;
	int Exponent;
	PtrToNode next;
};
typedef PtrToNode Polynomial;

void
ZeroPolynomial(Polynomial Poly){
	PtrToNode Pos, TmpCell;
	
	Pos = Poly -> next;
	Poly -> next = NULL;
	while(Pos){
		TmpCell = Pos;
		Pos = Pos -> next;
		free(TmpCell);
		TmpCell = NULL;
	}
}

void
AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum){
	PtrToNode P1Pos, P2Pos, PSPos, TmpPos;
	
	P1Pos = Poly1 -> next;
	P2Pos = Poly2 -> next;
	ZeroPolynomial(PolySum);
	PSPos = PolySum;
	
	while(P1Pos != NULL && P2Pos !=NULL){
		if(P1Pos -> Exponent > P2Pos -> Exponent){
			TmpPos = InitNode();
			TmpPos -> Coefficient = P1Pos -> Coefficient;
			TmpPos -> Exponent = P1Pos -> Exponent;
			PSPos -> next = TmpPos;
			PSPos = PSPos -> next;
			TmpPos = NULL;
			P1Pos = P1Pos -> next;
		}
		else if(P1Pos -> Exponent < P2Pos -> Exponent){
			TmpPos = InitNode();
			TmpPos -> Coefficient = P2Pos -> Coefficient;
			TmpPos -> Exponent = P2Pos -> Exponent;
			PSPos -> next = TmpPos;
			PSPos = PSPos -> next;
			TmpPos = NULL;
			P2Pos = P2Pos ->next;
		}
		else{
			TmpPos = InitNode();
			TmpPos -> Coefficient = P1Pos -> Coefficient;
			TmpPos -> Exponent = P1Pos -> Exponent;
			PSPos -> next = TmpPos;
			PSPos = PSPos -> next;
			TmpPos = NULL;
			P1Pos = P1Pos -> next;
			P2Pos = P2Pos ->next;
		}
	}
	
	while(P1Pos != NULL){
		TmpPos = InitNode();
		TmpPos -> Coefficient = P1Pos -> Coefficient;
		TmpPos -> Exponent = P1Pos -> Exponent;
		PSPos -> next = TmpPos;
		PSPos = PSPos -> next;
		TmpPos = NULL;
		P1Pos = P1Pos -> next;
	}
	
	while(P2Pos != NULL){
		TmpPos = InitNode();
		TmpPos -> Coefficient = P2Pos -> Coefficient;
		TmpPos -> Exponent = P2Pos -> Exponent;
		PSPos -> next = TmpPos;
		PSPos = PSPos -> next;
		TmpPos = NULL;
		P2Pos = P2Pos ->next;
	}
}

void
MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd){
	PtrToNode P1Pos, P2Pos, PPPos, TmpPos, PPNextPos;
	
	if(Poly1 -> next == NULL){
		P2Pos = Poly2 -> next;
		while(P2Pos){
			TmpPos = InitNode();
			TmpPos -> Coefficient = P2Pos -> Coefficient;
			TmpPos -> Exponent = P2Pos -> Exponent;
			PPPos -> next = TmpPos;
			PPPos = PPPos -> next;
			TmpPos = NULL;
			P2Pos = P2Pos ->next;
		}
	}
	else if(Poly1 -> next == NULL){
		P1Pos = Poly1 -> next;
		while(P1Pos){
			TmpPos = InitNode();
			TmpPos -> Coefficient = P1Pos -> Coefficient;
			TmpPos -> Exponent = P1Pos -> Exponent;
			PPPos -> next = TmpPos;
			PPPos = PPPos -> next;
			TmpPos = NULL;
			P1Pos = P1Pos ->next;
		}
	}
	else{
		P1Pos = Poly1 -> next;
		while(P1Pos){
			P2Pos = Poly2 -> next;
			while(P2Pos){
				TmpPos = InitNode();
				TmpPos -> Coefficient = P1Pos -> Coefficient * P2Pos -> Coefficient;
				TmpPos -> Exponent = TmpPos -> Exponent + TmpPos -> Exponent;
				
				//找到相同指数或者比这个指数大的第一个指数
				PPPos = PolyProd;
				while(PPPos -> next != NULL && PPPos -> next -> Exponent > TmpPos -> Exponent){
					PPPos = PPPos -> next;
				}
				
				if(PPPos -> next == NULL || PPPos -> next -> Exponent < TmpPos -> Exponent){
					PPNextPos = PPPos -> next;
					PPPos -> next = TmpPos;
					TmpPos -> next = PPNextPos;
					TmpPos = NULL;
				}
				else{
 					PPPos -> next -> Coefficient += TmpPos -> Coefficient;
				}
				
				P2Pos = P2Pos -> next;
			}
			P1Pos = P1Pos ->next;
		}
	}
}

















