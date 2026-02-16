#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char E;

/* ========= Huffman树结点 ========= */
typedef struct TreeNode{
    E element;                 // 叶子存字符
    struct TreeNode *left;
    struct TreeNode *right;
    int value;                 // 权重
}TreeNode;

typedef TreeNode* Node;

/* ========= 优先队列（升序链表） ========= */
typedef struct QNode{
    Node element;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;   // dummy头
    QNode *rear;
}Queue;


/* ========= 队列初始化 ========= */
bool initQueue(Queue *q){
    QNode *dummy = malloc(sizeof(QNode));
    if(!dummy) return false;

    dummy->next = NULL;
    q->front = q->rear = dummy;
    return true;
}


/* ========= 创建树结点 ========= */
Node createNode(E element,int val){
    Node node = malloc(sizeof(TreeNode));
    node->element = element;
    node->left = node->right = NULL;
    node->value = val;
    return node;
}


/* ========= 按value升序插入 ========= */
bool offerQueue(Queue *q,Node x){
    QNode *n = malloc(sizeof(QNode));
    if(!n) return false;

    n->element = x;
    n->next = NULL;

    QNode *pre = q->front;

    while(pre->next && pre->next->element->value <= x->value){
        pre = pre->next;
    }

    n->next = pre->next;
    pre->next = n;

    if(pre == q->rear)
        q->rear = n;

    return true;
}


/* ========= 出队 ========= */
Node pollQueue(Queue *q){
    if(q->front->next == NULL)
        return NULL;

    QNode *first = q->front->next;
    Node e = first->element;

    q->front->next = first->next;

    if(q->rear == first)
        q->rear = q->front;

    free(first);
    return e;
}


/* ========= Huffman编码 ========= */
char* encode(Node root,E e){

    if(root == NULL)
        return NULL;

    // 找到叶子
    if(root->left == NULL && root->right == NULL && root->element == e){
        char *s = malloc(1);
        s[0] = '\0';
        return s;
    }

    // 左
    char *str = encode(root->left,e);

    if(str != NULL){
        char *s = malloc(strlen(str) + 2); // '0'+str+'\0'
        s[0] = '0';
        strcpy(s+1,str);
        free(str);
        return s;
    }

    // 右
    str = encode(root->right,e);

    if(str != NULL){
        char *s = malloc(strlen(str) + 2);
        s[0] = '1';
        strcpy(s+1,str);
        free(str);
        return s;
    }

    return NULL;
}


/* ========= 打印编码 ========= */
void printEncode(Node root,E e){
    char *code = encode(root,e);

    if(code){
        printf("%c 的编码为: %s\n",e,code);
        free(code);
    }else{
        printf("%c 未找到\n",e);
    }
}


/* ========= 主函数 ========= */
int main(){

    Queue q;
    initQueue(&q);

    // 构建叶子
    offerQueue(&q,createNode('A',5));
    offerQueue(&q,createNode('B',16));
    offerQueue(&q,createNode('C',8));
    offerQueue(&q,createNode('D',13));


    /* ========= 构建Huffman树 ========= */
    while(q.front->next != q.rear){

        Node left = pollQueue(&q);
        Node right = pollQueue(&q);

        Node parent = createNode('#',left->value + right->value);
        parent->left = left;
        parent->right = right;

        offerQueue(&q,parent);
    }

    Node root = pollQueue(&q);


    /* ========= 输出编码 ========= */
    printEncode(root,'A');
    printEncode(root,'B');
    printEncode(root,'C');
    printEncode(root,'D');

    return 0;
}