#ifndef _LINK_QUEUE_ADT_H
#define _LINK_QUEUE_ADT_H

typedef int ElementType;
typedef struct QNode{
	ElementType data;
	struct QNode *next;
}QueueNode, *PtrQueueNode;
typedef struct{
	QueueNode *front;
	QueueNode *rear;
}LinkQueue, *PtrLinkQueue;

PtrLinkQueue CreateLinkQueue();
int IsEmptyLinkQueue(PtrLinkQueue queue);
void DisposeLinkQueue(PtrLinkQueue queue);
void MakeEmptyLinkQueue(PtrLinkQueue queue);
void EnLinkQueue(ElementType element, PtrLinkQueue queue);
ElementType FrontLinkQueue(PtrLinkQueue queue);
void DeLinkQueue(PtrLinkQueue queue);
ElementType FrontAndDeLinkQueue(PtrLinkQueue queue);

#endif