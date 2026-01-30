bool Enqueue(int x){//将元素x入队
    if(!StackEmpty(s1)){
        push(s1,x);
        return 1;
    }
    else if(StackOverflow(s1)&&StackEmpty(s2)){
        while(!StackEmpty(s1)){
            pop(s1,x);
            push(s2,x);
        }
        push(s1,x);
        return 1;
    }
    else if(StackOverflow(s1)&&!StackEmpty(s2)){
        printf("队列已满");
        return 1;
    }
}
bool Dequeue(int x){
    if(StackEmpty(s1)&&StackEmpty(s2)){
        printf("队列已空");
        return 0;
    }else if(StackEmpty(s2)&&!StackEmpty(s1)){
        while(!StackEmpty(s1)){
            pop(s1,x);
            push(s2,x);
        }
        pop(s2,x);
        return 1;
    }
    else{
        pop(s2,x);
        return 1;
    }
}
bool QueueEmpty(){
    return StackEmpty(s1)&&StackEmpty(s2);
}