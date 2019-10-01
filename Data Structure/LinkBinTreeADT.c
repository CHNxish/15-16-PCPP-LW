#define SIZE 100
/* 先序遍历非递归 */
void PreOrderBinTree(PtrChildBinTree tree){
    PtrChildBinTree pt;
    PtrSqStack stack = CreateSqStack(SIZE);

    if(tree != NULL){
        PushSqStack(stack, tree);
        while(stack -> top != 0){
            pt = TopAndPopSqStack(stack);
            visit(pt);
            if(pt -> rChild != NULL)
                PushSqStack(stack, pt -> rChild);
            if(pt -> lChild != NULL)
                PushSqStack(stack, pt -> lChild);
        }
    }
}

/* 中序遍历非递归 */
void InOrderBinTree(PtrChildBinTree tree){
    PtrChildBinTree pt;
    PtrSqStack stack = CreateSqStack(SIZE);

    pt = tree;
    while(pt != NULL || !IsEmptySqStack(stack)){
        if(pt!= NULL){
            PushSqStack(stack, pt);
            pt = pt -> lChild;
        }
        else{
            pt = TopAndPopSqStack(stack);
            visit(pt);
            p = p -> rChild;
        }
    }
}

/* 后序遍历非递归 */
void PostOrderBinTree(PtrChildBinTree tree){
    PtrChildBinTree pt;
    PtrSqStack stack = CreateSqStack(SIZE);
    int flag;

    if(tree != NULL){
        do{
            while(tree != NULL){
                PushSqStack(stack, tree);
                tree = tree -> lChild;
            }
            pt = NULL;
            flag = 1;
            while(!IsEmptySqStack(stack) && flag){
                tree = TopSqStack(stack);
                if(tree -> rChild == pt){
                    visit(tree);
                    PopSqStack(stack);
                    pt = tree;
                }
                else{
                    tree = tree -> rChild;
                    flag = 0;
                }
            }
        }while(!IsEmptySqStack(stack));
    }
}

/* 以字符串的形式“根 左子树 右子树” */
BOOL CreateBinTreeForString(PtrChildBinTree tree, int array[], int size, int n){
    int ch;

    if(n < size)
        ch = array[n];
    else
        return TRUE;

    if(ch == ' ') tree = NULL;
    else{
        tree = CreateLinkBinTree(tree);
        tree -> data = ch;
        return CreateBinTreeForString(tree -> lChild);
        return CreateBinTreeForString(tree -> rChild);
    }
}

/* 先序和中序构造树 */
void CrtBT(PtrChildBinTree tree, char pre[], char ins[], int ps, int is, int size){
    //pre[ps --- ps + size - 1] ins[is --- is + size - 1]
    int k;

    if(size == 0) tree = NULL;
    else{
        k = SearchArray(ins, SIZE, pre[ps]);
        if(k == -1) tree = NULL;
        else{
            tree = CreateLinkBinTree();
            tree -> data = pre[ps];
            if(k == is)
                tree -> lChild = NULL;
            else
                CtrBT(tree -> lChild, pre, ins, ps + 1, is, k - is);

            if(k == is + size - 1)
                tree -> rChild = NULL;
            else
                CtrBT(tree -> rChild, pre, ins, ps + 1 + (k - is), k + 1, n - (k - is) -1);
        }
    }
}

int SearchArray(char ins[], int size, char ch){
    int i;

    for(i = 0; i < size; i++){
        if(ch == ins[i]) return i;
    }
    return -1;
}

/* 按给定的表达式建二叉树 */

/* 进行层次遍历 */
void LevelOrder(PtrChildBinTree tree){
    PtrChildBinTree Queue[MAX_TREE_SIZE];
    int front, rear;

    if(tree == NULL) return;

    front = -1; rear = 0;
    Queue[rear] = b;
    while(front != rear){
        Visit(Queue[++front] -> data);
        if(Queue[front] -> lChild != NULL)
            Queue[++rear] = Queue[front] -> lChild;
        if(Queue[front] -> rChild != NULL
            Queue[++rear] = Queue[front] -> rChild7yyy;
    }
}
