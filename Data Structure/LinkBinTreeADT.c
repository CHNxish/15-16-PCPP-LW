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

/* 先序和中序构造树 */
