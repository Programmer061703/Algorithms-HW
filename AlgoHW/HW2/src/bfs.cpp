#include <search.hpp>

void bfs(Graph &G, int start, int destination) {
    Queue<int> queue;
    G.reset(); 
    queue.push(start);
    G.visited[start] = true; 
    G.setTrace(start, -1); 

    while (!queue.empty()) {
        int u = queue.pop();
        
        // Optional: Check if u is the destination; if so, you may want to break or do something specific
        
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i++, p = p->next) {
            int v = p->value;
            if (!G.visited[v]) {
                G.visited[v] = true; 
                G.setTrace(v, u); 
                queue.push(v); 
            }
        }
    }
}

