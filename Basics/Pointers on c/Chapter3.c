/*
基本数据类型：
1）整型
char short int long bool（stdbool.h）complex imaginary（complex.h）wchar_t（wchar.h）
signed unsigned
常量：普通整型值后面添加L,U：123L
多字节常量前面加L：L'X'
八进制整型：0123
十六进制整型：0x123
2）浮点型
float double long double
3）指针
4）聚合类型
enum union struct

limits.h：规定了整型的最大值和最小值
float.h:规定了浮点型的最大值和最小值
stdbool.h:bool true false
complex.h:complex imaginary 配合 double,float,long double使用 I：虚数宏 creal() cimag()：计算实部和虚部，输出时还要带%+.1fi，
不自带i这个符号
wchar.h:wchar_t wscanf wprintf wchar_t wstr[]=L"something"; wprintf(L"%ls\n",wstr);
字符前面要带L前缀，s代表字符串，ls代表宽字符串
设置地域环境,locale.h：设置语言和货币等等，setlocale(LC_ALL,"zh_CH.UTF-8");
在使用wscanf等函数直接必须用setlocale设置本地环境，设置完成后，不能再使用scanf函数，必须使用wscanf函数
！！！wchar_t只能在linux中使用，不能再windows中使用，因为linux中wchar_t占4个字节，在windows中占2个字节
！！！在windows使用中文可以使用tchar.h DWORD TEXT("something");

#define 宏定义
typedef 类型定义

修饰符
const static

作用域：1）代码块（局部）作用域
2）文件（全局）作用域
3）原型（函数参数）作用域
4）函数作用域：goto语句，不属于局部，不属于全局，不属于原型

链接属性：1）外部（external）
2）内部（internal）
3）无（none）
链接属性指标识符，而不仅仅是变量和函数，还有typedef int *a; 此时a是无属性标识符
*/
