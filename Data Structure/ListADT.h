#ifndef _LIST_ADT_H
#define _LIST_ADT_H
#define MAXSIZE 1000
#define None -32768
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

typedef PtrLinkList List;

List InitList();
void DestortList(List L);
void ClearList(List L);
int ListEmpty(List L);
int ListLength(List L);
ElemType GetElem(List L, int Position);
LinkList *LocateElem(List L, ElemType x, int (*compare)(ElemType a, ElemType b));
ElemType PriorElem(List L, ElemType x);
ElemType NextElem(List L, ElemType x);
void ListInsert(List L, int position, ElemType x);
ElemType ListDelete(List L, int position);
//void ListTraverse(List L, void (*visit)());

#endif
