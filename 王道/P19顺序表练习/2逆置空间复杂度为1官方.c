#include <stdio.h>
#include <stdlib.h>
typedef int E;
struct List{
    E *array;
    int capacity;
    int size;
};
typedef struct List* ArrayList;
_Bool initlist(ArrayList list){
    list->array = malloc(sizeof(E)*10);
    if(list->array==NULL)return 0;
    list->capacity=10;
    list->size=0;
    return 1;
}
void reverselist(ArrayList list){
    int t=0;
    for(int i=0;i<list->size/2;i++){
        t=list->array[i];
        list->array[i]=list->array[list->size-i-1];
        list->array[list->size-i-1]=t;}
}
void printlist(ArrayList list){
    for(int i=0;i<list->size;i++){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}
int main(){
    struct List list;
    if(initlist(&list)){//array已经声明初始化了，不能这样赋值，可逐一赋值，或用for循环
        /*list.array[]={1,2,3,4,5,6};*/
        for(int i=0;i<6;i++)
            list.array[i]=i;
        list.size=6;
        printlist(&list);
        reverselist(&list);
        printlist(&list);
    }
}