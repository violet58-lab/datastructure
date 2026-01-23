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
int sizelist(ArrayList list){
    return list->size;
}
E *getlist(ArrayList list,E index){//按序查找
    if(index<1||index>list->size)return NULL;
    return &list->array[index-1];//注意这里要取地址，解引用！！！
}
int findlist(ArrayList list,int element){//按值查找
    for(int i = 0;i<list->size;i++)
        if(list->array[i]==element)return i+1;
    return -1;
}
void printlist(ArrayList list){//编写一个用于打印表当前的数据
    for(int i =0;i<list->size;i++)
        printf("%d ",list->array[i]);
    printf("\n");
}
int main(){
    struct List list={0};
    if(initlist(&list)){//参数为指针传参要解引用，返回指针数组也要解引用！！！
        list.array[0]=42;
        list.size=1;
        printlist(&list);
        printf("%d\n",findlist(&list,42));//注意换行符！！！
        printf("%d",*getlist(&list,1));//函数名称写全！！！
    }
    else
        printf("顺序表初始化失败");
}