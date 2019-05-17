/*
数组名：我人为数组名就是一个指针，但是编译器在变量表上默认这个指针带const,不能用于计算
当然我只是认为可能存在一个这样的变量表，并在变量表上这两个符号（数组名和指针名的的标识符）具有差不多的运算过程

a是数组名或者指针，x是整数
a[x] <==> x[a] <==> *(a+x)

##x,y是int类型数组
void try5(){
  register int *p1,*p2;
  
  for(p1=x,p2=y;p<&x[SIZE];)
    *p1++=*p2++;
}
##这个是一个可以和汇编速度媲美的复制数组的例子

产生高效率代码：
1）当你用某个固定数目的增量在一个数组中移动时，使用指针变量的速度要比使用下标产生的效率更高的代码
2）声明在寄存器中的变量的指针要比位于静态内存或者堆栈中的指针效率更高（具体提高的幅度取决于你使用的机器）
3）如果你可以在一个循环中不是用计数器，而使用其他的方法终止循环，你应该不用计数器
最总要的一点：时间换空间，空间换时间，当真的没有办法避免的时候，这个是最有效的方法

八皇后问题：
##

#include <stdio.h>
#define QUEENS     8
#define IS_OUTPUT  1

int A[QUEENS+1],B[QUEENS*3+1],C[QUEENS*3+1],K[QUEENS+1][QUEENS+1];
int inc,*a=A,*b=B+QUEENS,*c=C,*k=K;
void lay(int row){
  int column=0,i,j;
  
  while(++column<QUEENS){
    if(a[column]+b[column-row]+c[column+row]==0){
      k[row][column]=a[column]=b[column-row]=c[column+row]=1;
      if(i<QUEENS) lay(i+1);
      else{
        ++inc;
        if(IS_OUTPUT){
          for(printf("(%d)\n",inc),i=QUEENS+1;--i;printf("\n"))
            for(j=QUEENS+1;--j;) k[i][j]?printf("Q "):printf("+ ");
          printf("\n\n\n");
        }
      }
      k[row][column]=a[column]=b[column-row]=c[column+row]=0;
  }
}

int main(void){
  lay(1);
  printf("%d皇后共计%d个解\n",QUEENS,inc);
  return 0;
}

##
*/
