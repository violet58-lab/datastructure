#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef char C;
struct ListNode{
    C element;
    struct ListNode *next;
};
typedef struct ListNode * Node;
void initlist(Node head){
    head->next=NULL;
}
bool is_dc(Node head){//是否中心对称
    Node p=head->next,q,tmp=head;//定义头指针和尾指针,t指向头结点
    while(head->next)
        head=head->next;
    q=head;
    while(p&&q&&p!=q&&p->next!=q){
        if(p->element!=q->element)return 0;
        p=p->next;
        Node t=tmp->next;//t要重新初始化
        while(t){
            if(t->next==q){q=t;break;}
            t=t->next;
        }
    }
    return 1;
}//入栈
void pushstack(Node head, C x) {
    Node p = head;
    while (p->next) p = p->next;
    Node s = (Node)malloc(sizeof(struct ListNode));
    s->element = x;
    s->next = NULL;
    p->next = s;
}
int main(){
    struct ListNode L;
    initlist(&L);
    pushstack(&L,'x');
    pushstack(&L,'y');
    pushstack(&L,'y');
    pushstack(&L,'x');
    printf("%d",is_dc(&L));
}