#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5
#define N 5
#define infinity 21000   // 定义无穷大

typedef char E;

typedef struct Node {
    int nextvertex;
    struct Node *next;
} *Node;

struct HeadNode {
    E element;
    struct Node *next;
};

typedef struct AdjacencyGraph {
    int vertexCount, edgeCount;
    struct HeadNode vertex[MaxVertex];
} *Graph;

/* 创建图 */
Graph create() {
    Graph graph = (Graph)malloc(sizeof(struct AdjacencyGraph));
    if (graph == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    return graph;
}

/* 添加顶点 */
void addVertex(Graph graph, E element) {
    if (graph->vertexCount >= MaxVertex) {
        printf("顶点数已达到上限！\n");
        return;
    }
    graph->vertex[graph->vertexCount].element = element;
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

/* 添加边 a -> b */
void addEdge(Graph graph, int a, int b) {
    if (a < 0 || a >= graph->vertexCount || b < 0 || b >= graph->vertexCount) {
        printf("边(%d -> %d)越界！\n", a, b);
        return;
    }

    Node node = graph->vertex[a].next;
    Node newnode = (Node)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newnode->next = NULL;
    newnode->nextvertex = b;

    if (!node) {
        graph->vertex[a].next = newnode;
    } else {
        while (1) {
            if (node->nextvertex == b) {   // 防止重复边
                free(newnode);
                return;
            }
            if (node->next)
                node = node->next;
            else
                break;
        }
        node->next = newnode;
    }
    graph->edgeCount++;
}

/* 打印邻接表 */
void printGraph(Graph graph) {
    printf("邻接表如下：\n");
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextvertex);
            node = node->next;
        }
        putchar('\n');
    }
}

/* Dijkstra：这里统一使用 0 ~ n-1 下标 */
void dijkstra(int matrix[N][N], int x, int n) {   // x是源点
    int i, k;
    int path[N];
    int mark[N];
    int min, dist[N];

    for (i = 0; i < n; i++) {
        mark[i] = 0;
        dist[i] = matrix[x][i];
        if (matrix[x][i] < infinity && i != x)
            path[i] = x;       // 能直接到，就前驱设为源点
        else
            path[i] = -1;      // 不可达
    }

    dist[x] = 0;
    mark[x] = 1;
    path[x] = -1;

    do {
        min = infinity;
        k = -1;

        for (i = 0; i < n; i++) {
            if (!mark[i] && dist[i] < min) {
                min = dist[i];
                k = i;
            }
        }

        if (k != -1) {
            mark[k] = 1;
            for (i = 0; i < n; i++) {
                if (!mark[i] &&
                    matrix[k][i] < infinity &&
                    dist[k] + matrix[k][i] < dist[i]) {
                    dist[i] = dist[k] + matrix[k][i];
                    path[i] = k;
                }
            }
        }
    } while (k != -1);

    /* 输出结果 */
    printf("\n从顶点 %d 出发的最短路径结果：\n", x);
    for (i = 0; i < n; i++) {
        printf("到顶点 %d 的最短距离 = ", i);
        if (dist[i] >= infinity)
            printf("∞");
        else
            printf("%d", dist[i]);

        printf("，前驱 = ");
        if (path[i] == -1)
            printf("无");
        else
            printf("%d", path[i]);

        putchar('\n');
    }
}

int main() {
    Graph graph = create();

    for (int c = 'A'; c <= 'D'; ++c)
        addVertex(graph, (char)c);

    addEdge(graph, 0, 1);   // A -> B
    addEdge(graph, 1, 2);   // B -> C
    addEdge(graph, 2, 3);   // C -> D
    addEdge(graph, 3, 0);   // D -> A
    addEdge(graph, 2, 0);   // C -> A

    printGraph(graph);

    /* 邻接矩阵
       这里给每条边都设权值 1
       没有边的地方设为 infinity
    */
    int matrix[N][N] = {
        {0,        1,        infinity, infinity, infinity},
        {infinity, 0,        1,        infinity, infinity},
        {1,        infinity, 0,        1,        infinity},
        {1,        infinity, infinity, 0,        infinity},
        {infinity, infinity, infinity, infinity, 0}
    };

    dijkstra(matrix, 0, 4);   // 从顶点0(A)出发，前4个点参与运算

    return 0;
}