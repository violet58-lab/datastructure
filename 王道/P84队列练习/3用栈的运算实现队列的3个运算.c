//入队
int EnQueue(Stack &s1,Stack &s2,ElemType e){
    if(!StackOverflow(s1)){//如果栈没满
        push(s1,e);
        return 1;
    }
    if(StackOverflow(s1)&&!StackOverflow(s2)){
        printf("队列已满");
        return 0;
    }
    if(StackOverflow(s1)&&StackOverflow(s2)){
        while(!StackEmpty(s1)){
            pop(s1,x);
            push(s2,x);
        }
    }
    push(s1,e);
    return 1;
}
//出队
void DeQueue(Stack &s1,Stack &s2,ElemType &x){
    if(!StackEmpty(s2)){
        pop(s2,x);
    }
    else if(StackEmpty(s1)){
        printf("队列为空");
    }
    else {
        while(!StackEmpty(s1)){
        pop(s1,x);
        push(s2,x);}
        pop(s2,x);
    }
}//判断队列是否为空
int QueueEmpty(Stack s1,Stack s2){
    if(StackEmpty(s1)&&StackEmpty(s2))return 1;
    return 0;
}