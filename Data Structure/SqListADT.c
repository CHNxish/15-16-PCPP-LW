#include <stdlib.h>
#include "SqListADT.h"
#include "FalatError.h"

// 初始化顺序表的结点
PtrSqList InitSqList(int maxElements){
    PtrSqList list;

    if(maxElements < minSqListSize)
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

// 顺序表清空
void MakeEmptySqList(PtrSqList list){
    list -> length = 0;
}

// 检查顺序表是否是空
int IsEmptySqList(PtrSqList list){
    return list -> length == 0;
}

// 检查该结点是不是最后一个结点
int IsLastSqList(int position, PtrSqList list){
    return position == list -> length - 1;
}

// 找出首个包含该元素的结点
int FindSqList(ElementType element, PtrSqList list){
    int position;

    for(position = 0; position < list -> length; position++)
        if(list -> data[position] == element)
            break;

    if(position == list -> length)
        return NONE;
    else
        return position;
}

// 删除首个包含该元素的结点
void DeleteNodeSqList(ElementType element, PtrSqList list){
    int position;

    position = FindSqList(element, list);
    if(position != NONE){
        while(!IsLastSqList(position, list)){
            list -> data[position] = list -> data[position + 1];
            position++;
        }
        list -> length -= 1;
    }
}

// 找出首个包含该元素的前一结点
int FindPreviousSqList(ElementType element, PtrSqList list){
    int position;

    position = FindSqList(element, list);
    if(position == NONE)
        return NONE;
    //如果position为0，也就是首结点，返回-1(即NONE)
    else
        return position - 1;
}

// 在该结点后插入该元素
void InsertSqList(ElementType element, PtrSqList list, int position){
    int tmpCell;

    if(position + 1 <= list -> capacity - 1){
        tmpCell = position + 1;
        position = list -> length;
        while(position > tmpCell){
            list -> data[position] = list -> data[position - 1];
        }
        list -> data[tmpCell] = element;
        list -> length += 1;
    }
    else
        Error("Sequence list is full!\n");
}

// 删除顺序表
void DeleteSqList(PtrSqList list){
    list -> length = 0;
}

// 没有头结点，返回首结点，等同于FirstSqList
int HeaderSqList(PtrSqList list){
    return 0;
}

// 返回首节点
int FirstSqList(PtrSqList list){
    return 0;
}

// 返回下一结点
int AdvanceSqList(int position){
    return position + 1;
}

//返回该结点内元素
ElementType RetrieveSqList(int position, PtrSqList list){
    retutn list -> data[position];
}
