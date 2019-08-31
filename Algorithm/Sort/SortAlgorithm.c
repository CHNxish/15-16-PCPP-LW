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
void MergeSort(PtrElementType array, int length){
	int *temp = (int *)malloc(length * sizeof(int))
}


void QuickSort(PtrElementType array, int left, int right){

}


void HeapSort(PtrElementType array, int length){

}


void BuckerSort(PtrElementType array, int length){

}


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