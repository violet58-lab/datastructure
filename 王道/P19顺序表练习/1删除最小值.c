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
int deletelist(ArrayList list){
    if(list->size==0)return -1;
    int p=0;//简化：用一个值把i记下来！！！p一定要初始化！！！
    int min=list->array[0];
    for(int i =0;i<list->size;i++)
        if(list->array[i]<min){
            min = list->array[i];
            p = i;}
    list->array[p]=list->array[list->size-1];
    list->size--;
    return min;
}
void printlist(ArrayList list){//编写一个用于打印表当前的数据
    for(int i =0;i<list->size;i++)
        printf("%d ",list->array[i]);
    printf("\n");
}
int main(){
    struct List list;
    if(initlist(&list)){
        list.array[0]=1;
        list.array[1]=2;
        list.array[2]=3;
        list.size=3;
        printlist(&list);
        printf("%d\n",deletelist(&list));
        printlist(&list);
    }
}