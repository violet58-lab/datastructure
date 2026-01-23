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
}
void reverse(ArrayList list,int left,int right,int maxsize){//左右为索引
    if(left>=right||right>=maxsize)return;
    int mid=(left+right)/2;
    for(int i=0;i<=mid-left;i++){//i为左右分别向中间移动的距离大小！！！
        int t = list->array[left+i];
        list->array[left+i]=list->array[right-i];
        list->array[right-i]=t;
    }
}
void printlist(ArrayList list){
    for(int i=0;i<list->size;i++){
        printf("%d ",list->array[i]);
    }
    printf("\n");
}
int main(){
    struct List A;
    if(initlist(&A)){
        int m=6,n=3;
        for(int i=0;i<m;i++)
            A.array[i]=i;
        for(int i=0;i<n;i++)
            A.array[i+m]=i;
        A.size = m + n;//注意要更新size!!!
        printlist(&A);
        reverse(&A,0,8,9);
        reverse(&A,0,2,9);
        reverse(&A,3,8,9);
        printlist(&A);
    }
    else
        printf("顺序表初始化失败");
}