/*
ANSI C在实现过程中存在两种环境，1）编译环境2）执行环境
编译过程：
（先对源代码进行解析，判断语句的意思，在没有出错的
情况下，根据编译器的优化选项（优化器）编译代码）
main.c 源文件
1）预处理器 main.i 处理后的文件（文本格式）
2）编译器 main.s 汇编代码（文本格式）
3）汇编器 main.o 目标代码（二进制格式）
4）链接器 a.out 可执行程序（二进制格式）

可执行文件运行时的内存分配：
1）正文段（text segment）：存放程序执行的代码
2）只读数据段（Ro data）：只读数据段存放程序不会被改变的数据（比如编译器配置信息等等）
3）已初始化读写数据段（data segment）：存放程序已经初始化的全局变量
4）bss段（block started by symbol segment）：存放程序未初始化的全局变量
运行时：
1）堆（heap）：程序运行时被动态分配的内存段
2）栈（stack）：程序存放局部变量的地方

exec header（执行头部，文件头部，ELF）
text segment（文本段）
data segment（数据段）
text relocations（文本重定位段）
data relocations（数据重定位段）
symbol table（符号表）
string table（字符串表）
重定位段：xxx.lib文件不属于程序，但是程序在执行的时候会使用这个dll，那么就需要重定位

liunx下内存分配：
kernel space
stack
memory mapping segment
heap
bss segment
data segment
text segment（包括ELF）
*/
