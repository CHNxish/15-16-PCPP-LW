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

##list.h

#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

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

struct Node{
	ElementType Element;
	Position Next;
};

#endif

##
