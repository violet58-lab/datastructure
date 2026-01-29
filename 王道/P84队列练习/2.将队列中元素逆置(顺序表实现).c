//实现函数在最下面！！！
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct Queue{
    E * array;//数组
    int capacity;//容量
    int front,rear;//队首，队尾
}Q;
typedef struct Queue * ArrayQueue;
typedef struct Stack * ArrayStack;
struct Stack {
    E *array;
    int capacity;
    int top;//栈顶的位置，存栈顶元素的下标，默认-1
}S;
bool initqueue(ArrayQueue queue){
    queue->array=malloc(sizeof(E)*10);
    if(queue->array==NULL)return 0;
    queue->capacity=10;
    queue->front=queue->rear=0;
    return 1;
}
bool initstack(ArrayStack stack){
    stack->array = malloc(sizeof(E)*10);
    if(stack->array==NULL)return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}
bool offerqueue(ArrayQueue queue,E element){//注意要判断队列是否满
    int pos=(queue->rear+1)%queue->capacity;
    if(pos==queue->front)return 0;
    queue->rear=pos;
    queue->array[queue->rear]=element;
}//2.判断是否为空
bool isemptyq(ArrayQueue queue){
    return queue->front==queue->rear;
}//3.出队
E pollqueue(ArrayQueue queue){
    queue->front=(queue->front+1)%queue->capacity;
    return queue->array[queue->front];
}
bool pushstack(ArrayStack stack,E element){//栈满了要扩容
    if(stack->top+1==stack->capacity){
        int newcapacity=stack->capacity+(stack->capacity>>1);
        E * newArray = malloc(sizeof(E)*newcapacity);
        if(newArray==NULL)return 0;
        stack->array=newArray;
        stack->capacity=newcapacity;
    }
    stack->array[++stack->top]=element;//top要先递增再使用
}//2.判断栈是否为空
bool isemptys(ArrayStack stack){
    return stack->top == -1;
}//3.出栈
E popstack(ArrayStack stack){
    return stack->array[stack->top--];//top自减在后面
}
bool reversequeue(ArrayQueue queue){
    while(!isemptyq(&Q)){
        int x=pollqueue(&Q);//出队函数调用
        pushstack(&S,x);
    }
    while(!isemptys(&S)){
        int x=popstack(&S);
        offerqueue(&Q,x);
    }
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
    initqueue(&Q);
    initstack(&S);
    for(int i=0;i<5;i++)
        offerqueue(&Q,i*100);
    printqueue(&Q);
    reversequeue(&Q);
    printqueue(&Q);
}