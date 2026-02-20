#include <stdio.h>
#include <stdlib.h>

typedef int E;
typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int height;//记录子树的高度，便于计算平衡因子
}* Node;

Node createNode(E element){
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;//高度初始化为1
    return node;
}

int max(int a,int b){
    return a > b ? a : b; 
}

int getheight(Node root){
    if(root == NULL)return 0;
    return root->height;
}

Node leftRotation(Node root){//传入原本根节点，返回新根节点
    Node newroot = root->right;//取出新根节点
    root->right = newroot->left;
    newroot->left = root;

    root->height = max(getheight(root->left),getheight(root->right))+1;
    newroot->height = max(getheight(newroot->left),getheight(newroot->right))+1;
    return newroot;
}

Node rightRotation(Node root){
    Node newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;

    root->height = max(getheight(root->left),getheight(root->right))+1;
    newroot->height = max(getheight(newroot->left),getheight(newroot->right))+1;
    return newroot;
}

Node leftrightRotation(Node root){
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node rightleftRotation(Node root){
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node insert(Node root,E element){
    if(root==NULL){//如果结点为空，说明找到了插入位置，直接创建
        root = createNode(element);
    }else if(root->element >element){//和二叉树一样，判断该往哪走往哪走
        root->left = insert(root->left,element);
        if(getheight(root->left) - getheight(root->right) > 1){//插入之后计算平衡因子，看是否失衡
            if(root->left->element > element)//判断插入左子树左边还是右边
                root = rightRotation(root);
            else
                root = leftrightRotation(root);
        }
    }else if(root->element < element){
        root->right = insert(root->right,element);
        if(getheight(root->left) - getheight(root->right) < -1){
            if(root->right->element <element)
                root = leftRotation(root);
            else
                root = rightleftRotation(root);
        }
    }
    root->height = max(getheight(root->left),getheight(root->right))+1;
    return root;
}

int main(){
    Node root = NULL;
    while(1){
        E e;
        scanf("%d",&e);
        if(e==0)break;
        root = insert(root,e);
    }
}