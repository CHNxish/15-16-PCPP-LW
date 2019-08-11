#ifndef _DOUBLE_LINK_LIST_ADT_H
#define _DOUBLE_LINK_LIST_ADT_H

typedef int ElementType;
typedef struct DNode{
    ElementType data;
    struct DNode *proir;
    struct DNode *next;
}DoubleLinkList, *PtrDoubleLinkList;

PtrDoubleLinkList InitDoubleLinkList();
PtrDoubleLinkList MakeEmptyDoubleLinkList(PtrDoubleLinkList list);
int IsEmptyDoubleLinkList(PtrDoubleLinkList list);
int IsLastDoubleLinkList(PtrDoubleLinkList list, PtrDoubleLinkList position);
PtrDoubleLinkList FindLinkList(ElementType element, PtrDoubleLinkList list);
void DeleteNodeDoubleLinkList(ElementType element, PtrDoubleLinkList list);
PtrDoubleLinkList FindPreviousDouble(ElementType element, PtrLinkList list);
void InsertLinkList(ElementType element, PtrLinkList list, PtrLinkList position);
void DeleteLinkList(PtrLinkList list);
PtrLinkList HeaderLinkList(PtrLinkList list);
PtrLinkList FirstLinkList(PtrLinkList list);
PtrLinkList AdvanceLinkList(PtrLinkList position);
ElementType RetrieveLinkList(PtrLinkList list, PtrLinkList position);

#endif
