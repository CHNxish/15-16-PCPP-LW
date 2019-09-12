/*
对于程序需要处理大数据的讨论：
当数据比较少的时候，算法本身区别并不是很大，但是如果处理一百万个元素的随机文件，
很多算法需要处理几天才有结果，而有的只需要几秒钟，这就是算法的需要

指数：https://zh.wikipedia.org/wiki/%E6%8C%87%E6%95%B0
对数：https://zh.wikipedia.org/wiki/%E5%AF%B9%E6%95%B0
级数：https://zh.wikipedia.org/wiki/%E7%BA%A7%E6%95%B0
模运算：https://zh.wikipedia.org/wiki/%E6%A8%A1%E9%99%A4

归纳法：当证明一个等式成立的时候，可以先证明基本情形，然后假设这个情况在1<=n<=k都
成立，证明n=k+1的时候也成立，则等式成立
反证法：假设一个反例让证明结构不成立，然后推导出矛盾的情况，最后证明结果成立
最有名的例子：证明存在无穷多个素数 假设存在某个最大的素数是Pk，则
N=P1P2···Pk+1 显然N是大于Pk的数 但是P1，P2，···，Pk都不能整除N，因为都有
余数1，所以和算术基本定理（任何一个数都是一些素数的乘积）矛盾，所以存在无穷多个
素数

递归：
1）基准情形（base case）：你必须总要有某些基准的情形，不需要递归就能求解
2）不断推进（making progress）：对于那些需要递归求解的情形，递归调用必须总能朝着产生
基准情形的方法推进
3）设计法则（design rule）：假设所有的递归调用都能运行
4）合成效益法则（compound interest rule）：在求解一个问题的同一实例中，切勿在不同的
递归调用中做重复性的工作

##打印一个数的n次方
void printOut( unsigned int N , unsigned int k ){
  if( N >= k )
    printOut( N / k , k);
  PrintDigit( N % k );
}
##

## 递归置换生成程序
#include <stdio.h>
#define SIZE 4
#define SWAP(x, y, z) ((z) = (x), (x) = (y), (y) = (z))
void perm(char *list, int i, int n);

int main(void){
	char list[SIZE] = {'A', 'B', 'C', 'D'};
	
	perm(list, 0, SIZE - 1);
	
	return 0;
}

void perm(char *list, int i, int n){
	int j, temp;
	if(i == n){
		for(j = 0; j <= n; j++) printf("%c", list[j]);
		printf("   ");
	}
	else{
		for(j = i; j <= n; j++){
			SWAP(list[i], list[j], temp);
			perm(list, i+1, n);
			SWAP(list[i], list[j], temp);
			if(i == 0) printf("\n");
		}
	}
}
##

编码规范
*/
