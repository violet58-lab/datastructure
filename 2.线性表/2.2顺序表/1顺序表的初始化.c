#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct List{
    /*E array[10];*///数组
    E * array;
    int capacity;//顺序表当前的长度(容量)
    int size;//顺序表当前的元素个数
};

typedef struct List * ArrayList;
//顺序表初始化函数
//结构体传参也是拷贝，所以要传指针
/*void initlist(ArrayList list){
    list->capacity = 10;
}*///这样就指定大小了，要动态分配，用malloc(stdlib.h)
_Bool initlist(ArrayList list){
    list->array = malloc(sizeof(E)*10);
    if(list->array==NULL)return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}
int main(){
    struct List list;
    if(initlist(&list)){
        printf("顺序表初始化成功\n");
    }
    else
        printf("顺序表初始化失败");
}