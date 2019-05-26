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
3）##表示将两个字符连接起来，
*/
