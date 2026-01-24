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
_Bool delete_same(ArrayList list){
    if(list->size==0)return 0;
    int i,j;
    for(i=0,j=1;j<list->size;j++){
        if(list->array[i]!=list->array[j])
            list->array[++i]=list->array[j];
    }
    list->size =i+1;
    return 1;
}
void printlist(ArrayList list){
    for(int i=0;i<list->size;i++){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}
int main(){
    struct List list;
    if(initlist(&list)){
        for(int i=0;i<6;i++)
            list.array[i]=i;
        list.array[6]=5;
        list.size=7;
        printlist(&list);
        delete_same(&list);
        printlist(&list);
    }
}