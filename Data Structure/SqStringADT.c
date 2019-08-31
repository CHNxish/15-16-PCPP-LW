#include <stdlib.h>
#include "SqStringADT.h"
#include "FatalError.h"
const int minSqStringSize = 5;

// 初始化顺序串的结点
PtrSqString CreateSqString(int maxElements){
	PtrSqString string;

	if(maxElements < minSqStringSize)
		Error("Sequence String size is too small!\n");

	string = (PtrSqString)malloc(sizeof(SqString));
	if(string == NULL)
		FatalError("Out of space!\n");
	string -> data = (char *)malloc(sizeof(char) * maxElements);
	if(string -> data == NULL)
		FatalError("Out of space!\n");
	string -> capacity = maxElements;
	MakeEmptySqString(string);

	return string;
}

// 检查顺序串是否是空
int IsEmptySqString(PtrSqString string){
	return string -> length == 0;
}

// 检查顺序串是否是满
int IsFullSqString(PtrSqString string){
	return string -> length == string -> capacity;
}

// 删除顺序串
void DisposeSqString(PtrSqString string){
	if(string != NULL){
		free(string -> data);
		free(string);
	}
}

// 顺序串清空
void MakeEmptySqString(PtrSqString string){
	if(string == NULL)
		Error("Must use CreateSqString first!\n");
	string -> length = 0;
}

// 返回顺序串的长度
int LengthSqString(PtrSqString string){
	return string -> length;
}

// 连接顺序串
void ConcatSqString(PtrSqString string1, PtrSqString string2){
	int count, size;

	if(string1 -> capacity < string1 -> length + string2 -> length)
		size = string1 -> capacity - string2 -> length;
	else{
		size = string1 -> length + string2 -> length;
	}
	for(count = 0; count < size; count++)
		string1 -> data[string1 -> length + count] = string2 -> data[count];

}

// 返回子串
PtrSqString SubSqString(PtrSqString string, int position, int length){
	int count;
	PtrSqString subSqString;

	if(position < 1 || string -> capacity < position || length < 0 \
	   || string -> capacity - position + 1< length)
		Error("Unable to return Sequence String!\n");

	subSqString = CreateSqString(string -> capacity);
	for(count = position - 1; count < length; count++)
		subSqString -> data[count] = string -> data[position + count - 1];

	return subSqString;
}

// 比较顺序串
int EqualSqString(PtrSqString string1, PtrSqString string2){
	int count, size = (string1 -> length > string2 -> length)?string1 -> length \
	    : string2 -> length;

	for(count = 0; count < size; count++)
		if(string1 -> data[count] != string2 -> data[count])
			return string1 -> data[count] - string2 -> data[count];
	return string1 -> length - string2 -> length;
}

// 寻找字符串
int IndexSqString(PtrSqString string1, PtrSqString string2){
	int count1, count2;
	count1 = count2 = 0;

	while(count1 < string1 -> length && count2 < string2 -> length){
		if(string1 -> data[count1] == string2 -> data[count2]){
			count1++;
			count2++;
		}
		else{
			count1 = count1 - count2;
			count2 = 0;
		}
	}
	if(count2 >= string2 -> length)
		return count1 - count2;
	else
		return NONE_POSITION;
}

// 插入字符串
void InsertSqString(PtrSqString string1, PtrSqString string2, int position){
	int count;

	if(position < 1 || string1 -> length < position || string1 -> capacity \
	   < string2 -> length + position)
		Error("Ubable to insert Sequence String!\n");

	if(string1 -> length + string2 -> length <= string1 -> capacity){
		for(count = string1 -> length - 1; count >= position - 1; count--)
			string1 -> data[string2 -> length + count - 1] = string1 -> data[count];
		for(count = position - 1; count < position + string2 -> length; count++)
			string1 -> data[count] = string2 -> data[count - position + 1];
		string1 -> length = string1 -> length + string2 -> length;
	}
	else{
		for(count = string1 -> capacity -1; count > position - 1; count--)
			string1 -> data[count] = string1 -> data[count - string2 -> length];
		for(count = position - 1; count < position + string2 -> length; count++)
			string1 -> data[count] = string2 -> data[count - position + 1];
		string1 -> length = string1 -> capacity;
	}

}