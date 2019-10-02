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

// 线索二叉树
typedef enum {LINK, THREAD} PointerThr;
typedef struct TBTCNode{
    ElementType data;
    struct TBTCNode *lChild, *rChild;
    PointerThr lTag, rTag;
}ThreadChildBinTree, *PtrThreadChildBinTree;
