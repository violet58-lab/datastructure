#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int element;
    struct ListNode * next;
};

typedef struct ListNode * Node;
Node deletelist_same(Node head){//因为有序，所以用p扫描链表，若p所指的值与后继相等则删后者，否则直接后移
    Node p=head->next,q;
    if(p==NULL)return NULL;
    while(p->next){//要考虑尾元素
        if(p->element==p->next->element){
            q=p->next;
            p->next=q->next;
            free(q);
        }
        else{
            p=p->next;
        }
    }
    return head;
}
int main(){
    struct ListNode head;
    
}