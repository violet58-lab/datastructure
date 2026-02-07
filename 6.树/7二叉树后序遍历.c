#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
}* Node;

void PostOrder(Node root){
    if(root==NULL)return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c",root->element);
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