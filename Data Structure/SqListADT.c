#include <stdlib.h>
#include "SqListADT.h"
#include "FalatError.h"

//初始化顺序表的结点
PtrSqList InitSqList(int maxElements){
    PtrSqList list;

    if(maxElements < MinSqListSize)
        Error("Sequence List size is too small!\n");

    list = (PtrSqList)malloc(sizeof(SqList));
    if(list == NULL)
        FalatError("Out of space!\n");
    list -> data = (ElementType *)malloc(sizeof(ElementType) * maxSize);
    if(list -> data == NULL)
        FalatError("Ouf of space!\n");
    list -> capacity = maxSize;
    MakeEmptySqList(list);

    return list;
}

//顺序表清空
void MakeEmptySqList(PtrSqList list){
    list -> length = 0;
}


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
ElementType RetrieveSqList(int position);
