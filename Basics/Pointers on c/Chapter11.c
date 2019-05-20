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

##sort.c
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

##inventor.h
typedef struct{
  int cost;
  int supplier;
}Partinfo;

typedef struct{
  int n_parts;
  struct SUBASSYPART{
    char patrno[10];
    short quan;
  }*part;
}Subassyinfo;

typedef struct{
  char partno[10];
  int quan;
  enum{PART,SUBASSY} type;
  union{
    Partinfo *part;
    Subassyinfo *subassy;
  }info;
}Invrec;
##

##invcreat.c
#include <stdlib.h>
#include <stdio.h>
#include "inventor.h"

Invrec *create_subassy_record(int n_parts){
  Invrec *new_rec;
  new_rec=malloc(sizeof(Invrec));
  if(new_rec!=NULL){
    new_rec->info.subassy=malloc(sizeof(Subassyinfo));
    if(new_rec->ifo.subassy!=NULL){
      new_rec->info.subassy->part=malloc(n_parts*sizeof(struct SUBASSYPART));
      if(new_rec->info.subassy->part!=NULL){
        new_rec->type=SUBASSY;
        new_rec->info.subassy->n_parts=n_parts;
        return new_rec;
      }
      free(new->info.subassy);
    }
    free(new_rec);
  }
  return NULL;
}
##

##invdelet.c
#include <stdlib.h>
#include "inventor.h"

void discard_inventory_record(Invrec* record){
  switch(record->type){
  case SUBASSY:
    free(record->info.subassy->part);
    free(record->info.subassy);
    break;
  case PART:
    free(record->info.part);
    break;
  }
  free(record);
}
##

##
*/
