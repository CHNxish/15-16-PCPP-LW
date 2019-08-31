#include <stdlib.h>
#include "FatalError.h"
#include "LinkListADT.h"

// 初始化链表的结点
PtrLinkList InitLinkList(){
    PtrLinkList list;
    
    list = (PtrLinkList)malloc(sizeof(LinkList));
    if(list == NULL)
        FatalError("Out of space!\n");
    list -> next = NULL;
    MakeEmptyLinkList(list);
    return list;
}

// 链表清空
PtrLinkList MakeEmptyLinkList(PtrLinkList list){
    if(list == NULL)
        Error("Must use InitLinkList first!\n");
    else
        if(!IsEmptyLinkList(list))
            DeleteLinkList(list);
}

// 检查链表是否是空
int IsEmptyLinkList(PtrLinkList list){
    return list -> next == NULL;
}

// 检查该结点是否是最后一个结点
int IsLastLinkList(PtrLinkList list, PtrLinkList position){
    retutn position -> next == NULL;
}

// 找出首个包含该元素的结点
PtrLinkList FindLinkList(ElementType element, PtrLinkList list){
    PtrLinkList position;

    position = list -> next;
    while(position != NULL && position -> data != element)
        position = position -> next;

    return position;
}

// 删除首个包含该元素的结点
void DeleteNodeLinkList(ElementType element, PtrLinkList list){
    PtrLinkList position, tmpCell;
    
    position = FindPreviousLinkList(element, list);
    if(!IsLastLinkList(position, list)){
        tmpCell = position -> next;
        position -> next = position -> next -> next;
        free(tmpCell);
    }
}

// 找出首个包含该元素的前一结点
PtrLinkList FindPreviousLinkList(ElementType element, PtrLinkList list){
    PtrLinkList position;

    position = list;
    while(position -> next != NULL && position -> next -> data != element)
        position = position -> next;

    return position;
}

// 在该结点后插入该元素
void InsertLinkList(ElementType element, PtrLinkList list, PtrLinkList position){
    PtrLinkList tmpCell;

    tmpCell = InitLinkList();
    tmpCell -> data = element;
    tmpCell -> next = position -> next;
    position -> next = tmpCell;
}

// 删除链表
void DeleteLinkList(PtrLinkList list){
    PtrLinkList position, tmpCell;

    position = list -> next;
    while(position != NULL){
        tmpCell = position;
        position = position -> next;
        free(tmpCell);
    }
    free(list);
}

// 返回头结点
PtrLinkList HeaderLinkList(PtrLinkList list){
    return list;
}

// 返回首结点
PtrLinkList FirstLinkList(PtrLinkList list){
    return list -> next;
}

// 返回下一结点
PtrLinkList AdvanceLinkList(PtrLinkList position){
    return position -> next;
}

// 返回该结点内元素
ElementType RetrieveLinkList(PtrLinkList list, PtrLinkList position){
    return position -> data;
}
