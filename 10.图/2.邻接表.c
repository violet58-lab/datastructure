#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5

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

int main(){
    Graph graph = create();
    for(int c = 'A';c<='D';++c)
        addVertex(graph,(char)c);
    addEdge(graph,0,1);//A->B，表示几号单元到几号单元
    addEdge(graph,1,2);//B->C
    addEdge(graph,2,3);//C->D
    addEdge(graph,3,0);//D->A
    addEdge(graph,2,0);//C->A

    printGraph(graph);
}