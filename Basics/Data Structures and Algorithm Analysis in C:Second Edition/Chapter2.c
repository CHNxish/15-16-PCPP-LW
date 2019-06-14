/*
两个函数的相对增长率
1.如果存在正常数c和n0，如果当N≥n0时，T(N)≤cF(N),则记为T(N)=O(F(N))
2.如果存在正常数c和n0，如果当N≥n0时，T(N)≤cF(N),则记为T(N)=Ω(F(N))
3.如果T(N)=O(F(N))且T(N)=Ω(F(N))，则T(N)=θ(F(N))
4.如果T(N)=O(F(N))且T(N)≠Ω(F(N))，则T(N)=o(F(N))

1)存在T1(N)=O(F(N)),T2(N)=O(G(N))
T1(N)+T2(N)=max(O(F(N)),O(G(N)))
T1(N)*T2(N)=O(F(N)*G(N))

2)如果T(N)是一个k次多项式，则T(N)=θ(K的n次方)

3)如果k是常数，logkN=O(N)，说明对数增长非常缓慢

在用到大O表示法的时候，不要将低阶或者常数放入表达式中，如T(N)=O(N²+N+c)，应该写成T(N)=O(N²)

在求两个函数相对增长率的时候，我们可以根据极限limf(N)/g(N)的情况来判断，必要的时候利用洛必达法则
1）如果极限为0，则f(N)=o(g(N))
2）如果极限为c≠0，则f(N)=θ(g(N))
3）如果极限为∞，则g(N)=o(f(N))
4）极限摆动，两者无关

模型：在对程序进行估计运算时间或者占据内存时，因为加减乘除，读取内存不同，使用时间会不同，因为系统
位数不同，占据内存大小不同，但是我们统一用一个单位来衡量每一次计算和赋值。

考虑情况：往往情况下Tavg(N)≦Tworst(N)，我们在考虑问题的时候应该考虑最坏情况，而不是考虑平均情况
，相对而言，分析平均的这个“平均”是一个非常不好规定的词语。

最大子串的值：

分治法：
##
static int
MaxSubSum(const int A[], int Left, int Right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	
	if(Left == Right)
		if(A[Left] > 0)
			return A[Left];
		else
			return 0;
		
	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum( A, Left, Center);
	MaxRightSum = MaxSubSum( A, Center + 1, Right);
	
	MaxLeftBorderSum = 0, LeftBorderSum = 0;
	for( i = Center; i >= Left; i-- ){
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	
	MaxRightBorderSum = 0, RightBorderSum = 0;
	for( i = Center + 1; i < Left; i++ ){
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	
	return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorder);
}

int
MaxSubsequenceSum(const int A[], int N){
	return MaxSubSum( A, 0, N-1);
}
##

线性方法：
##
int
MaxSubsequenceSum(const int A[], int N){
	int ThisSum, MaxSum, j;
	
	ThisSum = MaxSum = 0;
	for( j=0; j<N; j++){
		ThisSum += A[j];
		
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0)
			ThisSum = 0;
	}
	
	return MaxSum;
}
##

在线（联机）算法（on line algorithm）：
对于数据只要读入一次且不需要存储的不知道准确数量的算法
离线算法（off line algorithm）：
对于数据需要知道准确数量的算法

完美算法：
只需要常量空间和线性处理速度的算法

对分查法：
##对排序后的A数组查找X
int
BinarySearch(const ElementType A[], ElementType X, int N){
	int Low, Mid, High;
	
	Low = 0, High = N - 1;
	while(Low <= High){
		Mid = (Low + High) / 2;
		if(A[Mid] < X)
			Low = Mid + 1;
		else if(A[Mid] > X)
			High = Mid - 1;
		else
			return Mid;
	}
	return NotFound;/*NotFound is defined as -1*/
}
##

*/
