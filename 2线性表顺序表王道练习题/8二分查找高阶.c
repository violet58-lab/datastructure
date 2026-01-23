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
void searchlist(ArrayList list,int x){
    int low=0,high=list->size-1,mid;//顺序表的上界和下界
    while(low<=high){
        mid=(low+high)/2;
        if(list->array[mid]==x)break;
        else if(list->array[mid]<x)low=mid+1;
        else high=mid-1;
    }
    if(list->array[mid]==x&&mid!=list->size-1){//找到就与后继元素交换
        int t=list->array[mid];
        list->array[mid]=list->array[mid+1];
        list->array[mid+1]=t;
    }
    else if(low>high){//找不到就插入，插到high那里
        int i=0;
        for(i=list->size-1;i>=low;i--) list->array[i+1]=list->array[i];
        list->array[i+1]=x;
        list->size++;
    }
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
        searchlist(&list,6);
        printlist(&list);
    }
}