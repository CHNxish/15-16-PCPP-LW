typedef int ElementType;

// 孩子兄弟表示法
typedef struct TBCSNode{
    ElementType data;
    struct TCSNode *child;
    struct TCSNode *sibling;
}ChildSiblingTree, *PtrChildSiblingTree;

// 孩子表示法
typedef struct TBCNode{
    ElementType data;
    struct TBCNode *lChild;
    struct TBCNode *rChild;
}ChildBinTree, *PtrChildBinTree;
