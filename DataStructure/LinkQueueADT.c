#include <stdlib.h>
#include "LinkQueueADT.h"
#include "FatalError.h"

// 初始化链队列的结点
PtrLinkQueue CreateLinkQueue(){
	PtrLinkQueue queue;

	queue = (PtrLinkQueue)malloc(sizeof(LinkQueue));
	if(queue == NULL)
		FatalError("Out of space!\n");
	MakeEmptyLinkQueue(queue);
	return queue;
}

// 检查链队列是否是空
int IsEmptyLinkQueue(PtrLinkQueue queue){
	return queue -> front == NULL;
}

// 删除链队列
void DisposeLinkQueue(PtrLinkQueue queue){
	if(queue != NULL){
		while(!IsEmptyLinkQueue(queue))
			DeLinkQueue(queue);
		free(queue);
	}
}

// 链队列清空
void MakeEmptyLinkQueue(PtrLinkQueue queue){
	if(queue == NULL)
		Error("Must use CreateLinkQueue first!\n");
	else{
		while(!IsEmptyLinkQueue(queue))
			DeLinkQueue(queue);
	}
}

// 入队列
void EnLinkQueue(ElementType element, PtrLinkQueue queue){
	PtrQueueNode tmpCell;

	tmpCell = (PtrQueueNode)malloc(QueueNode);
	if(tmpCell == NULL)
		FalatError("Out of space!");
	tmpCell -> data = element;
	tmpCell -> next = NULL;
	if(IsEmptyLinkQueue(queue)){
		queue -> front = tmpCell;
		queue -> rear = tmpCell;
	}
	else{
		queue -> rear -> next = tmpCell;
		queue -> rear = queue -> rear -> next;
	}
}

// 返回链队列首个元素
ElementType FrontLinkQueue(PtrLinkQueue queue){
	if(!IsEmptyLinkQueue(queue))
		return queue -> front -> data;	
	Error("Empty Queue!");
	return 0; 	/*Return value used to avoid warning*/
}

// 出队列
void DeLinkQueue(PtrLinkQueue queue){
	PtrLinkQueue tmpCell;

	if(IsEmptyLinkQueue(queue))
		Error("Empty Queue!\n");
	else{
		tmpCell = queue -> front；
		if(queue -> front == queue -> next)
			queue -> front = queue -> next = NULL;
		else
			queue -> front = queue -> front -> next;
		free(tmpCell);
	}
}

// 返回链队列首个元素且出队列
ElementType FrontAndDeLinkQueue(PtrLinkQueue queue){
	ElementType element;
	PtrQueueNode tmpCell;

	if(IsEmptyLinkQueue(queue)){
		Error("Empty Queue!\n");
		return 0;	/*Return value used to avoid warning*/
	}
	else{
		tmpCell = queue -> front;
		element = tmpCell -> data;
		if(queue -> front == queue -> next)
			queue -> front = queue -> next = NULL;
		else
			queue -> front = queue -> front -> next;
		free(tmpCell);
		return element;
	}
}

#endif