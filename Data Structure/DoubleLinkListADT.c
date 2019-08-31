#include <stdlib.h>
#include "DoubleLinkListADT.h"
#include "FatalError.h"

// 初始化双循环链表
PtrDoubleLinkList InitDoubleLinkList(){
    PtrDoubleLinkList list;
    list = (PtrDoubleLinkList)malloc(sizeof(DoubleLinkList));
    if(list == NULL)
        FatalError("Out of space!\n");
    list -> prior = NULL;
    list -> next = NULL;
    MakeEmptyDoubleLinkList(list);
    return list;
}

// 双循环链表清空
PtrDoubleLinkList MakeEmptyDoubleLinkList(PtrDoubleLinkList list){
    if(list == NULL)
        Error("Must use InitDoubleLinkList first!\n");
    else
        if(!IsEmptyDouble(list))
            DeleteDoubleLinkList(list);
}

// 检查双循环链表是否是空
int IsEmptyDoubleLinkList(PtrDoubleLinkList list){
    return list -> next == NULL;
}

// 检查该结点是否是最后一个结点
int IsLastDoubleLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position){
    return position -> next == list -> next;
}

// 找出首个包含该元素的结点
PtrDoubleLinkList FindDoubleLinkList(ElementType element, PtrDoubleLinkList list){
    PtrDoubleLinkList position;

    position =  list -> next;
    if(position != NULL)
        while(position -> data != element){
            if(!IsLastDoubleLinkList(list, position))
                position = position -> next;
            else{
                position = NULL;
                break;
            }
        }

    return position;
}

// 删除首个包含该元素的结点
void DeleteNodeDoubleLinkList(ElementType element, PtrDoubleLinkList list){
    PtrDoubleLinkList position, tmpCell;

    tmpCell = FindDoubleLinkList(element, list);
    if(tmpCell != NULL){
        position = tmpCell -> prior;
        position -> next = tmpCell -> next;
        tmpCell -> next -> prior = position;
        free(tmpCell);
    }
}

// 找出首个包含该元素的前一结点
PtrDoubleLinkList FindPreviousDoubleLinkList(ElementType element, PtrDoubleLinkList list){
    PtrDoubleLinkList position;

    position = FindDoubleLinkList(element, list);
    if(position == NULL)
        return position;
    else
        return position -> prior;
}

// 在该结点后插入该元素
void InsertDoubleLinkList(ElementType element, PtrDoubleLinkList list, PtrDoubleLinkList position){
    PtrDoubleLinkList tmpCell;

    tmpCell = InitDoubleLinkList();
    tmpCell -> data = element;
    tmpCell -> next = position -> next;
    tmpCell -> prior = position;
    position -> next = tmpCell;
    tmpCell -> next -> prior = tmpCell;
}

// 删除链表
void DeleteDoubleLinkList(PtrDoubleLinkList list){
    PtrDoubleLinkList position, tmpCell;

    position = list -> next;
    while(!IsLastDoubleLinkList(list, position)){
        tmpCell = position;
        position = positon -> next;
        free(tmpCell);
    }
    free(position);
}

// 返回头结点
PtrDoubleLinkList HeaderDoubleLinkList(PtrDoubleLinkList list){
    return list;
}

//返回首结点
PtrDoubleLinkList FirstDoubleLinkList(PtrDoubleLinkList list){
    return list -> next;
}

// 返回下一结点
PtrDoubleLinkList AdvanceDoubleLinkList(PtrDoubleLinkList position){
    return position -> next;
}

//返回该结点内元素
ElementType RetrieveLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position){
    return position -> data;
}