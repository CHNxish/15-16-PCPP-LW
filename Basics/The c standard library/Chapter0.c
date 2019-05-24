/*
__xxx或_xxx这样的宏定义是给标准库使用的

可以在某个目标模块前面加上t给这个头文件测试
如tstdio1.c和tstdio2.c给stdio.h这个头文件多次测试

应该习惯用
#ifndef
#define
#endif
#undef

可以使用这样的语句给指针直接赋初值
struct name *x=&(struct name){1,2};
这个方式和char *p="123";一个道理
*/
