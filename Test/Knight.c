/* Knight's Tour 骑士征程 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMD     (8)
#define MAPSIZE (8)

/* 宏定义布尔类型 */
#define BOOL    int
#define TRUE    (1)
#define FALSE   (0)

/* 宏定义错误 */
#define Error(str) FatalError(str)
#define FatalError(str) \
fprintf(stderr, "%s", str), exit(1);

void SetMap(int *map[], int order, int row, int col);
BOOL KnightTour(int *map[], int size, int iPos, int jPos, const int iMove[], \
                const int jMove[], int order);
BOOL CheckMap(int *map[], int size);
BOOL CheckTour(int *map[], int size, int iPos, int jPos);
void PrintMap(int *map[], int size);

int main(){
    int i, j;  // 迭代元素

    /* 地图初始化 */
    int *pMap[MAPSIZE];
    int map[MAPSIZE][MAPSIZE];

    for(i = 0; i < MAPSIZE; i++){
        pMap[i] = &map[i][0];
    }
    for(i = 0; i < MAPSIZE; i++){
        for(j = 0; j < MAPSIZE; j++){
            map[i][j] = -1; // 初始化值为-1
        }
    }
                     
    /* 骑士移动且打印路径 */
    int iPos, jPos, order = 0;  // 骑士的横坐标 骑士的纵坐标 顺序
    const int iMove[NMD] = {-2, -1, 1, 2, -2, -1, 1, 2};
    const int jMove[NMD] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    srand( (unsigned)time(NULL) );
    iPos = rand() % MAPSIZE;
    jPos = rand() % MAPSIZE;
    SetMap(pMap, order++, iPos, jPos);
    if(KnightTour(pMap, MAPSIZE, iPos, jPos, iMove, jMove, order) == TRUE){
        printf("Start point(%d, %d) is feasible!\n", iPos + 1, jPos + 1);
        PrintMap(pMap, MAPSIZE);
    }
    else{
        printf("Start point(%d, %d) is infeasible!\n", iPos + 1, jPos + 1);
        //PrintMap(pMap, MAPSIZE);
    }
       
    return 0;
}

void SetMap(int *map[], int order, int row, int col){
    map[row][col] = order;
}

BOOL KnightTour(int *map[], int size, int iPos, int jPos, const int iMove[], \
                const int jMove[], int order){
    int i;  // 迭代元素
    
    if(CheckMap(map, size) == TRUE){
        return TRUE;
    }
    else{
        for(i = 0; i < size; i++){  // 这里 size = NMD
            if(CheckTour(map, size, iPos + iMove[i], jPos + jMove[i]) == FALSE)
                continue;
            else{
                SetMap(map, order++, iPos + iMove[i], jPos + jMove[i]);
                if(KnightTour(map, size, iPos + iMove[i], jPos + jMove[i], iMove, jMove, order) == FALSE){
		continue;
		}
		else{
			return TRUE;
		}
            }
        }
        SetMap(map, -1, iPos, jPos);
        return FALSE;
    }
}

BOOL CheckMap(int *map[], int size){
    int row, col;

    for(row = 0; row < size; row++){
        for(col = 0; col < size; col++){
            if(map[row][col] == -1) return FALSE;
        }
    }
    return TRUE;
}

BOOL CheckTour(int *map[], int size, int iPos, int jPos){
    if(iPos < 0 || iPos >= size || jPos < 0 || jPos >= size \
       || map[iPos][jPos] != -1)
        return FALSE;
    else
        return TRUE;
}

void PrintMap(int *map[], int size){
    int i;
    int row, col;
    
    for(i = 0; i < size * size; i++){
        for(row = 0; row < size; row++){
            for(col = 0; col < size; col++){
                if(map[row][col] == i){
                    printf("%d: (%d, %d)\n", i + 1, row + 1, col + 1);
                }
            }
        }
    }
}
