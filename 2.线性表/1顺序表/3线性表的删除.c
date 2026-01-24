#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct List{
    E * array;
    int capacity;//顺序表当前的长度(容量)
    int size;//顺序表当前的元素个数
};

typedef struct List * ArrayList;

_Bool initlist(ArrayList list){
    list->array = malloc(sizeof(E)*10);
    if(list->array==NULL)return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}//index为位序
_Bool deletelist(ArrayList list,int index){
    if(index<1||index>list->size) return 0;
    for(int i = index-1;i<list->size-1;++i)
        list->array[i]=list->array[i+1];
    list->size--;
    return 1;
}
void printlist(ArrayList list){//编写一个用于打印表当前的数据
    for(int i =0;i<list->size;i++)
        printf("%d ",list->array[i]);
    printf("\n");
}
int main(){
    struct List list={0};
    if(initlist(&list)){
        list.array[0]=42;
        list.size=1;
        if(deletelist(&list,1))
            printf("删除成功");
        printlist(&list);
    }
    else
        printf("顺序表初始化失败");
}