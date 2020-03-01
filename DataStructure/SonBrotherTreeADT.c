#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SonBrotherTreeADT.h"
#include "FatalError.h"

#define FILE_NAME ("TreeLike.tl")

// 初始化儿子兄弟树
PtrSonBrotherTree CreateSonBrotherTree(){
	PtrSonBrotherTree tree;

	tree = (PtrSonBrotherTree)malloc(sizeof(SonBrotherTree));
	if(tree == NULL)
		FatalError("Out of space!\n");
	tree -> son = NULL;
	tree -> brother = NULL;
	MakeEmptySonBrotherTree(tree);
	return tree;
}

// 清空
void MakeEmptySonBrotherTree(PtrSonBrotherTree tree){
	if(tree == NULL)
		Error("Must use CreateSonBrotherTree first!\n");
	else
		if(!IsEmptySonBrotherTree(tree))
			DeleteSonBrotherTree(tree);
}

// 判断儿子兄弟树是不是空
int IsEmptySonBrotherTree(PtrSonBrotherTree tree){
	return (tree -> son == NULL) && (tree -> brother == NULL);
}

// 删除儿子兄弟树
void DeleteSonBrotherTree(PtrSonBrotherTree tree){
	PtrSonBrotherTree position, tmpCell;

	position = tree -> next;
	if(IsEmptySonBrotherTree(position)){
		if(position -> son != NULL)
			DeleteSonBrotherTree(position -> son);
		if(position -> brother != NULL)
			DeleteSonBrotherTree(position -> brother);
	}
	free(tree);
}

// 获取TreeLike
void GetTreeLike(PtrSonBrotherTree tree){
	FILE *fileName;
	char array[256]; // 获取每一行 size是256
	int count, currentTab, prevTab; //字符数 当前行tab数 前一行tab数

	currentTab = prevTab = 0;
	fileName = fopen(FILE_NAME, "r+");
	while(getline(fileName, array)){
		count = 0;
		while(array[count] != '\0'){
			if(array[count] == '\t'){
				currentTab++;
				count++;
			}
			else
				break;
		}

		if(currentTab > prevTab){
			tree -> son = 
		}
		else if(currentTab < prevTab){

		}
		else{

		}

		prevTab = currentTab; currentTab = 0;
	}


	fclose(fileName);
}

// 显示TreeLike
void DirTreeLike(PtrSonBrotherTree tree){

}

int getline(const char *filename, char *array){
	int c, count;

	count = 0;
	while((c = fgetc(filename)) != EOF && c != '\n'){
		array[count++] = c;
	}
	array[count] = '\0';

	return (c == EOF)? 0:1;
}