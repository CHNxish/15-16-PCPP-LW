#ifndef _SQ_QUEUE_ADT_H
#define _SQ_QUEUE_ADT_H_

typedef int ElementType;
typedef struct{
	int capacity;
	int front,rear;
	int size;
	ElementType *data;
}SqQueue, *PtrSqQueue;

PtrSqQueue CreateSqQueue(int maxElements);
int IsEmptySqQueue(PtrSqQueue queue);
int IsFullSqQueue(PtrSqQueue queue);
void DisposeSqQueue(PtrSqQueue queue);
void MakeEmptySqQueue(PtrSqQueue queue);
void EnSqQueue(ElementType element, PtrSqQueue queue);
ElementType FrontSqQueue(PtrSqQueue queue);
void DeSqQueue(PtrSqQueue queue);
ElementType FrontAndSqQueue(PtrSqQueue queue);
int SuccSqQueue(PtrSqQueue queue, int position);

#endif