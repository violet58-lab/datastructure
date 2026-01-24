#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int E;
struct ListNode{//定义
    E element;
    struct ListNode * next;
};
typedef struct ListNode * Node;
void initlist(Node node){//初始化
    node->next = NULL;//头结点置为空
}//1.插入节点
bool insertlist(Node head,E element,int index){
    if(index<1)return 0;
    while(--index){//头结点一直往后走
        head = head->next;
        if(head==NULL)return 0;//不能越界(例如插在最后一个)
    }
    Node node = malloc(sizeof(struct ListNode));//插入的元素组成的链表
    if(node==NULL)return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}//2.删除节点
bool deletdlist(Node head,int index){//位序
    if(index<1)return 0;
    while(--index){//不能删最后一个，越界了
        head=head->next;
        if(head == NULL)return 0;
    }
    if(head->next == NULL)return 0;
    Node temp =head->next;//先存一下，之后删
    head->next = head->next->next;//1.改其前驱节点
    free(temp);//2.删去元素节点free
    return 1;
}//3.获取对应位置的元素
E * getlist(Node head,int index){
    if(index<1)return 0;
    do{//因为头结点不算，用do-while
        head=head->next;
        if(head == NULL)return 0;
    }while(--index);
    return &head->element;
}//4.查找对应元素的位置
int findlist(Node head,E element){
    head = head->next;//因为头结点为随机值，从第一个开始算
    int i=1;//计数器
    while(head){//找到返回位序
        if(head->element == element)return i;
        head = head->next;
        i++;
    }
    return -1;//没找到返回-1
}//5.获取链表的长度
int sizelist(Node head){
    int i=-1;//从-1开始，为了不计入头结点
    while(head){//那么第一次就是检查head本身是否为空
        head=head->next;
        i++;
    }
    return i;
}
void printlist(Node head){//打印
    while(head->next){
        head =head->next;
        printf("%d",head->element);
    }
}
int main(){
    struct ListNode head;
    initlist(&head);
}