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

##


##radixSort.c

//对正数进行基数排序
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
#define INPUT_SIZE 5
#define Error(str) FalatError(str)
#define FalatError(str) \
fprintf(stderr,"%s",str),exit(1);

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct node{
	int element;
	Position next;
};

int getMaxNumber(const List L){
	int maxNumber;
	Position P;
	
	maxNumber = 0;
	P = L -> next;
	while(P){
		if(P -> element > maxNumber)
			maxNumber = P -> element;
		P = P -> next;
	}
	
	return maxNumber;
}

Position initNode(){
	Position P;
	P = (Position)malloc(sizeof(struct node));
	if(P == NULL)
		Error("Out of memory!");
	P -> next = NULL;
	return P;
}

void destroyList(List L){
	Position P, Tmp;
	
	P = L;
	while(P){
		Tmp = P;
		P = P -> next;
		free(Tmp);
		Tmp = NULL;
	}
}

void addBackList(List L, Position Pos){
	Position P;
	
	P = L;
	while(P -> next != NULL){
		P = P -> next;
	}
	
	P -> next = Pos;
}

void inputLinkedList(List L){
	int number;
	Position P;
	P = L;
	
	while(P -> next != NULL)
		P = P -> next;
	
	while(scanf("%d", &number) && number >= 0){
		P -> next = initNode();
		P -> next -> element = number;
		P = P -> next;
	}
}

void radixSortList(List L, int maxNumber){
	int exp;
	
	for(exp = 1; maxNumber / exp > 1; exp *= 10){
		int i;
		List LArray[ARRAY_SIZE];
		Position P, Tmp;
		
		for(i = 0; i < ARRAY_SIZE; i++)
			LArray[i] = initNode();
			
		P = L -> next;
		L ->next = NULL;
		while(P){
			Tmp = P;
			P = P ->next;
			Tmp -> next = NULL;
			addBackList(LArray[Tmp -> element / exp % ARRAY_SIZE], Tmp);
		}
			
		for(i = 0; i < ARRAY_SIZE; i++){
			P = LArray[i] -> next;
			while(P){
				Tmp = P;
				P = P ->next;
				Tmp -> next = NULL;
				addBackList(L, Tmp);
			}
		}
		
		for(i = 0; i < ARRAY_SIZE; i++)
			free(LArray[i]);
	}
	
}

void outputLinkedList(List L){
	int count;
	Position P;
	
	P = L -> next;
	count = 0;
	while(P){
		printf("%d ", P -> element);
		count +=1;
		if(count % INPUT_SIZE == 0)
			printf("\n");
		P = P -> next;
	}
}

int main(){
	int maxNumber;
	List L;
	
	L = initNode();
	//输入
	inputLinkedList(L);
	//获取最大数
	maxNumber = getMaxNumber(L);
	//排序
	radixSortList(L, maxNumber);
	//输出
	outputLinkedList(L);
	
	destroyList(L);
	return 0;
}

##


多重表
广义表，一个结构体可能属于多个表，往往是循环结构，表尾指针指向表头


Cursor 游标ADT
当编程语言没有指针这一基本类型的时候，，可以利用数组模仿链式结构来写表ADT
表的末端指向数组第一个元素，即下标为0的元素(一般保存着不会存在于存储元素的值)
不好的地方，数组一开始大小就分配了，不易变动

##cursor.h

#ifndef _CURSOR_H_
#define SPACESIZE 1000

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
struct node{
	ElementType element;
	Position next;
}

struct node CursorSpace[SPACESIZE];

##cursorSpace.c

#include <cursor.h>
//假设元素全部是正数
void 
initCursorSpace(struct node CursorSpace[], int SpaceSize){
	int i;
	for(i = 0; i < SpaceSize; i++){
		CursorSpace[i].element = -1;
		CursorSpace[i].next = i + 1;
	}
	CursorSpace[SpaceSize - 1].next = 0; 
}

Position
CursorAlloc(void){
	Position P;
	
	P = CursorSpace[0].next;
	CursorSpace[0].next = CursorSpace[P].next;
	
	return P;
}

