#ifndef _SQ_STACK_ADT_H_
#define _SQ_STACK_ADT_H_

#define BASE (-1) //栈底

typedef int ElementType;
typedef struct{
	int capacity;
	int top;
	ElementType *data;
}SqStack, *PtrSqStack;

PtrSqStack CreateSqStack(int maxElements);
int IsEmptySqStack(PtrSqStack stack);
int IsFullSqStack(PtrSqStack stack);
void DisposeSqStack(PtrSqStack stack);
void MakeEmptySqStack(PtrSqStack stack);
void PushSqStack(ElementType element, PtrSqStack stack);
ElementType TopSqStack(PtrSqStack stack);
void PopSqStack(PtrSqStack stack);
ElementType TopAndPopSqStack(PtrSqStack stack);

#endif;