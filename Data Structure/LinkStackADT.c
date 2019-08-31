#include <stdlib.h>
#include "LinkStackADT.h"
#include "FatalError.h"

// 初始化链栈的结点
PtrLinkStack CreateLinkStack(){
	PtrLinkStack stack;
	stack = (PtrLinkStack)malloc(sizeof(LinkStack));
	if(stack == NULL)
		FatalError("Out of space!\n");
	stack -> next = NULL;
	MakeEmptyLinkStack(stack);
	return stack;
}

// 检查链栈是否是空
int IsEmptyLinkStack(PtrLinkStack stack){
	return stack -> next == NULL;
}

// 删除链栈
void DisposeLinkStack(PtrLinkStack stack){
	if(stack != NULL){
		while(!IsEmptyLinkStack(stack))
			PopLinkStack(stack);
		free(stack);
	}
}

// 链栈清空
void MakeEmptyLinkStack(PtrLinkStack stack){
	if(stack == NULL)
		Error("Must use CreateLinkStack first!\n");
	else
		while(!IsEmptyLinkStack(stack))
			PopLinkStack(stack);
}

// 入栈
void PushLinkStack(ElementType element, PtrLinkStack stack){
	PtrLinkStack tmpCell;

	tmpCell = CreateLinkStack();
	tmpCell -> data = element;
	tmpCell -> next = stack -> next;
	stack -> next = tmpCell;
}

// 返回栈顶元素
ElementType TopLinkStack(PtrLinkStack stack){
	if(!IsEmptyLinkStack(stack))
		return stack -> next -> data;
	Error("Empty Stack!\n");
	return 0;	/*Return value used to avoid warning*/
}

// 出栈
void PopLinkStack(PtrLinkStack stack){
	PtrLinkStack tmpCell;

	if(IsEmptyLinkStack(stack))
		Error("Empty Stack!\n");
	else{
		tmpCell = stack -> next;
		stack -> next = stack -> next -> next;
		free(tmpCell);
	}
}

// 返回栈顶元素且出栈
ElementType TopAndPopLinkStack(PtrLinkStack stack){
	ElementType element;
	PtrLinkStack tmpCell;

	if(IsEmptyLinkStack(stack)){
		Error("Empty Stack!\n");
		return 0; 	/*Return value used to avoid warnning*/
	}
	else{
		tmpCell = stack -> next;
		element = tmpCell -> data;
		stack -> next = stack -> next -> next;
		free(tmpCell);
		return element;
	}
}