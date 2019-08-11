#ifndef _LINK_LIST_ADT_H
#define _LINK_LIST_ADT_H

typedef int ElementType;
typedef struct LNode{
    ElementType data;
    struct LNode *next;
}LinkList, *PtrLinkList;

PtrLinkList InitLinkList();
PtrLinkList MakeEmptyLinkList(PtrLinkList list);
int IsEmptyLinkList(PtrLinkList list);
int IsLastLinkList(PtrLinkList list, PtrLinkList position);
PtrLinkList FindLinkList(ElementType element, PtrLinkList list);
void DeleteNodeLinkList(ElementType element, PtrLinkList list);
PtrLinkList FindPreviousLinkList(ElementType element, PtrLinkList list);
void InsertLinkList(ElementType element, PtrLinkList list, PtrLinkList position);
void DeleteLinkList(PtrLinkList list);
PtrLinkList HeaderLinkList(PtrLinkList list);
PtrLinkList FirstLinkList(PtrLinkList list);
PtrLinkList AdvanceLinkList(PtrLinkList position);
ElementType RetrieveLinkList(PtrLinkList list, PtrLinkList position);

#endif
