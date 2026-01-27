#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct LNode {
    int element;
    struct LNode * next;
};
typedef struct LNode * Node;
void initstack(Node head){//初始化
    head->next = NULL;
}//1，入栈
bool pushstack(Node head,E element){
    Node node = malloc(sizeof(struct LNode));
    if(node==NULL)return 0;
    node->element=element;
    node->next=head->next;
    head->next=node;
    return 1;
}//2.判断是否为空栈
bool isempty(Node head){
    return head->next==NULL;
}
//3.出栈
E popstack(Node head){
    Node tmp=head->next;
    E e = tmp->element;
    head->next=head->next->next;
    free(tmp);
    return e;
}
void printstack(Node head){//打印
    printf("| ");
    head=head->next;
    while(head){
        printf("%d ",head->element);
        head = head->next;
    }
    printf("\n");
}
int main(){
    struct LNode head;
    initstack(&head);
    for(int i=0;i<3;++i)
        pushstack(&head,i*100);
    printstack(&head);
    while(!isempty(&head))
        printf("%d ",popstack(&head));
}