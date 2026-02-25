#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertex 7

typedef char E;

typedef struct Node{//普通结点
    int nextvertex;
    struct Node * next;
}* Node;

struct HeadNode{//头结点
    E element;
    struct Node * next;
};

typedef struct AdjacencyGraph{
    int vertexCount,edgeCount;
    struct HeadNode vertex[MaxVertex];//存头结点
}* Graph;
Graph create(){
    Graph graph = malloc(sizeof(struct AdjacencyGraph));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;
}

void addVertex(Graph graph,E element){//插入顶点
    graph->vertex[graph->vertexCount].element = element;
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addEdge(Graph graph,int a,int b){//插入边
    Node node = graph->vertex[a].next;//找到第一个结点
    Node newnode = malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->nextvertex = b;//创建新插入的结点
    if(!node)//如果头结点下一个没有结点，直接连上去
        graph->vertex[a].next = newnode;
    else{
        do{
            if(node->nextvertex == b)return;//把前面内存释放
            if(node->next)node=node->next;
            else break;
        }while(1);
        node->next = newnode;
    }
    graph->edgeCount++;
}

void printGraph(Graph graph){
    for(int i = 0;i< graph->vertexCount;++i){
        printf("%d | %c",i,graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while(node){
            printf(" -> %d",node->nextvertex);
            node = node->next;
        }
        putchar('\n');
    }
}
typedef int T;   //这里将顶点下标作为元素

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}

bool bfs(Graph graph,int startVertex,int targetVertex,int * visited,LinkedQueue queue){
    offerQueue(queue,startVertex);
    visited[startVertex] = 1;
    while(!isEmpty(queue)){
        int next = pollQueue(queue);
        printf("%c -> ",graph->vertex[next].element);
        Node node = graph->vertex[next].next;
        while(node){
            if(node->nextvertex == targetVertex)return 1;
            if(!visited[node->nextvertex]){//如果没有走过，就直接入队
                offerQueue(queue,node->nextvertex);
                visited[node->nextvertex] = 1;
            }
            node = node->next;
        }
    }
    return 0;
}

int main(){
    Graph graph = create();
    for(int c = 'A';c<='G';++c)
        addVertex(graph,(char)c);
    addEdge(graph,0,1);//A->B，表示几号单元到几号单元
    addEdge(graph,1,2);//B->C
    addEdge(graph,1,3);//B->D
    addEdge(graph,1,4);//B->D
    addEdge(graph,4,5);//E->F
    addEdge(graph,3,6);//D->G

    int arr[graph->vertexCount];
    for(int i = 0;i<graph->vertexCount;++i)arr[i] = 0;
    struct Queue queue;
    initQueue(&queue);
    printf("\n%d",bfs(graph,0,3,arr,&queue));
}