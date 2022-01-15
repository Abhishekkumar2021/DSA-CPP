#include<stdio.h>
#include<stdlib.h>
struct ArrayAsADT{
    int *elements;
    int capacity;
};
void createNewArray(struct ArrayAsADT *Array, int capacity){
    Array->elements = (int*)malloc(capacity*sizeof(int));
}
void storeValue(struct ArrayAsADT* Array, int value, int index){
     Array->elements[index] = value;
}
int accessValue(struct ArrayAsADT* Array,int index){
    return Array->elements[index];
}
void deleteArray(struct ArrayAsADT * Array){
    free(Array->elements);
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  struct ArrayAsADT Array = {NULL, 0};
  int capacity;
  scanf("%d", &capacity);
  createNewArray(&Array, capacity);
  for(int current = 0; current < capacity; current++){
      int num;
      scanf("%d", &num);
      storeValue(&Array, num, current); 
      printf("The value at index %d is %d\n", current,accessValue(&Array, current));
  }
   deleteArray(&Array);
  
}