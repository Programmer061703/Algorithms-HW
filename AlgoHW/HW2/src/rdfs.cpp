#include <search.hpp>

void rdfs(Graph &G, int start, int destination) {
    // Mark the current node as visited
    G.visited[start] = true;
    if (start == destination) {
        return;
    }
    int numberOfAdjacencyNodes = G.e[start].size();
    LinkedListNode<int> *p = G.e[start].getRoot();
    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
        int v = p->value;
        if (!G.visited[v]) {
            G.setTrace(v, start); 
            rdfs(G, v, destination);
        }
    }
}

