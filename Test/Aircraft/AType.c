#include <stdlib.h>
#include <time.h>
#include "AType.h"

void AirCome(ComeQueue *cq, int *airNumber, int *runTime){
	ElementType air;

	air -> time = *runTime;
	air -> symbol = (*airNumber)++;
	srand((unsigned)time(NULL));
	air -> caTime = rand() % 10 + 30;

	if(IsFullSqQueue(cq -> cQueue1) == FALSE || IsFullSqQueue(cq -> cQueue2) == FALSE){
		air -> lt = TYPE1;
		if(SizeSqQueue(cq -> cQueue1) <= SizeSqQueue(cq -> cQueue2)){
			EnSqQueue(cq -> cQueue1, air);
		}
		else{
			EnSqQueue(cq -> cQueue2, air);
		}
		printf("Air No.%d is come!\n", air -> symbol);
	}
	else if(IsFullSqQueue(cq -> cQueue3) == FALSE || IsFullSqQueue(cq -> cQueue4) == FALSE){
		air -> lt = TYPE2;
		if(SizeSqQueue(cq -> cQueue3) <= SizeSqQueue(cq -> cQueue4)){
			EnSqQueue(cq -> cQueue3, air);
		}
		else{
			EnSqQueue(cq -> cQueue4, air);
		}
		printf("Air No.%d is come!\n", air -> symbol);
	}
	else{
		(*airNumber)--;
	}
}

void AirTakeOffOrLand(ComeQueue *cq, LeaveQueue *lq, int *runway0, int *runway1, int *runway2){
	/* 跑道时间先自减 */
	if(*runway0 > 0) (*runway0)--;
	if(*runway1 > 0) (*runway1)--;
	if(*runway2 > 0) (*runway2)--;

	/* 起飞或下降 */
	if(*runway0 == 0){
		
	}

	if(*runway1 == 0){

	}

	if(*runway2 == 0){
		
	}
}

ComeQueue *CreateComeQueue(void){
	ComeQueue *cq;
	cq = (ComeQueue *)malloc(sizeof(ComeQueue))
	if(cq == NULL)
		FatalError("Ouf of space");

	cq -> cQueue1 = CreateSqQueue();
	cq -> cQueue2 = CreateSqQueue();
	cq -> cQueue3 = CreateSqQueue();
	cq -> cQueue4 = CreateSqQueue();

	return cq;
}
void DisposeComeQueue(ComeQueue *cq){
	if(cq != NULL){
		DisposeSqQueue(cq -> cQueue1);
		DisposeSqQueue(cq -> cQueue2);
		DisposeSqQueue(cq -> cQueue3);
		DisposeSqQueue(cq -> cQueue4);
		free(cq);
	}
}

LeaveQueue *CreateLeaveQueue(void){
	LeaveQueue *lq;
	lq = (LeaveQueue *)malloc(sizeof(LeaveQueue))
	if(lq == NULL)
		FatalError("Ouf of space");

	lq -> lQueue1 = CreateSqQueue();
	lq -> lQueue2 = CreateSqQueue();
	lq -> lQueue3 = CreateSqQueue();

	return lq;
}
void DisposeLeaveQueue(LeaveQueue *lq){
	if(lq != NULL){
		DisposeLeaveQueue(lq -> lQueue1);
		DisposeLeaveQueue(lq -> lQueue2);
		DisposeLeaveQueue(lq -> lQueue3);
		free(lq);
	}
}
