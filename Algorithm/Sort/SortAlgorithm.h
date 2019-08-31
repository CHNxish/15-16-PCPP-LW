#ifndef _SORT_ALGORITHM_
#define _SORT_ALGORITHM_

typedef int ElementType, *PtrElementType;
void BubbleSort(PtrElementType array, int length);
void CocktailSort(PtrElementType array, int length);
void SelectSort(PtrElementType array, int length);
void InsertSort(PtrElementType array, int length);
void ShellSort(PtrElementType array, int length);
void MergeSort(PtrElementType array, int length);
void QuickSort(PtrElementType array, int left, int right);
void HeapSort(PtrElementType array, int length);
void BuckerSort(PtrElementType array, int length);
void BaseSort(PtrElementType array, int length);
void Swap(PtrElementType array, int p, int q);
void Get(PtrElementType array, int p, int q);
int Compare(PtrElementType array, int p, int q);

#endif