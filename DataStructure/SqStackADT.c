#include <stdlib.h>
#include "SqStackADT.h"
#include "FatalError.h"
const int  minSqStackSize = 5;

// 初始化顺序栈的结点
PtrSqStack CreateSqStack(int maxElements){
	PtrSqStack stack;

	if(maxElements < minSqStackSize)
		Error("Sequence Stack size is too small!\n");

	stack = (PtrSqStack)malloc(sizeof(SqStack));
    if(stack == NULL)
        FalatError("Out of space!\n");
    stack -> data = (ElementType *)malloc(sizeof(ElementType) * maxElements);
    if(stack -> data == NULL)
        FalatError("Ouf of space!\n");
    list -> capacity = maxElements;
    MakeEmptySqStack(stack);
	return stack;
}

// 检查顺序栈是否是空
int IsEmptySqStack(PtrSqStack stack){
	return stack -> top == BASE;
}

// 检查顺序栈是否是满
int IsFullSqStack(PtrSqStack stack){
	return stack -> top == stack -> capacity;
}

// 删除顺序栈
void DisposeSqStack(PtrSqStack stack){
	if(stack != NULL){
		free(stack -> data);
		free(stack)
	}
}

// 顺序栈清空
void MakeEmptySqStack(PtrSqStack stack){
	if(stack == NULL)
        Error("Must use CreateSqStack first!\n");
    stack -> top = BASE;
}

// 入栈
void PushSqStack(ElementType element, PtrSqStack stack){
	if(IsFullSqStack(stack))
		Error("Full Stack!\n");
	else
		stack -> data[++stack -> top] = element;
}

// 返回栈顶首个元素
ElementType TopSqStack(PtrSqStack stack){
	if(!IsEmptySqStack(stack))
		return stack -> data[stack -> top];
	Error("Empty Stack!\n");
	return 0; 	/*Return value used to avoid warning*/
}

// 出栈
void PopSqStack(PtrSqStack stack){
	if(!IsEmptySqStack(stack))
		--stack -> top;
	else
		Error("Empty Stack!\n");
}

// 返回栈顶元素且出栈
ElementType TopAndPopSqStack(PtrSqStack stack){
	if(!IsEmptySqStack(stack))
		return stack -> data[stack -> top--];
	Error("Empty Stack!\n");
	return 0; 	/*Return value used to avoid warning*/
}