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
bool is_dc(Node head,int n){
    int i;
    char s[n/2];//s为字符栈
    Node p=head->next;//p为扫描指针
    for(i=0;i<n/2;i++){
        s[i]=p->element;
        p=p->next;
    }
    i--;//注意前面i越界了！！！
    if(n%2)//n为奇数，需要后移过中心节点
        p=p->next;
    while(p&&p->element==s[i]){
        i--;
        p=p->next;
    }
    if(i==-1)return 1;
    else return 0;
}
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
    printf("%d",is_dc(&L,4));
}