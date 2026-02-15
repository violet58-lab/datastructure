#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode{
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
}* Node;
Node createNode(E element){
    Node node = malloc(sizeof(struct TreeNode));
    node->left=node->right=NULL;
    node->element=element;
    return node;
}

Node insert(Node root,E element){
    if(root){
        if(root->element>element)
            root->left = insert(root->left,element);//还要找，找到为空的位置才行
        else if(root->element<element)
            root->right = insert(root->right,element);
    }else{
        root=createNode(element);
    }
    return root;
}

Node find(Node root,E target){
    while(root){
        if(root->element > target)
            root = root->left;
        else if(root->element < target)
            root = root->right;
        else
            return root;
    }return NULL;//找不到返回空
}

Node findmax(Node root){
    while(root && root->right)
        root = root->right;
    return root;
}

Node delete(Node root,E target){
    if(root == NULL)return NULL;//都走到底了还是没有找到要删除的结点，说明没有，直接返回空
    if(root->element >target)
        root->left = delete(root->left,target);
    else if(root->element < target)
        root->right = delete(root->right,target);
    else{//这种情况是找到了
        if(root->left && root->right){//有两个孩子结点
            Node max = findmax(root->left);
            root->element = max->element;
            root->left = delete(root->left,root->element);
        }else{//其他两种情况一起处理
            Node tmp = root;
            if(root->left){//不是左边就是右边
                root = root->right;
            }else{
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}

void InOrder(Node root){
    if(root==NULL)return;
    InOrder(root->left);
    printf("%d ",root->element);
    InOrder(root->right);
}

int main(){
    Node root = insert(NULL,18);//注意插入的顺序
    insert(root,10);
    insert(root,20);
    insert(root,7);
    insert(root,5);
    insert(root,22);
    insert(root,9);
    InOrder(root);
    printf("\n");
    printf("%p\n",find(root,17));
    printf("%p\n",find(root,9));
    delete(root,9);
    InOrder(root);
}