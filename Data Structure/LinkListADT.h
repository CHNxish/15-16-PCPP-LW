#ifndef _LINK_LIST_ADT_H
#define _LINK_LIST_ADT_H

typedef int ElementType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList, *PtrLinkList;

PtrLinkList InitLinkList();
PtrLinkList MakeEmptyLinkList(PtrLinkList list);
int IsEmptyLinkList(PtrLinkList list);
PtrLinkList FindLinkList(ElementType element, PtrLinkList list);
void DeleteNodeLinkList(ElementType element, PtrLinkList list);
PtrLinkList FindPrevious(ElementType element, PtrLinkList list);
void InsertLinkList(ElementType element, PtrLinkList list, PtrLinkList position);

#endif
