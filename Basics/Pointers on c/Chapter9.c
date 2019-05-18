/*
string.h包含了一些处理字符串的函数

size_t strlen(char const *string);
if(strlen(x)>=strlen(y))    √ 
if(strlen(x)-strlen(y)>=0)  ×
因为size_t是无符号整型，所以值永远是正数

char *strcpy(char *dst,char const *src);

char *strcat(char *dst,char const *src);

int strcmp(char const *s1,char const *s2);

长度受限的字符串函数：
char *strncpy(char *dst,char const *src,size_t len);
char *strncat(char *dst,char const *src,size_t len);
int strncmp(char const *s1,char const *s2,size_t len);
如果src的长度小于len，那么dst中剩下的字符用NUL字符填充；如果src的长度大于len，那么dst将复制src中
前len个字符，且不以NUL字符结尾
buffer[SIZE-1]='\0';

char *strchr(char const *str,int ch);
char *strrchr(char const *str,int ch);

char *strpbrk(char const *str,char const *group);

char *strstr(char const *s1,char const *s2);

##标准库没有strrstr函数，利用strstr实现

#include <string.h>

char *my_strrstr(char const *s1,char const *s2){
  register char *last;
  register char *current;
  
  last=NULL;
  if(*s2!='\0'){
    current=strstr(s1,s2);
    while(current!=NULL){
      last=current;
      current=strstr(last+1,s2);
    }
  }
  return last;
}

##

size_t strspn(char const *str,char const *group);
size_t strcspn(char const *str,char const *group);

char *strtok(char *str,char const *sep);

char *strerror(int error_number);

<ctype.h>
对于字符串中单个字符进行判断或者转换

对于内存的操作，可以用于任何类型
void *memcpy(void *dst,void const *src,size_t length);
void *memmove(void *dst,void const *src,size_t length);
void *memcmp(void *a,void const *b,size_t length);
void *memchr(void *a,int ch,size_t length);
void *memset(void *dst,int ch,size_t length);
*/
