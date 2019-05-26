/*
assert.h

##assert.h
#undef assert

#ifdef NDEBUG
  #define assert(test) ((void)0)
#else
  void _Assert(char *);
  #define _STR(x) _VAL(x)
  #define _VAL(x) #x
  #define assert(test) ((test)?(void)0) \
    : _Assert (__FILE__)":"_STR(__LINE__)"" #test)
#endif
##

##xassert.c
#include <assert.h>
#include <stdio.h>
#inlcude <stdlib.h>

void _Assert(char *mesg)
{
  fputs(mesg,stderr);
  fputs(" -- assertion failed\n",stderr);
  abort();
}
##

1）不论是否定义了assert这个宏，先通过undef将这个宏给解除定义
2）通过ifdef else endif来控制宏定义
3）##表示将两个字符连接起来，#将符号变成字符串
4）编译器预编译文件，汇编文件，可执行文件
gcc test.c -E > test.i
gcc test.c -S test.s
gcc test.c -o test
5）宏处理应该使用的是多次处理，第一次将STR变成VAL，__LINE__变成常量，第二次将VAL宏让常量变成字符串
6）使用隐式的函数，使用库文件，输出和中断，不应该在头文件内引用头文件
7）在使用assert.h的时候，先定义NDEBUG在某一段代码不断言，在后面undef NDEBUG再使用assert宏
* /
