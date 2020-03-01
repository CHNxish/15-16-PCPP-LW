#ifndef _LINK_STACK_ADT_H_
#define _LINK_STACK_ADT_H_

typedef int ElementType;
typedef struct SNode{
	ElementType data;
	struct SNode *next;
}LinkStack, *PtrLinkStack;

PtrLinkStack CreateLinkStack();
int IsEmptyLinkStack(PtrLinkStack stack);
void DisposeLinkStack(PtrLinkStack stack);
void MakeEmptyLinkStack(PtrLinkStack stack);
void PushLinkStack(ElementType element, PtrLinkStack stack);
ElementType TopLinkStack(PtrLinkStack stack);
void PopLinkStack(PtrLinkStack stack);
ElementType TopAndPopLinkStack(PtrLinkStack stack);

#endif