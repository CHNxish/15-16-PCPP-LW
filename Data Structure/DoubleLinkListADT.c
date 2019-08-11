#include <stdlib.h>
#include "DoubleLinkListADT.h"
#include "FatalError.h"

PtrDoubleLinkList InitDoubleLinkList(){
    PtrDoubleLinkList list;
    list = (PtrDoubleLinkList)malloc(sizeof(DoubleLinkList));
    if(list == NULL)
        FalatError("Out of space!\n");
    list -> prior = list;
    list -> next = list;
    MakeEmptyDoubleLinkList(list);
    return list;
}

PtrDoubleLinkList MakeEmptyDoubleLinkList(PtrDoubleLinkList list){
    if(list == NULL)
        Error("Must use InitDoubleLinkList first!\n");
    else
        if(!IsEmptyDouble(list))
            DeleteDoubleLinkList(list);
}

int IsEmptyDoubleLinkList(PtrDoubleLinkList list){
    return list -> next == list;
}

int IsLastDoubleLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position){
    return position -> next == list -> next;
}

PtrDoubleLinkList FindDoubleLinkList(ElementType element, PtrDoubleLinkList list){
    PtrDoubleLinkList position;

    position = list;
    if(position == NULL)
        return NULL
    else{
        while(position -> data != element && )
    }
}

void DeleteNodeDoubleLinkList(ElementType element, PtrDoubleLinkList list);
PtrDoubleLinkList FindPreviousDoubleLinkList(ElementType element, PtrDoubleLinkList list);
void InsertDoubleLinkList(ElementType element, PtrDoubleLinkList list, PtrDoubleLinkList position);
void DeleteDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList HeaderDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList FirstDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList AdvanceDoubleLinkList(PtrDoubleLinkList position);
ElementType RetrieveLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position);
