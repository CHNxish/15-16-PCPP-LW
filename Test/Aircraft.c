/* Aircraft Landing and Landing Waiting Mod 飞机起落等待模式 */
/* 头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 宏定义 */
#define BASE    (-1)
#define QUEUESIZE (3)

/* 宏定义布尔类型 */
#define BOOL    int
#define TRUE    (1)
#define FALSE   (0)

/* 宏定义错误 */
#define Error(str) FatalError(str)
#define FatalError(str) \
fprintf(stderr, "%s", str), exit(1);

/* 函数声明 */

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

void DeSqQueue(PtrSqQueue queue, ElementType element){
    if(IsEmptySqQueue(queue))
        Error("Queue is Empty!\n");
    (queue -> front++) %= queue -> capacity;
    queue -> size--;
}

void ElementCopy(ElementType *dst, ElementType *src){
    dst -> symbol = src -> symbol;
    dst -> time = stc -> time;
    dst -> lt = src -> lt;
}

void DisposeSqEmpty(PtrSqQueue queue){
    if(queue != NULL){
        free(queue -> air);
        free(queue);
    }
}

/* 着落 起飞 */
typedef struct comeQueue{   // 着落等待队列
    PtrSqQueue cQueue1, cQueue2, cQueue3, cQueue4;
}ComeQueue;
typedef struct leaveQueue{  // 起飞等待队列
    PtrSqQueue lQueue1, lQueue2, lQueue3;
}LeaveQueue;

/* 解决问题 */
/*
**问题分析：机场有3条跑道0，1，2， 2号主要用于起飞，不得已也可以着落
**        有4个着落等待队列，一个队列中的飞机数目不超过3架     机油可用时间5-10
**        有3个起飞等待队列，一个队列中的飞机数目不超过3架     起飞时间6-8
*/
int main(void){
    /* 获取时间 */
    int runTime = 0;
    int programTime, over, lTime, rTime, dAir;    // 程序运行时间 飞机起飞降落成功数目 平均起飞时间 平均着落时间 坠毁飞机数目
    GetRange("Input running time of program: ", &programTime, 10000, 20000);
    
    /* 创建队列 */
    ComeQueue *cq;
    LeaveQueue *lq;
    
    cq -> cQueue1 = CreateSqQueue();
    cq -> cQueue2 = CreateSqQueue();
    cq -> cQueue3 = CreateSqQueue();
    cq -> cQueue4 = CreateSqQueue();
    lq -> lQueue1 = CreateSqQueue();
    lq -> lQueue2 = CreateSqQueue();
    lq -> lQueue3 = CreateSqQueue();
    
    /* 程序运行：着落等待队列 -> 机场内 -> 起飞等待队列 */
    int airNumber = 1;      // 飞机编号
    int runway0 = 0, runway1 = 0, runway2 = 0;
    /* 循环结束 programTime = 0 */
    while(runTime < programTime){
        AirComeAndLeave(cq, lq, &over, &lTime, &rTime, &dAir, &airNumber, \
                        &runway0, &runway1, &runway2, &runTime);
        runTime++;
    }
    
    /* 销毁队列  */
    DisposeSqEmpty(cq -> cQueue1);
    DisposeSqEmpty(cq -> cQueue2);
    DisposeSqEmpty(cq -> cQueue3);
    DisposeSqEmpty(cq -> cQueue4);
    DisposeSqEmpty(lq -> lQueue1);
    DisposeSqEmpty(lq -> lQueue2);
    DisposeSqEmpty(lq -> lQueue3);

    return 0;
}

AirComeAndLeave(ComeQueue *cq, LeaveQueue *lq, int *over, \
                int *lTime, int *rTime, int *dAir, int *airNumber, \
                int *runway0, int *runway1, int *runway2, int *runTime){
    ElementType element;    // 飞机属性
    
    /* 假设着陆等待队列没满，1单位时间来1架飞机 */
    srand( (unsigned)time(NULL) );
    element.lt = (LType)rand() % 2;
    element.symbol = airNumber++;
    element.time = rand() % 6 + 5;
    
    
    if(element.lt == TYPE1){
        if(IsEmptySqQueue(cq -> cQueue1)){
            EnSqQueue(cq -> cQueue1, element);
        }
        else if(IsEmptySqQueue(cq) -> cQueue2){
            EnSqQueue(cq -> cQueue2, element);
        }
    }
    else{
        if(IsEmptySqQueue(cq -> cQueue3)){
            EnSqQueue(cq -> cQueue3, element);
        }
        else if(IsEmptySqQueue(cq) -> cQueue4){
            EnSqQueue(cq -> cQueue4, element);
        }
    }
    
    if(runway)
}

int ScanfRange(char *str, int *integer, int min, int max){
    int c;
    
    printf("%s", str);
    scanf("%d", c);
    if(c < min || c > max)
        printf("Input number out of range!\n");
    *integer = c;
    return c;
}

void AirCOmeAndLeave();
