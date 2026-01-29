/*给定一个只包含括号(类似'()','{}','[]')的字符串s，判断字符串是否有效。
字符串有效：
1.左括号必须用相同类型的右括号闭合
2.左括号必须以正确的顺序闭合*/
//用栈实现，一半存入栈，一半比较，类似练习题的中心对称
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef char E;
struct LNode {
    E element;
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
bool isValid(char * s){
    unsigned long len=strlen(s);
    if(len%2)return 0;
    struct LNode head;
    initstack(&head);
    
    for(int i=0;i<len;++i){
    char c=s[i];
    if(c=='('||c=='{'||c=='['){
        pushstack(&head,c);
    }else{
        if(isempty(&head))return 0;//'[]]]]]'防止这种情况
        if(c==')'){
            if(popstack(&head)!='(')return 0;
        }else if(c=='}'){
            if(popstack(&head)!='{')return 0;
        }else if(c==']'){
            if(popstack(&head)!='[')return 0;
        }
    }
   }
   return isempty(&head);//'[[[[[]'这种情况
}
int main(){
    char s[5]="[[]]";//注意字符串最后的'\0'
    printf("%d",isValid(s));
}