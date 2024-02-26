#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset(); 
    stack.push(start);
    G.visited[start] = true; // Mark the start vertex as visited
    G.setTrace(start, -1); 

    while (!stack.empty()) {
        int u = stack.pop();
        
        
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if (!G.visited[v]) { 
                G.visited[v] = true; 
                G.setTrace(v, u); 
                stack.push(v); 
            }
        }
    }
}


