#include <stdlib.h>
#include "SqQueueADT.h"
#include "FatalError.h"
const int minSqQueueSize = 5;

// 初始化顺序队列的结点
PtrSqQueue CreateSqQueue(int maxElements){
	PtrSqQueue queue;

	if(maxElements < minSqQueueSize)
		Error("Sequence Queue size is too small!\n");

	queue = (PtrSqQueue)malloc(sizeof(SqQueue));
	if(queue == NULL)
		FalatError("Out of space!\n");
	queue -> data = (ElementType *)malloc(sizeof(ElementType) * maxElements);
	if(queue -> data == NULL)
		FalatError("Out of space!\n");
	queue -> capacity = maxElements;
	MakeEmptySqQueue(queue);

	return queue;
}

// 检查顺序表是否是空
int IsEmptySqQueue(PtrSqQueue queue){
	return queue -> size == 0;
}

// 检查顺序队列是否是满
int IsFullSqQueue(PtrSqQueue queue){
	return queue -> size == capacity;
}

// 删除顺序队列
void DisposeSqQueue(PtrSqQueue queue){
	if(queue != NULL){
        free(queue -> data);
		free(queue);
	}
}

// 顺序队列清空
void MakeEmptySqQueue(PtrSqQueue queue){
	if(queue == NULL)
		Error("Must use CreateSqQueue first!\n");
	else{
		queue -> size = 0;
		queue -> front = 1;
		queue -> rear = 0;
	}
}

// 入顺序队列
void EnSqQueue(ElementType element, PtrSqQueue queue){
	if(IsFullSqQueue(queue))
		Error("Full Stack!\n");
	else{
		queue -> size++;
		queue -> rear = SuccSqQueue(queue, queue -> rear);
		queue -> data[queue -> rear] = element;
	}
}

// 返回顺序队列首个元素
ElementType FrontSqQueue(PtrSqQueue queue){
	if(!IsEmptySqQueue(queue))
		return queue -> data[queue -> front];
	Error("Empty Queue!\n");
	return 0; 	/*Return value used to avoid warning*/
}

// 出顺序队列
void DeSqQueue(PtrSqQueue queue){
	if(IsEmptySqQueue(queue))
		Error("Empty Queue!\n");
	else{
		queue -> size--;
		queue -> front = SuccSqQueue(queue, queue -> front);
	}
}

// 返回顺序队列首个元素且出队列
ElementType FrontAndSqQueue(PtrSqQueue queue){
	int position;

	if(IsEmptySqQueue(queue)){
		Error("Empty Queue!\n");
		return 0; 	/*Return value used to avoid warnning*/
	}
	else{
		queue -> size--;
		position = queue -> front;
		queue -> front = SuccSqQueue(queue, queue -> front);
		return queue -> data[position];
	}
}

// 进位
int SuccSqQueue(PtrSqQueue queue, int position){
	if(++position == queue -> capacity)
		position = 0;

	return position;
}
