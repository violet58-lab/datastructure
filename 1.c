Enqueue(x): // x 入队
if not Stackoverflow(S1):
    Push(S1,x);

Dequeue(x): // x 出队
if QueueEmpty(): return;
t = null; // t是临时变量
while not StackEmpty(S1):
    Pop(S1,t); 
    Push(S2,t);
Pop(S2,t);
x = t;
while not StackEmpty(S2):
    Pop(S2,t); 
    Push(S1,t);

QueueEmpty():
    return StackEmpty(S1)