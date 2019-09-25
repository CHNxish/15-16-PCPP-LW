/* Aircraft Landing and Landing Waiting Mod 飞机起落等待模式 */       
/* 头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ScanfRange(char *str, int *integer, int min, int max);
/* 解决问题 */
/*
**问题分析：机场有3条跑道0，1，2， 2号主要用于起飞，不得已也可以着落
**        有4个着落等待队列，一个队列中的飞机数目不超过3架     机油可用时间30-40
**        有3个起飞等待队列，一个队列中的飞机数目不超过3架     起飞或降落时间为5-6
*/
int main(void){
    int runTime = 0, programTime;   // 程序已运行时间 程序总运行时间
    int programTime, over, lTime, rTime, dAir;    // 飞机起飞降落成功数目 平均起飞时间 平均着落时间 坠毁飞机数目
    GetRange("Input running time of program: ", &programTime, 10000, 20000);
    
    /* 创建队列 */
    ComeQueue *cq;
    LeaveQueue *lq;

    cq = CreateComeQueue();
    lq = CreateLeaveQueue();

    
    /* 程序运行：着落等待队列 -> 机场内 -> 起飞等待队列 */
    int airNumber = 1;      // 飞机编号
    int runway0 = 0, runway1 = 0, runway2 = 0;
    /* 循环结束 programTime = 0 */
    while(runTime < programTime){
        AirCome(cq, &airNumber, &runTime);

        AirTakeOffOrLand(cq, &runway0, &runway1, &runway2);

        AirLeave(lq, &airNumber, &runTime);

        runTime++;
    }
    
    /* 销毁队列  */
    DisposeComeQueue(cq);
    DisposeLeaveQueue(lq);

    return 0;
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
