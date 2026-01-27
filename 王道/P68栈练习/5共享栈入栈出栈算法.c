#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int E;
typedef struct Stack * ArrayStack;
struct Stack {//共享栈必须指向同一数组！！！
    E *array;
    int capacity;
    int top1;
    int top2;
};//s1入栈
void pushs1(ArrayStack stack,E x){
    stack->array[++stack->top1]=x;//注意先加再用
}
//s2入栈
void pushs2(ArrayStack stack,E x){
    stack->array[--stack->top2]=x;
}//s1出栈
E pops1(ArrayStack stack){
    return stack->array[stack->top1--];
}//s2出栈
E pops2(ArrayStack stack){
    return stack->array[stack->top2++];
}
int main(){
    int maxsize=10;
    struct Stack sharestack;
    sharestack.array=malloc(sizeof(E)*maxsize);
    if(sharestack.array!=NULL){
        sharestack.capacity = maxsize;//容量也要设！！！
        sharestack.top1=-1;
        sharestack.top2=maxsize;//初始化
        pushs1(&sharestack,1);
        pushs1(&sharestack,3);
        pushs2(&sharestack,4);
        printf("%d\n",pops1(&sharestack));
        printf("%d\n",pops1(&sharestack));
    }
}