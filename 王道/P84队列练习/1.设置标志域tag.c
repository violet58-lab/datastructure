#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct queue{
    E *array;
    int capacity;
    int front,rear;
    int tag;
};
typedef struct queue * ArrayQueue;
bool initqueue(ArrayQueue queue){
    queue->array=malloc(sizeof(E)*10);
    if(queue->array==NULL)return 0;
    queue->capacity=10;
    queue->front=queue->rear=0;
    queue->tag=0;
    return 1;
}
bool offerqueue(ArrayQueue queue,E x){
    if(queue->rear==queue->front&&queue->tag==1)return 0;//注意要判断队列是否满
    queue->array[queue->rear]=x;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->tag=1;
    return 1;
}
bool pollqueue(ArrayQueue queue){//注意要判断队列是否空，如果队空就不能出队了
    if(queue->rear==queue->front&&queue->tag==0)return 0;
    E x=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->tag=0;
    return 1; 
}
int main(){
    struct queue queue;
    initqueue(&queue);
}