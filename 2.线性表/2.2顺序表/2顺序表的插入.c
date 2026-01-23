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
    list->size = 0;//存一个变量
    return 1;
}
//参数分别为线性表，插入元素，插入位置。index为位序,size为元素个数,i为索引
_Bool insertlist(ArrayList list,E element,int index){
    if(index<1||index>list->size+1)return 0;//判断插入位置是否越界
    if(list->size == list->capacity){
        int newcapacity = list->capacity+(list->capacity>>1);//右移就是除2，变为1.5倍
        E *newarray = realloc(list->array,sizeof(E)*newcapacity);//重新申请，原来的直接复制过来
        if(newarray==NULL)return 0;
        list->array = newarray;
        list->capacity = newcapacity;
    }
    for(int i=list->size;i>index-1;--i)
        list->array[i] = list->array[i-1];
    list->array[index-1]=element;
    list->size++;
    return 1;
}
void printlist(ArrayList list){//编写一个用于打印表当前的数据
    for(int i =0;i<list->size;i++)
        printf("%d ",list->array[i]);
    printf("\n");
}
int main(){
    struct List list;
    if(initlist(&list)){
        insertlist(&list,666,1);
        printlist(&list);
        insertlist(&list,777,1);
        printlist(&list);
        insertlist(&list,888,2);
        printlist(&list);
        free(list.array);
    }
    else
        printf("顺序表初始化失败");
}