void
CursorFree(Position P){
	CursorSpace[P].next = CursorSpace[0].next;
	CursorSpace[0].next = p;
}

##

栈ADT
栈又称先进后出表，一般操作就是Push，Pop，Top
可以访问的元素只有栈顶的元素，非栈顶元素在设计时应该不能被访问

##stack.h

#ifndef _STACK_H_
#define _STACK_H_

struct node;
typedef struct node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

struct node{
	ElementType element;
	PtrToNode next;
};

#endif

##

##stack.c

#include <stdlib.h>
#include "falaterror.h"
#include "stack.h"

int IsEmpty(Stack S){
	return S->next == NULL;
}

Stack CreateStack(void){
	Stack S;
	
	S = (Stack)malloc(sizeof(struct node));
	if(S == NULL)
		FalatError("Out of space!");
	S -> next == NULL;
	MakeEmpty(S);
	return P; 
}

void DisposeStack(Stack S){
	while(!IsEmpty(S))
		Pop(S);
	free(S);
}

void MakeEmpty(Stack S){
	if(S == NULL)
		Error("Must use CreateStack first!");
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S){
	PtrToNode TmpCell;
	
	TmpCell = (PtrToNode)malloc(sizeof(struct node));
	if(TmpCell == NULL)
		FalatError("Out of space!");
	else{
		TmpCell -> element = X;
		TmpCell -> next = S ->next;
		S -> next = TmpCell;
	}
}

ElementType Top(Stack S){
	if(!IsEmpty(S))
		return S -> next -> element;
	else{
		Error("Empty Stack!");
		return 0; /*Return value used to avoid warning*/
	}
}

void Pop(Stack S){
	PtrToNode FirstCell;

	if(IsEmpty(S)){
		Error("Empty Stack!");
	}
	else{
		FirstCell = S -> next;
		S -> next = S -> next -> next;
		free(FirstCell);
	}
}

##

##stackRecord.h

#ifndef _STACK_H_
#define _STACK_H_

struct StackRecord;
typedef struct StackRecord *stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#define EMPTY_TOS (-1)
#define MIN_STACK_SIZE (5)

