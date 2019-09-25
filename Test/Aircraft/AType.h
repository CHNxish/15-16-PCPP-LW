#ifndef _A_TYPE_H_
#define _A_TYPE_H_

#include "SqQueue.h"

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

/* 着落 起飞 */
typedef struct comeQueue{   // 着落等待队列
    PtrSqQueue cQueue1, cQueue2, cQueue3, cQueue4;
}ComeQueue;
typedef struct leaveQueue{  // 起飞等待队列
    PtrSqQueue lQueue1, lQueue2, lQueue3;
}LeaveQueue;

void AirCome(ComeQueue *cq, int *airNumber, int *runTime);
void AirTakeOffOrLand(ComeQueue *cq, LeaveQueue *lq, int *runway0, int *runway1, int *runway2);

ComeQueue *CreateComeQueue(void);
void DisposeComeQueue(ComeQueue *cq);
LeaveQueue *CreateLeaveQueue(void);
void DisposeLeaveQueue(LeaveQueue *lq);

#endif
