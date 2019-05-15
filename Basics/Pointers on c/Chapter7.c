/*
c语言设计ADT和黑盒：

##addrlist.h

#ifndef ADDRLIST_HEADER
#define ADDRLIST_HEADER

#define NAME_LENGTH 30
#define ADDR_LENGTH 100
#define PHONE_LENGTH 11

#define MAX_ADDRESSER 1000

char const *lookup_address(char const *name);
char const *lookup_phone(char const *name);

##endif

##

##addrlist.c

#include "addrlist.h"
#include <stdio.h>
#include <string.h>

static char name[MAX_ADDRESSER][NAME_LENGTH];
static char address[MAX_ADDRESSER][ADDR_LENGTH];
static char phone[MAX_ADDRESSER][PHONE_LENGTH];

static int find_entry(char const *name_to_find){
  int entry;
  
  for(entry=0;entry<MAX_ADDRESSES;entry+=1)
    if(strcmp(name_to_find,name[entry])==0)
      return entry;
  return -1;
}

char const *lookup_address(char const *name){
  int entry;
  
  entry=find_entry(name);
  if(entry==-1)
    return NULL;
  else
    return address[entry];
}

char const *lookup_phone(char const *name){
  int entry;
  
  entry=find_entry(name);
  if(entry==-1)
    return NULL;
  else
    return phone[entry];
}

##黑盒中的不需要被显式调控的文件可以用static来声明，可以通过非static来使用函数或者返回数据（数据必须是全局性的）

迭代和递归:迭代是针对一个变量的循环，递归是针对一个函数的循环
具体情况，具体讨论，如果递归开销很大，应该使用不好阅读的迭代

可变参数列表：stdarg.h va_start va_arg va_end va_list
*/
