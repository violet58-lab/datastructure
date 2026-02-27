#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int UFSets[SIZE];

void init(int s[]){//初始化,s为并查集
    for(int i=0;i<SIZE;i++)
        s[i]=-1;//每个元素自成集合
}

int find(int s[],int x){//查找祖先或集合代表
    while(s[x]>=0)
        x=s[x];//寻找x的祖先
    return x;//祖先的s[]小于0
}

void Union(int s[],int root1,int root2){//合并
    if(root1==root2)return;
    s[root2]=root1;//root2连在root1下面
}

void Union1(int s[],int root1,int root2){//改进的合并操作，小树合并到大树上
    if(root1==root2)return;
    if(s[root2]>s[root1]){//root2结点数更少
        s[root1]+=s[root2];//累加集合树的结点总和
        s[root2]=root1;
    }else{
        s[root2]+=s[root1];
        s[root1]=root2;
    }
}
int find1(int s[],int x){
    int root=x;
    while(s[root]>=0)//循环找根/祖先
        root=s[root];
    while(x!=root){//压缩路径
        int t=s[x];
        s[x]=root;
        x=t;
    }
    return root;
}

void printSetInfo(int s[], int n) {//打印结点、祖先
    printf("index: ");
    for (int i = 0; i < n; i++) printf("%3d", i);
    printf("\nparent:");
    for (int i = 0; i < n; i++) printf("%3d", s[i]);
    printf("\n\n");
}

// 判断无向图是否有环
// n: 顶点个数（顶点编号假设为 0..n-1）
// edges: 边集，每条边是 (u, v)
// m: 边数
// 有环返回 1，无环返回 0
int hasCycleUndirected(int n, const int edges[][2], int m) {
    // 安全检查：n 不能超过 SIZE
    if (n > SIZE) return -1; // 表示参数不合法

    init(UFSets);

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // 顶点编号合法性检查
        if (u < 0 || u >= n || v < 0 || v >= n) return -1;

        int ru = find1(UFSets, u);
        int rv = find1(UFSets, v);

        // 同一集合里再连边 => 出现环
        if (ru == rv) return 1;

        Union1(UFSets, ru, rv);
    }
    return 0;
}

int main(){
    init(UFSets);

    int n = 10;

    Union1(UFSets, find1(UFSets, 0), find1(UFSets, 1)); // {0,1}
    Union1(UFSets, find1(UFSets, 2), find1(UFSets, 3)); // {2,3}
    Union1(UFSets, find1(UFSets, 3), find1(UFSets, 4)); // {2,3,4}
    Union1(UFSets, find1(UFSets, 5), find1(UFSets, 6)); // {5,6}
    Union1(UFSets, find1(UFSets, 6), find1(UFSets, 7)); // {5,6,7}

    printf("After unions:\n");
    printSetInfo(UFSets, n);

    printf("Find roots (with path compression):\n");
    for (int i = 0; i < n; i++) {
        printf("root(%d) = %d\n", i, find1(UFSets, i));
    }
    printf("\n");

    printf("After path compression:\n");
    printSetInfo(UFSets, n);

    Union1(UFSets, find1(UFSets, 0), find1(UFSets, 2));

    printf("After merging set {0,1} with {2,3,4}:\n");
    printSetInfo(UFSets, n);

     // 图1：0-1-2-0 有环
    int edges1[][2] = {{0,1},{1,2},{2,0}};
    printf("graph1 cycle? %d\n", hasCycleUndirected(3, edges1, 3)); // 1

    // 图2：0-1-2-3 无环
    int edges2[][2] = {{0,1},{1,2},{2,3}};
    printf("graph2 cycle? %d\n", hasCycleUndirected(4, edges2, 3)); // 0

    return 0;
}