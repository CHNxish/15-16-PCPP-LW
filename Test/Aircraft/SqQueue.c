/* 顺序队列 实现 */
#include <stdlib.h>
#include "SqQueue.h"

PtrSqQueue CreateSqQueue(int capacity = QUEUESIZE){
    PtrSqQueue queue;
    queue = (PtrSqQueue)malloc(sizeof(SqQueue));
    if(queue == NULL)
        FatalError("Out of space!\n");
    queue -> air = (ElementType *)malloc(capacity * sizeof(ElementType));
    if(queue -> air == NULL)
        FatalError("Out of space!\n");
    queue -> capacity = capacity;
    MakeEmptySqQueue(queue);
    return queue;
}

void MakeEmptySqQueue(PtrSqQueue queue){
    if(queue == NULL)
        Error("Must used CreateSqQueue Function first!\n");
    queue -> size = 0;
    queue -> front = 1;
    queue -> rear = 0;
}

BOOL IsEmptySqQueue(PtrSqQueue queue){
    return  queue -> size == 0;
}

BOOL IsFullSqQueue(PtrSqQueue queue){
    return queue -> size == capacity;
}

void EnSqQueue(PtrSqQueue queue, ElementType element){
    if(IsFullSqQueue(queue))
        Error("Queue is Full!\n");
    (queue -> rear++) %= queue -> capacity;
    ElementCopy(&queue -> air[queue -> rear], &element);
    queue -> size++;
}

void DeSqQueue(PtrSqQueue queue){
    if(IsEmptySqQueue(queue))
        Error("Queue is Empty!\n");
    (queue -> front++) %= queue -> capacity;
    queue -> size--;
}

ElementType TopAndDeSqQueue(PtrSqQueue queue){
    ElementType element;

    if(IsEmptySqQueue(queue))
        Error("Queue is Empty!\n");
    ElementCopy(&element, &queue -> air[queue -> front]);
    (queue -> front++) %= queue -> capacity;
    queue -> size--;
    return element;
}

void ElementCopy(ElementType *dst, ElementType *src){
    dst -> symbol = src -> symbol;
    dst -> time = stc -> time;
    dst -> lt = src -> lt;
    dst -> caTime = str -> caTime;
}

void DisposeSqQueue(PtrSqQueue queue){
    if(queue != NULL){
        free(queue -> air);
        free(queue);
    }
}

int SizeSqQueue(PtrSqQueue queue){
    return queue -> size;
}
