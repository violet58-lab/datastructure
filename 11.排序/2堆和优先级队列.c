#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//大顶堆
typedef int E;
typedef struct MaxHeap{
    E *arr;
    int size;
    int capacity;
}* Heap;

bool initHeap(Heap heap){
    heap->size = 0;
    heap->capacity = 10;
    heap->arr = malloc(sizeof(E)*10);
    return heap->arr != NULL;
}

bool insert(Heap heap,E element){
    if(heap->size == heap->capacity)return 0;//满了可以不处理，也可以扩容
    int index = ++heap->size;//计算出插入位置
    while(index > 1 && element > heap->arr[index/2]){//比父节点大，要处理。一直循环找到插入位置
        heap->arr[index] = heap->arr[index/2];
        index /= 2;
    }
    //找到插入位置，直接插
    heap->arr[index] = element;
    return 1;
}

void printHeap(Heap heap){
    for(int i=1;i<=heap->size;++i)
        printf("%d ",heap->arr[i]);
}

E delete(Heap heap){
    E max = heap->arr[1],e = heap->arr[heap->size--];//取出最大的元素，最后一个元素
    int index = 1;
    while(index * 2 <= heap->size){//从上往下找
        int child = index *2;
        if(child < heap->size && heap->arr[child]<heap->arr[child+1])//比较左孩子与右孩子哪个大
            child += 1;
        if(e >= heap->arr[child])break;//如果子节点都不大于新节点，说明就是这个位置了
        else heap->arr[index] = heap->arr[child];
        index = child;
    }
    heap->arr[index] = e;
    return max;

}

int main(){
    struct MaxHeap heap;
    initHeap(&heap);

    insert(&heap,5);
    insert(&heap,2);
    insert(&heap,3);
    insert(&heap,7);
    insert(&heap,6);
    
    printHeap(&heap);
    printf("\n");

    for(int i=0;i<5;++i){
        printf("%d ",delete(&heap));
    }
}