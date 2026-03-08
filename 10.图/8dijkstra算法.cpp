//https://www.luogu.com.cn/problem/P4779
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    using pii = pair<int,int>; // distance, u(重要)
    int n,m,s;//n:点数，m:边数，s:起点
    cin >> n >> m >> s;//cin是输入
    auto graph = vector(n+1,vector<pii>()); // 邻接表，
    while(m--) {
        int u,v,c; // 有向边，u:起点，v:终点，c:长度
        cin >> u >> v >> c;
        graph[u].emplace_back(v,c);//存放点u的所有出边
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;//优先队列！！！q是小根堆
    auto min_dist = vector(n+1,INT_MAX);//距离数组
    auto calced = vector(n+1,0);//标记数组
    min_dist[s] = 0;//从起点 s 到点 s(可为i) 的当前最短距离，初始设为无穷大
    q.emplace(min_dist[s],s); // 距离一定放第一位
    while(q.size())//主函数，只要堆不空就继续
    {
        auto [dist,u] = q.top();//取堆顶元素
        q.pop();//删除堆顶元素
        if(calced[u]) continue;//跳过已经处理的点
        calced[u] = true;
        for(auto [v,c]:graph[u])//遍历所有的边
        {
            if(min_dist[v] <= min_dist[u] + c) continue;
            min_dist[v] = min_dist[u] + c;
            q.emplace(min_dist[v], v);//更新后入堆
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << min_dist[i] << " ";//输出答案
    return 0;
}