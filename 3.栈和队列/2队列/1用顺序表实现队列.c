#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct Queue{
    E * array;//数组
    int capacity;//容量
    int front,rear;//队首，队尾
};
typedef struct Queue * ArrayQueue;
bool initqueue(ArrayQueue queue){//初始化
    queue->array=malloc(sizeof(E)*10);
    if(queue->array==NULL)return 0;
    queue->capacity=10;
    queue->front=queue->rear=0;
    return 1;
}//1.入队
bool offerqueue(ArrayQueue queue,E element){//注意要判断队列是否满
    int pos=(queue->rear+1)%queue->capacity;
    if(pos==queue->front)return 0;
    queue->rear=pos;
    queue->array[queue->rear]=element;
}//2.判断是否为空
bool isempty(ArrayQueue queue){
    return queue->front==queue->rear;
}//3.出队
E pollqueue(ArrayQueue queue){
    queue->front=(queue->front+1)%queue->capacity;
    return queue->array[queue->front];
}
void printqueue(ArrayQueue queue){
    printf("<<<");
    int i=queue->front;//遍历队列要从头开始
    do{
        i=(i+1)%queue->capacity;//front指向对头前一个元素
        printf("%d ",queue->array[i]);
    }while(i!=queue->rear);
    printf(">>>");
    printf("\n");
}
int main(){
    struct Queue queue;
    initqueue(&queue);
    for(int i=0;i<5;i++)
        offerqueue(&queue,i*100);
    printqueue(&queue);
    while(!isempty(&queue))
        printf("%d ",pollqueue(&queue));
}