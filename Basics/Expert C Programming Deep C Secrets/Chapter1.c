/*
UNIX(先用PDP-7汇编语言编写，然后用PDP-11编写，最后用c语言编程，因为汇编在使用数据结构的时候很麻烦)
BCPL(Basic Combined Programmming Language)->B->New B->早期C->K&R C->ANSI C->ISO C
ANSI C（ISO C）都有标准文档，里面有各种版本的规定

不可移植代码（unportable code）
坏代码（bad code）
可移植代码（portable code）

函数原型要有返回值，函数名，参数类型，参数名称（最好有）

const char *=char *    没问题
const char **=char **  有问题
（在研究程序具体错误或者警告原因的时候，可以通过标准文档查看具体问题）

寻常算术转换：1）字符和整形（整形升级）2）寻常算术转换
通俗解释：当执行算术运算时，操作数如果类型不同，就会发生转换，数据类型一般朝着浮点精度更高，
长度更长的方向转换，整形数如果转换为signed不会丢失信息，就转换成signed，如果不行就转换成
unsigned。
###Eg:
main(){
  if(-1<(unsigned char)1)
    printf("-1 is less than (unsigned char)1: ANSI semantics");
  else
    printf("-1 NOT less than (unsigned char)1: K&R semantics");
}
###Unacceptable mistakes
*/
