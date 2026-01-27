#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define maxsize 100
#define E int
typedef struct {
    E stack[maxsize];
    int top[2];
}stk;
stk s;
int push(int i,E x){//入栈
    if(i<0||i>1){printf("栈号输入不对");exit(0);}
    if(s.top[1]-s.top[0]==1){printf("栈已满");return 0;}
    switch(i){
        case 0:s.stack[++s.top[0]]=x;return 1;break;
        case 1:s.stack[--s.top[1]]=x;return 1;
    }
}//出栈
E pop(int i){
    if(i<0||i>1){printf("栈号输入不对");exit(0);}
    switch(i){
        case 0:if(s.top[0]==-1){printf("栈空\n");return -1;}
        else{return s.stack[s.top[0]--];}break;
        case 1:if(s.top[1]==maxsize){printf("栈空\n");return -1;}
        else{return s.stack[s.top[1]++];}break;
    }
}
int main(){
    s.top[0] = -1; 
    s.top[1] = maxsize;
    push(0,1);
    push(0,3);
    push(1,2);
    push(1,4);
    printf("%d\n",pop(0));
    printf("%d\n",pop(1));
}