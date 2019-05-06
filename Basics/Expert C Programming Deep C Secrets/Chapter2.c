/*
作者：正如我的祖母曾说过的那样，当在超导条件下进行超级碰撞时不可能连一个原子也不撞碎。所以在欣赏
C语言的优点时也不要忘了分析一下它的缺陷。

switch语句：
###Eg:
const int two=2;
switch(i){
  case 1:printf("case 1\n");
  case two:printf("case 2\n");
  //error
  case 3:printf("case 3\n");
  default: ;
}
###const int并不是一个常量，case只能接常量

###Eg:
switch(operator->num_of_operands){
  case 2:process_operand(operator->operand_2);
  //error:fall through
  case 1:process_operand(operator->operand_1);
  break;
}
###switch容易产生fall through问题

###Eg:
printf("line 1 \
line 2 \
line 3\n");

printf("line 1 "
"line 2 "
"line 3");
###C语言实现的两种自动连接字符串

C语言符号重载：
static：1）在函数内部，表示该变量的值在各个调用间一直保持延续性
        2）在函数这一级，表示该函数只对本文件可见
extern：1）用于函数定义，表示全局可见（属于冗余的）
        2）用于变量，表示它在其他地方定义
void：  1）作为函数的返回类型，表示不返回任何值
        2）在指针声明中，表示通用指针的类型
        3）位于参数列表中，表示没有参数
*：     1）乘法运算符
        2）用于指针，间接引用
        3）在声明中，表示指针
&：     1）位的AND操作符
        2）取地址操作符
=：     1）取值符
==：    1）比较运算符
<=：    1）小于等于运算符
<<=：   1）左移复合赋值运算符
<：     1）小于运算符
        2）#include指令的左定界符
()：    1）在函数定义中，包围形式参数表
        2）调用一个函数
        3)改变表达式的运算次序
        4）将值转换成其他类型（强制类型转换）
        5）定义带参数的宏
        6）包围sizeof操作符的操作数（如果它是类型名）
###Eg:
p=N*sizeof*q;
apple=sizeof(int)*q;
###
*/
