#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
}* Node;

typedef Node T;
struct QueueNode{
    T element;
    struct QueueNode * next;
};
typedef struct QueueNode * QNode;
struct Queue{
    QNode front,rear;
};
typedef struct Queue * LinkedQueue;
bool initqueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node==NULL)return 0;
    queue->front=queue->rear=node;
    node->next = NULL;
    return 1;
}
bool offerqueue(LinkedQueue queue,T element){
    QNode node=malloc(sizeof(struct QueueNode));
    if(node ==NULL)return 0;
    node->element=element;
    node->next=NULL;
    queue->rear->next=node;
    queue->rear=node;
    return 1;
}
bool isempty(LinkedQueue queue){
    return queue->rear==queue->front;
}
T pollqueue(LinkedQueue queue){
    QNode tmp=queue->front->next;
    T e=tmp->element;
    queue->front->next=queue->front->next->next;
    if(queue->rear==tmp)queue->rear=queue->front;
    free(tmp);
    return e;
}

void LevelOrder(Node root){
    struct Queue queue;
    initqueue(&queue);
    offerqueue(&queue,root);//队首入队
    while(!isempty(&queue)){
        Node node = pollqueue(&queue);//队首出队，打印
        printf("%c",node->element);
        if(node->left)offerqueue(&queue,node->left);
        if(node->right)offerqueue(&queue,node->right);
    }
}

int main(){
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));

    a->element='A';
    b->element='B';
    c->element='C';
    d->element='D';
    e->element='E';
    f->element='F';

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    c->left=NULL;
    d->left=d->right=NULL;
    e->left=e->right=NULL;
    f->left=f->right=NULL;
    
    LevelOrder(a);
}