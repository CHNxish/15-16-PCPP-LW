typedef struct{
    ElementType *data;
    int length;
}Array, *PtrArray;
// 下标为0的位置均空出来
int Search(Array array, ElementType x, \
    Status (*Compare)(ElementType, ElementType)){
    // 下标0不放哨兵
    int i;
    
    for(i = 1; i <= array.length && !Compare(array.data[i], x); i++)
        
    if(i <= array.length)
        return i;
    else
        return 0;
}

int Search(Array array, ElementType x, \
           Status (*Compare)(ElementType, ElementType)){
    // 下标0放要查找的元素
    int i;
    
    array.data[0] = x;
    for(i = array.length; !Compare(array.data[i], x); i--);
    
    return i;
}

// 有序元素的查找
int BinSearch(Array array, ElementType data, \
              Status (*Compare)(ElementType, ElementType)){
    int low, mid, high;
    
    low = 1, high = array.length;
    while(low <= high){
        mid = (low + high) / 2;
        if(Compare(array.data[mid], x) == 0)
            return mid;
        else if(Compare(array.data[mid], x) > 0)
            high = mid - 1;
        else if(Compare(array.data[mid], x) < 0)
            low = mid + 1;
    }
    return 0;
}
