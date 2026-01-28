#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct LNode{//定义
    E element;
    struct LNode * next;
};
typedef struct LNode * Node;
struct queue{
    Node front,rear;
};
typedef struct queue * LinkedQueue;
bool initqueue(LinkedQueue queue){//初始化，指向同一个
    Node node = malloc(sizeof(struct LNode));
    if(node==NULL)return 0;
    queue->front=queue->rear=node;//指向同一个
    return 1;
}//1.入队
bool offerqueue(LinkedQueue queue,E element){
    Node node=malloc(sizeof(struct LNode));
    if(node ==NULL)return 0;
    node->element=element;
    node->next=NULL;
    queue->rear->next=node;
    queue->rear=node;
    return 1;
}//2.判断是否为空
bool isempty(LinkedQueue queue){
    return queue->rear==queue->front;
}//3.出队
E pollqueue(LinkedQueue queue){
    Node tmp=queue->front->next;
    E e=tmp->element;
    queue->front->next=queue->front->next->next;
    if(queue->rear==tmp)queue->rear=queue->front;//如果队尾是出队节点，那么队尾要回到队首
    free(tmp);
    return e;
}
void printqueue(LinkedQueue queue){
    printf("<<<");
    Node node=queue->front->next;
    while(node){
        printf("%d ",node->element);
        node=node->next;
    }
    printf(">>>");
    printf("\n");
}
int main(){
    struct queue queue;
    initqueue(&queue);
    for(int i=0;i<5;i++)
        offerqueue(&queue,i*100);
    printqueue(&queue);
    while(!isempty(&queue))
        printf("%d ",pollqueue(&queue));
}