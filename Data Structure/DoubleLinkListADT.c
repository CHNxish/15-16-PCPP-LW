#include <stdlib.h>
#include "DoubleLinkListADT.h"
#include "FatalError.h"

PtrDoubleLinkList InitDoubleLinkList(){
    PtrDoubleLinkList list;
    list = (PtrDoubleLinkList)malloc(sizeof(DoubleLinkList));
    if(list == NULL)
        FalatError("Out of space!\n");
    list -> prior = NULL;
    list -> next = NULL;
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
    
}

int IsLastDoubleLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position);
PtrDoubleLinkList FindLinkList(ElementType element, PtrDoubleLinkList list);
void DeleteNodeDoubleLinkList(ElementType element, PtrDoubleLinkList list);
PtrDoubleLinkList FindPreviousDoubleLinkList(ElementType element, PtrDoubleLinkList list);
void InsertDoubleLinkList(ElementType element, PtrDoubleLinkList list, PtrDoubleLinkList position);
void DeleteDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList HeaderDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList FirstDoubleLinkList(PtrDoubleLinkList list);
PtrDoubleLinkList AdvanceDoubleLinkList(PtrDoubleLinkList position);
ElementType RetrieveLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position);
