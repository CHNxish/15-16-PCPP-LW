/*
void *malloc (size_t size);
void free(void *pointer);
void *calloc(size_t num_elements,size_t element_size);
void *realloc(void *ptr,size_t new_size);

if(pi==NULL){
  printf("Out of memory!\n");
  exit(1);
}

内存泄露（memory leak）:
所有执行程序共享一个通用内存池的系统，内存泄漏将会一点点榨干可用内存，最终将一无所有
摆脱这个困境，只有重启系统
*/
