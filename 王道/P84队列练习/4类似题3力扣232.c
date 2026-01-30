#include <stdlib.h>
#include <stdbool.h>

typedef int E;
struct stack{
    E *array;
    int top;
    int capacity;
};
typedef struct {
    struct stack s1;
    struct stack s2;
} MyQueue;

typedef struct stack * ArrayStack;
void initstack(ArrayStack stack){
    stack->array=malloc(sizeof(E)*1000);
    stack->capacity = 1000;
    stack->top = -1;
}
void pushstack(ArrayStack stack,E x){
    stack->array[++stack->top]=x;
}
E popstack(ArrayStack stack){
    int e=stack->array[stack->top--];
    return e;
}
E peekstack(ArrayStack stack){
    return stack->array[stack->top];
}
bool isempty(ArrayStack stack){
    return stack->top == -1;
}
MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    initstack(&q->s1);
    initstack(&q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    pushstack(&obj->s1,x);
}

int myQueuePop(MyQueue* obj) {
    if (isempty(&obj->s2)) {
        while (!isempty(&obj->s1)) {
            E t = popstack(&obj->s1);
            pushstack(&obj->s2, t);
        }
    }
    return popstack(&obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (isempty(&obj->s2)) {
        while (!isempty(&obj->s1)) {
            E t = popstack(&obj->s1);
            pushstack(&obj->s2, t);
        }
    }
    return peekstack(&obj->s2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isempty(&obj->s1)&&isempty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1.array);
    free(obj->s2.array);
    free(obj);
}