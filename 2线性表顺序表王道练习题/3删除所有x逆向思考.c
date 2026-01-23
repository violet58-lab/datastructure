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
void deletelist(ArrayList list,int index){
    for(int i=index-1;i<list->size-1;i++)
        list->array[i]=list->array[i+1];
    list->size--;
}
/*void delete(ArrayList list,int x){
    for(int i=0;i<list->size;i++)
        if(list->array[i]==x) 
            deletelist(&list,i+1);
}*/
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
        for(int i=0;i<list.size;)
            if(list.array[i]==5){//用if会使相邻的无法删，所以当不是时才增加!!!
                deletelist(&list,i+1);}//用while会使下标访问越界
            else i++;
        printlist(&list);
    }
}