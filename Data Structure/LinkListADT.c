#include <stdlib.h>
#include "FalatError.h"
#include "LinkListADT.h"

// 初始化链表的结点
PtrLinkList InitLinkList(){
    PtrLinkList list;
    
    list = (PtrLinkList)malloc(sizeof(LinkList));
    if(list == NULL)
        FalatError("Out of space!\n");
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
PtrLinkList FindLinkList(ElementType element, PtrLinkList list){
    return position -> next == NULL;
}

// 
void DeleteNodeLinkList(ElementType element, PtrLinkList list){
    PtrLinkList position;
    
    position = list -> next;
    while(position != NULL && position -> data != element)
        position = position -> next;

    return position;
}

// 删除首个包含该元素的结点
PtrLinkList FindPrevious(ElementType element, PtrLinkList list){
    
}


void InsertLinkList(ElementType element, PtrLinkList list, PtrLinkList position){

}


void DeleteLinkList(PtrLinkList list){

}


PtrLinkList HeaderLinkList(PtrLinkList list){

}


PtrLinkList FirstLinkList(PtrLinkList list){

}


PtrLinkList AdvanceLinkList(PtrLinkList position){

}


ElementType RetrieveLinkList(PtrLinkList list, PtrLinkList position){

}
