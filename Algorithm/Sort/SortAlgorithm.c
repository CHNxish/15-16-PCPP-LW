#include <stdlib.h>
#include <stdbool.h>
#include "SortAlgorithm.h"

// 冒泡排序
// T(n) = O(n^2) S(n) = O(1)
void BubbleSort(PtrElementType array, int length){
	int i, j;

	for(i = 0; i < length - 1; i++){
		for(j = 0; j < length - i - 1; j++){
			if(Compare(array, j, j + 1)){
				Swap(array, j, j + 1);
			}
		}
	}

}

// 鸡尾酒排序：冒泡排序的变形
// T(n) = O(n^2) S(n) = O(1)
void CocktailSort(PtrElementType array, int length){
	int i, j, left, right;

	left = 0; right = length - 1;
	for(left < right){
		for(i = left; i < right - 1; i++){
			if(Compare(i, i + 1)){
				Swap(array, i , i + 1);
			}
		}
		right -= 1;
		for(j = right; j > left; j--){
			if(Compare(j, j - 1)){
				Swap(array, j, j - 1);
			}
		}
		left += 1;
	}

}

// 选择排序
// T(n) = O(n^2) S(n) = O(1)
void SelectSort(PtrElementType array, int length){
	int i, j, minIndex;

	for(i = 0; i < length - 1; i++){
		minIndex = i;
		for(j = i + 1; j < length; j++){
			if(Compare(array, minIndex, j)){
				minIndex = j;
			}
		}
		if(minIndex != i){
			Swap(array, minIndex, i);
		}
	}

}

// 插入排序
// T(n) = O(n^2) S(n) = O(1)
void InsertSort(PtrElementType array, int length){
	int i, j, minIndex;

	for(i = 1; i < length; i++){
		minIndex = i;
		for(j = i - 1; j >= 0 && Compare(array, j, minIndex); j--){
			Swap(array, j + 1, j);
		}
		Swap(array, j + 1, minIndex);
	}

}

// 希尔排序
// T(n) = O(n^2) S(n) = O(1)
void ShellSort(PtrElementType array, int length){
	int i, j, gap, minIndex;

	for(gap = length / 2; gap > 0; gap /= 2){
		for(i = gap; i < length; i += gap){
			minIndex = i;
			for(j = i - gap; j >= 0 && Compare(array, j, minIndex); j -= gap){
				Compare(array, j + gap, j);
			}
			Compare(array, j + gap, minIndex);
		}
	}

}

// 归并排序
// T(n) = O(nlogn) S(n) = O(n)
void Merge(PtrElementType array, PtrElementType temp, int left, int right, int rightEnd){
    int leftEnd = right - 1;
    int p = left, i;
    int num = rightend - left + 1;
    
    while(left <= leftEnd && right <= rightend){
        if(array[left] < array[right])
            temp[p++] = array[left++];
        else
            temp[p++] = array[right++];
    }
    
    while(left <= leftEnd)
        temp[p++] = array[left++];
    while(right <= rightEnd)
        temp[p++] = array[right++];
    
    for(i = 0; i < num; i++)
        array[i] = temp[i];
}

void MSort(PtrElementType array, ElementType temp, int left, int right){
    int center;
    if(left < right){
        center = (left + right) / 2;
        MSort(array, temp, left, center);
        MSort(array, temp, center + 1, right);
        Merge(array, temp, left, center + 1, right);
    }
}

void MergeSort(PtrElementType array, int length){
    PtrElementType temp = (PtrElementType)malloc(length * sizeof(ElementType)));
    if(temp == NULL) return;
    MSort(array, temp, 0, length - 1);
    free(temp);
    temp = NULL;
}
// 快速排序
void QuickSort(PtrElementType array, int left, int right){
    if(left >= right) return;
    
    int i = left, j = right;
    int base = array[left];
    while(i < j){
        while(i < j && array[j] >= base)
            j--;
        if(i < j)
            array[i++] = array[j++];
        while(i < j && array[i] <= base)
            i++;
        if(i < j)
            array[j--] = array[i];
    }
    array[i] = base;
    QuickSort(array, left, i - 1);
    QuickSort(array, i + 1, right);
}

// 堆排序
void HeapDown(PtrElementType array, int i, int N){
    int child;
    int temp;
    for(temp = array[i]; 2 * i + 1 < N; i = child){
        child = 2 * i + 1;
        if(child != N - 1 && array[child + 1] > array[child])
            child++;
        if(temp < array[child]){
            array[i] = array[child];
            array[child] = temp;
        }
        else{
            break;
        }
    }
}
                                        
void HeapSort(PtrElementType array, int length){
    int i;
    for(i = length / 2; i >= 0; i--){
        HeapDown(array, i, length);
    }
    for(i = length - 1; i > 0; i--){
        Swap(&array[0], &array[i]);
        HeapDown(array, 0, i);
    }
}

// 桶排序
void BuckerSort(PtrElementType array, int length){
    int i, j;
    ElementType maxNum = array[0];
    for(i = 1; i < length; i++){
        if(arrayp[i] > maxNum){
            maxNum = array[i];
        }
    }
    
}

// 基数排序
void BaseSort(PtrElementType array, int length){

}

// 交换函数
void Swap(PtrElementType array, int p, int q){
	ElementType temp;

	temp = array[p];
	array[p] = array[q];
	array[q] = temp;
}

// 赋值函数
void Get(PtrElementType array, int p , int q){
	array[p] = array[q];
}

// 比较函数
int Compare(PtrElementType array, int p, int q){
	if(array[p] > array[q])
		return true;
	else
		return false;
}
