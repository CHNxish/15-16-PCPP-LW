#ifndef _SQ_LIST_ADT_H_
#define _SQ_LIST_ADT_H_

#define NONE (-1) //不存在结点

typedef int ElementType;
typedef struct{
    int capacity;
    int length;
    ElementType *data;
}SqList, *PtrSqList;

PtrSqList InitSqList(int maxSize);
void MakeEmptySqList(PtrSqList list);
int IsEmptySqList(PtrSqList list);
int IsLastSqList(int position, PtrSqList list);
int FindSqList(ElementType element, PtrSqList list);
void DeleteNodeSqList(ElementType element, PtrSqList list);
int FindPreviousSqList(ElementType element, PtrSqList list);
void InsertSqList(ElementType element, PtrSqList list, int position);
void DeleteSqList(PtrSqList list);
int HeaderSqList(PtrSqList list);
int FirstSqList(PtrSqList list);
int AdvanceSqList(int position);
ElementType RetrieveSqList(PtrSqList list, int position);


#endif
