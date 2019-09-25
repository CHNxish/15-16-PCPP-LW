/* 顺序队列 定义 */
#ifndef _SQ_QUEUE_H_
#define _SQ_QUEUE_H_

/* 宏定义 */
#ifndef _MY_DEFINE_C_
#define _MY_DEFINE_C_

/* 宏定义布尔类型 */
#define BOOL 	int
#define TRUE 	(1)
#define FALSE 	(-1)

/* 宏定义错误 */
#define Error(str) FatalError(str)
#define FatalError(str) \
fprintf(stderr, "%s", str), exit(1);

#endif

#define QUEUESIZE (3)

/* 问题模型中的队列定义和函数 */
typedef enum {TYPE1, TYPE2} LType;
typedef struct{
    LType lt;   // 飞机降落类型
    int symbol; // 飞机编号
    int caTime; // 可以等待时间
    int time;   // 到来的时间
}AircraftProperty;
typedef AircraftProperty ElementType;
typedef struct{
    int capacity;
    int front, rear;
    int size;
    ElementType *air;
}SqQueue, *PtrSqQueue;

PtrSqQueue CreateSqQueue(int capacity = QUEUESIZE);
void MakeEmptySqQueue(PtrSqQueue queue);
BOOL IsEmptySqQueue(PtrSqQueue queue);
BOOL IsFullSqQueue(PtrSqQueue queue);
void EnSqQueue(PtrSqQueue queue, ElementType element);
void DeSqQueue(PtrSqQueue queue);
ElementType TopAndDeSqQueue(PtrSqQueue queue);
void DisposeSqQueue(PtrSqQueue queue);
int SizeSqQueue(PtrSqQueue queue);
void ElementType(ElementType *dst, ElementType *src);

#endif
