#ifndef _SON_BROTHER_TREE_ADT_H_
#define _SON_BROTHER_TREE_ADT_H_

typedef char *PtrElementType;
typedef struct SBTNode{
	PtrElementType data;
	struct SBTNode *son;
	struct SBTNode *brother;
}SonBrotherTree, *PtrSonBrotherTree;

PtrSonBrotherTree CreateSonBrotherTree();
void DeleteSonBrotherTree(PtrSonBrotherTree tree);
void MakeEmptySonBrotherTree(PtrSonBrotherTree tree);
int IsEmptySonBrotherTree(PtrSonBrotherTree tree);
void GetTreeLike(PtrSonBrotherTree tree);
void DirTreeLike(PtrSonBrotherTree tree);

#endif