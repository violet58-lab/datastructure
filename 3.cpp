bool bfs(Graph graph,int startVertex,int targetVertex,int *visited,queue<int> &q)
{
    q.push(startVertex);
    visited[startVertex] = 1;
    while(!q.empty()) {
        int next = q.front();
        q.pop();
        cout<<graph->vertex[next].element<<" -> ";
        List node = graph->vertex[next].next;
        while(node) {
            if(node->nextVertex == targetVertex) return 1;
            if(!visited[node->nextVertex]) {
                q.push(node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    return 0;
}