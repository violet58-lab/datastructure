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
_Bool delete(ArrayList list,int s,int t){
    if(s>=t||list->size==0)return 0;
    int k=0;
    for(int i=0;i<list->size;i++){
        if(list->array[i]>=s && list->array[i]<=t)
            k++;
        else list->array[i-k]=list->array[i];
    }
    list->size -= k;
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
        delete(&list,2,4);
        printlist(&list);
    }
}