struct StackRecord{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

#endif 

##

##stackRecord.c

#include <stdlib.h>
#include "falaterror.h"
#include "stackRecord.h"

int IsEmpty(Stack S){
	return S -> TopOfStack == EMPTY_TOS;
}

int IsFull(Stack S){
	return S -> TopOfStack == S -> Capacity - 1;
}

Stack CreateStack(int MaxElements){
	Stack S;
	
	if(MaxElements < MIN_STACK_SIZE)
		Error("Stack Size is too small!");
	else{
		S = (Stack)malloc(sizeof(struct StackRecord));
		if(S == NULL)
			FalatError("Out of space!");
		
		S -> Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
		if(S -> Array == NULL)
			FalatError("Out of space!");
		
		S -> Capacity = MaxElements;
		MakeEmpty(S);
	}
	
	return S;
}

void DisposeStack(Stack S){
	if(S != NULL){
		free(S -> Array);
		free(S);
	}
}

void MakeEmpty(Stack S){
	S -> TopOfStack = EMPTY_TOS;
}

void Push(ElementType X, Stack S){
	if(IsFull(S))
		Error("Full Stack!");
	else
		S -> Array[++ S -> TopOfStack] = X;
}

ElementType Top(Stack S){
	if(!IsEmpty(S))
		return S -> Array[TopOfStack];
	else{
		Error("Empty Stack!");
		return 0; /*Return value used to avoid warning*/
	}
}

void Pop(Stack S){
	if(IsEmpty(S))
		Error("Empty Stack!");
	else
		S -> TopStack--;
}

ElementType TopAndPop(Stack S){
	if(!IsEmpty(S))
		return S -> Array[TopOfStack--];
	else{
		Error("Empty Stack!");
		return 0; /*Return value used to avoid warning*/
	}
}

##


Example Of Stack ADT


##characterMatch.c

//平衡符号
//仅作用于 [] () {}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CHAR_OBJECT_SIZE (3)
#define CODE_STRING_SIZE (100)
#define Error(str) FalatError(str)
#define FalatError(str) \
fprintf(stderr, "%s\n", str),exit(1)

struct node;
typedef char ElementType;
typedef struct node *PtrToNode;
typedef PtrToNode Stack;

struct node{
	ElementType element;
	PtrToNode next;
};

int IsEmpty(Stack S){
	return S -> next == NULL;
}

void MakeEmpty(Stack S){
	PtrToNode TmpCell;

	while(!IsEmpty(S)){
		TmpCell = S -> next;
		S -> next = S -> next -> next;
		free(TmpCell);
	}
}

Stack CreateStack(void){
	Stack S;
	
	S = (Stack)malloc(sizeof(struct node));
	if(S == NULL)
		FalatError("Out of space!");
	S -> next = NULL;
	MakeEmpty(S);
	return S;
}

void Push(ElementType X, Stack S){
	PtrToNode FirstCell;
	
	FirstCell = (PtrToNode)malloc(sizeof(struct node));
	if(FirstCell == NULL){
		FalatError("Out of space!");
	}
	else{
		FirstCell -> element = X;
		FirstCell -> next = S -> next;
		S -> next = FirstCell;
	}
}

ElementType Top(Stack S){
	if(!IsEmpty(S)){
		return S -> next -> element;
	}
	else{
		Error("Empty Stack!");
		return 0; /*Return value used to avoid warning*/
	}
}

void Pop(Stack S){
	PtrToNode TmpCell;

	if(IsEmpty(S)){
		Error("Empty Stack!");
	}
	else{
		TmpCell = S -> next;
		S -> next = S -> next -> next;
		free(TmpCell);
	}
}

void DisposeStack(Stack S){
	while(!IsEmpty(S))
		Pop(S);
	free(S);
}

int judgeIsCharacterObject(char c){
	int j;
	const char LeftCharacterObject[CHAR_OBJECT_SIZE] = {'[', '(', '{'};
	const char RightCharacterObject[CHAR_OBJECT_SIZE] = {']', ')', '}'};
	
	//左字符 返回 1 右字符 返回 2 没有 返回 0
	for(j = 0; j < CHAR_OBJECT_SIZE; j++)
		if(c == LeftCharacterObject[j])
			return 1;
		else if(c == RightCharacterObject[j])
			return 2;
		
	return 0;
}


int main(int argc,char *argv[]){
	int i, j;
	Stack s;
	char codeString[CODE_STRING_SIZE];
	
	s = CreateStack();
	scanf("%s", codeString);
	for(i = 0; codeString[i] != '\0'; i++){
		//两个相关性字符之间在ascii表上的值差距为1或者2
		switch( judgeIsCharacterObject(codeString[i]) ){
			case 0:
			break;
			case 1:
			Push(codeString[i], s);
			break;
			case 2:
			if(!IsEmpty(s)){
				if(abs(codeString[i] - Top(s)) <= 2)
					Pop(s);
				else{
					DisposeStack(s);
					Error("Character Mismatch!\n");
				}
			}
			else{
				DisposeStack(s);
				Error("Character Mismatch!\n");
			}
			break;
		}
	}
	
	if(IsEmpty(s))
		printf("Character Matching Successful!\n");
	else
		printf("Chararcter Mismatch!\n");
	DisposeStack(s);
	return 0;
}

##

逆波兰表达式 & 中缀表达式变成后缀（逆波兰）表达式


函数调用

实现递归的每一种程序设计语言中实际发生的事情其实全部由一个栈完成，函数调用的存储信息被称为活动记录或者栈帧
堆也是一种类似的形式，只是要手动获取，手动释放(没有手动释放堆空间也可能被系统释放)
在不检测栈溢出的语言和系统中，极易因为栈溢出而导致程序错误
如果是检测栈溢出的语言和系统中，因避免栈溢出而导致程序被暂停
