/* 题目：Random Walk 随机走动 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMD (8)	// Number of moving direction

// 定义布尔类型
#define BOOL 	int
#define TRUE 	(1)
#define FALSE 	(0)

// 出错宏定义 
#define Error(str) FatalError(str)
#define FatalError(str) \
fprintf(stderr, "%s", str), exit(1);

int GetInteger(char *s, int min, int max);
void SetMap(int *pMap[], int row, int col);
BOOL CheckMap(int *pMap[], int size);
void PrintMapInfo(int *pMap[], int size);

int main(void){
	int row, col;	// 行，列遍历元素
	int mapSize;	// 地图尺寸
	// 横纵可移动的操作
	int imove[NMD] = {-1, 0, 1, 1, 1, 0, -1, -1};	
	int jmove[NMD] = {1, 1, 1, 0, -1, -1, -1, 0};

	/* 获取地图尺寸 */
	mapSize = GetInteger("Input Map Size: ", 2, 40);

	/* 生成地图和相关信息 */
	int *pMap[mapSize];
	int map[mapSize][mapSize];	
	int ibug, jbug;	// 起始坐标

	for(row = 0; row < mapSize; row++){
		pMap[row] = &map[row][0];
	}
	for(row = 0; row < mapSize; row++){
		for(col = 0; col < mapSize; col++){
			map[row][col] = 0;
		}
	}

	// 随机生成 ibug jbug
	srand( (unsigned)time(NULL) );
	ibug = rand() % (mapSize - 2) + 2;
	jbug = rand() % (mapSize - 2) + 2;

	/* 随机走动 */
	int count = 0, moveDir;
	SetMap(pMap, ibug, jbug);
	while( CheckMap(pMap, mapSize) == FALSE && count < 50000){
		moveDir = rand() % 8;
		if(ibug + imove[moveDir] < 0 || ibug + imove[moveDir] >= mapSize 
		   || jbug + jmove[moveDir] < 0 || jbug + jmove[moveDir] >= mapSize)
		   continue;
		ibug += imove[moveDir];
		jbug += jmove[moveDir];
		SetMap(pMap, ibug, jbug);
		count++;
	}

	/* 输出结果 */
	if( CheckMap(pMap, mapSize) == TRUE){
		PrintMapInfo(pMap, mapSize);
	}
	else{
		printf("The program has run 50,000 times!\n");
	}

	return 0;
}

int GetInteger(char *s, int min, int max){
	int result;

	printf("%s", s);
	scanf("%d", &result);
	if(result < min || result > max)
		Error("Integer out of range!\n");

	return result;
}

void SetMap(int *pMap[], int row, int col){
	pMap[row][col]++;
}

BOOL CheckMap(int *pMap[], int size){
	int row, col;
	for(row = 0; row < size; row++){
		for(col = 0; col < size; col++){
			if(pMap[row][col] == 0) return FALSE;
		}
	}
	return TRUE;
}

void PrintMapInfo(int *pMap[], int size){
	int row, col;
	int sum = 0;
	for(row = 0; row < size; row++){
		for(col = 0; col < size; col++){
			sum += pMap[row][col];
			printf("In map point (%d, %d) runs %d!\n", row + 1, col + 1, pMap[row][col]);
		}
	}
	printf("Sum is %d!\n", sum);
}
