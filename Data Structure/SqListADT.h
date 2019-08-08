#ifndef _SQ_LIST_ADT_H_
#define _SQ_LIST_ADT_H_

typedef int ElementType;
typedef struct{
    int capacity;
    int length;
    ElementType *data;
}SqList, *PtrSqList;

PtrSqList InitSqList(int maxSize);
PtrSqList MakeEmptySqList(PtrSqList list);
int IsEmptySqList(PtrSqList list);
int IsLastSqList(int position, PtrSqList list);
int Find(ElementType element, PtrSqList list);
void DeleteNodeSqList(ElementType element, PtrSqList list);
int FindPreviousSqList(ElementType element, PtrSqList list);
void InsertSqList(ElementType element, PtrSqList list, int position);
void DeleteSqList(PtrSqList list);
int HeaderSqList()


#endif
