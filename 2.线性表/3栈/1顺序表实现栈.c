#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
struct Stack {
    E *array;
    int capacity;
    int top;//栈顶的位置，存栈顶元素的下标，默认-1
};
typedef struct Stack * ArrayStack;
bool initstack(ArrayStack stack){//初始化
    stack->array = malloc(sizeof(E)*10);
    if(stack->array==NULL)return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}//1.入栈(push)
bool pushstack(ArrayStack stack,E element){//栈满了要扩容
    if(stack->top+1==stack->capacity){
        int newcapacity=stack->capacity+(stack->capacity>>1);
        E * newArray = malloc(sizeof(E)*newcapacity);
        if(newArray==NULL)return 0;
        stack->array=newArray;
        stack->capacity=newcapacity;
    }
    stack->array[++stack->top]=element;//top要先递增再使用
}//2.判断栈是否为空
bool isempty(ArrayStack stack){
    return stack->top == -1;
}//3.出栈
E popstack(ArrayStack stack){
    return stack->array[stack->top--];//top自减在后面
}
void printstack(ArrayStack stack){
    for(int i=0;i<stack->top+1;++i){
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}
int main(){
    struct Stack stack;
    initstack(&stack);
    for(int i=0;i<3;++i)
        pushstack(&stack,i*100);
    printstack(&stack);
    while(!isempty(&stack))
        printf("%d ",popstack(&stack));
}