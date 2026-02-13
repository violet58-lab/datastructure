#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode * Node;

typedef Node T;

struct StackNode {
    T element;
    struct StackNode * next;
};
typedef struct StackNode * SNode;
typedef Node T;
void initstack(SNode head){
    head->next = NULL;
}
bool pushstack(SNode head,T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node==NULL)return 0;
    node->element=element;
    node->next=head->next;
    head->next=node;
    return 1;
}
bool isempty(SNode head){
    return head->next==NULL;
}

T popstack(SNode head){
    SNode tmp=head->next;
    T e = tmp->element;
    head->next=head->next->next;
    free(tmp);
    return e;
}

void PreOrder(Node root){//防止root为空直接结束循环
    struct StackNode head;//先定义栈
    initstack(&head);
    while(root || !isempty(&head)){
        while(root){
            printf("%c",root->element);
            pushstack(&head,root);
            root=root->left;
        }
        Node node = popstack(&head);
        root = node->right;
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
    
    PreOrder(a);
}