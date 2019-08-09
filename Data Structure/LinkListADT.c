#include <stdlib.h>
#include "FalatError.h"
#include "LinkListADT.h"

//初始化链表的结点
PtrLinkList InitLinkList(){
    PtrLinkList list;
    
    list = (PtrLinkList)malloc(sizeof(LinkList));
    if(list == NULL)
        FalatError("Out of space!\n");
    list -> next = NULL;
    MakeEmptyLinkList(list);
    return list;
}


PtrLinkList MakeEmptyLinkList(PtrLinkList list){
    if(list == NULL)
        Error("Must use InitLinkList first!\n");
    else
        if(!IsEmptyLinkList(list))
            DeleteLinkList(list);
}


int IsEmptyLinkList(PtrLinkList list){

}


PtrLinkList FindLinkList(ElementType element, PtrLinkList list){

}


void DeleteNodeLinkList(ElementType element, PtrLinkList list){

}


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
