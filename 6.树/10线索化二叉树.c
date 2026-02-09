#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int lefttag;
    int righttag;
}* Node;

Node createNode(E element){
    Node node = malloc(sizeof(struct TreeNode));
    node->left=node->right=NULL;
    node->righttag=node->lefttag=0;
    node->element=element;
    return node;
}

Node pre = NULL;//在外面存一下上一个节点
void PreOrderThreaded(Node root){
    if(root==NULL)return;
    if(root->left==NULL){
        root->left=pre;
        root->lefttag=1;
    }
    if(pre && pre->right==NULL){
        pre->right=root;
        pre->righttag=1;
    }
    pre = root;//更新一下pre
    if(root->lefttag==0)//本身左边有节点才往左走
        PreOrderThreaded(root->left);
    if(root->righttag==0)
        PreOrderThreaded(root->right);
}

void inorder(Node root){
    while(root){
        printf("%c",root->element);
        if(root->lefttag==0)
            root=root->left;
        else 
            root=root->right;
    }
}

int main(){
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');
    Node f = createNode('F');

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    c->left=NULL;
    d->left=d->right=NULL;
    e->left=e->right=NULL;
    f->left=f->right=NULL;
    
    PreOrderThreaded(a);
    inorder(a);
}