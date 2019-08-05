#ifndef _LIST_ADT_H
#define _LIST_ADT_H
#define MAXSIZE 1000

//定义ElemType为int
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList, *PtrSqList

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList, *PtrLinkList;

typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DoubleLinkList, *PtrDoubleLinkList;

LinkList *InitList();
void DestortList(LinkList *LP);
void ClearList(LinkList *LP);
int ListEmpty(LinkList L);
int ListLength(LinkList L);
ElemType GetElem(LinkList L, int Position);


#endif
