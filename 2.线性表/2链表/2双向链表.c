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
    head->next=head->prev=NULL;
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

    if(head->next!=NULL){//如果插入最后一个位置，就不需要后继节点的改变了
        node->next = head->next;
        head->next->prev = node;
    }else{//后继节点置为空
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 1;
}//2.删除节点
bool deletelist(Node head,int index){
    if(index<1)return 0;
    while(--index){
        head=head->next;
        if(head==NULL)return 0;
    }
    if(head->next==NULL)return 0;
    Node tmp=head->next;
    if(head->next->next){
        head->next=head->next->next;
        head->next->next->prev=head;
    }else{
        head->next=NULL;//若删最后的，将最后的本身置空
    }
    free(tmp);
    return 1;
}
int main(){
    struct ListNode head;
    initlist(&head); 
    for(int i=1;i<5;i++){
        insertlist(&head,i*10,i);
    }//正向遍历
    Node node = &head;
    deletelist(&head,1);
    do{
        node=node->next;
        printf("%d->",node->element);
    }while(node->next);
    printf("\n");
}