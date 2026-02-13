#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int flag;
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

T peekstack(SNode head){//获取栈顶元素的值
    return head->next->element;
}

void PostOrder(Node root){//先用符号位判断右孩子是否也遍历成功
    struct StackNode head;
    initstack(&head);
    while(root || !isempty(&head)){
        while(root){
            pushstack(&head,root);
            root->flag=0;
            root=root->left;
        }
        root = peekstack(&head);
        if(root->flag == 0){
            root->flag = 1;
            root = root->right;
        }else{
            printf("%c",root->element);//先输出，再出栈，因为popstack返回值可有可无
            popstack(&head);
            root = NULL;//跳过while，继续取栈里面的结点
        }
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
    
    PostOrder(a);
}