#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int E;
struct ListNode{//定义
    E element;
    struct ListNode * next;
    struct ListNode * prev;
};
typedef struct ListNode * Node;
void initlist(Node head){//初始化
    head->next = NULL;
    head->prev = NULL;
}//1.插入节点
bool insertlist(Node head,E element,int index){
    if(index<1)return 0;
    while(--index){
        head = head->next;
        if(head==NULL)return 0;
    }
    Node node =malloc(sizeof(struct ListNode));
    if(node==NULL)return 0;
    node->element = element;

    if(head->next!=NULL){
        node->next = head->next;
        head->next->prev = node;
    }else{
        node->next = NULL;
    }

    head->next = node;
    node->prev = head;

    return 1;
}    
int main(){
    struct ListNode head;
    initlist(&head); 
}