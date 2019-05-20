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

##
#include <stdlib.h>
#include <stdio.h>

int compare_integers(void const*a,void const *b){
  register int const *pa=a;
  register int const *pb=b;
  
  return *pa>*pb?1:*pa<*pb?-1:0;
}

int main(){
  int *array;
  int n_values;
  int i;
  
  printf("How many values are there?");
  if(scanf("%d",&n_values)!=1 || n_values<=0){
    printf("Illegal number of values.\n");
    exit(EXIT_FAILURE);
  }
  
  array=malloc(n_values*sizeof(int));
  if(array==NULL){
    printf("Can't get memory for that many values.\n");
    exit(EXIT_FAILURE);
  }
  
  for(i=0;i<n_values;i+=1){
    printf("? ");
    if(scanf("%d",array+i)!=1){
      printf("Error reading value #%d\n",i);
      free(array);
      exit(EXIT_FAILURE);
    }
  }
  
  qsort(array,n_values,sizeof(int),compare_integers);
  
  for(i=0;i<n_values;i+=1)
    printf("%d\n",array[i]);
    
  free(array);
  return EXIT_SUCCESS;
}

##
*/
