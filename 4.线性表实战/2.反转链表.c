#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int element;
    struct ListNode * next;
};

typedef struct ListNode * Node;
struct ListNode* reverselist(Node head){//数据结构课
    Node newhead=NULL,tmp;
    while(head){
        tmp=head->next;//改指向之前要先存一下其下一个
        head->next=newhead;
        newhead=head;
        head=tmp;
    }
}
int main(){
    struct ListNode head;
}