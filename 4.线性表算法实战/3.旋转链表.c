/*将链表每个位置向右移动k个位置，
每移动一个位置，将最后一个移到前面来。
连成循环链表，只须将最终的位置定下来*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int element;
    struct ListNode * next;
};

typedef struct ListNode * Node;
struct ListNode* rotateright(struct ListNode* head,int k){
    if(head==NULL||k==0)return head;
    int len=1;
    struct ListNode* node=head;
    while(node->next){
        node=node->next;
        len++;
    }
    if(len==k)return head;

    node->next=head;//连起来
    int i=len-k%len;//断n-k的地方
    while(--i)head=head->next;
    struct ListNode * res=head->next;//存一下头结点
    head->next=NULL;
    return res;
}
int main(){
    struct ListNode head;
}