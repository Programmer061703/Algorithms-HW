#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset(); // Reset the graph to clear any previous search states
    stack.push(start);
    G.visited[start] = true; // Mark the start vertex as visited
    G.setTrace(start, -1); // Set the start vertex's predecessor to -1 or a similar marker indicating no predecessor

    while (!stack.empty()) {
        int u = stack.pop();
        
        // Optional: Check if u is the destination; if so, you may want to break or do something specific
        
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            if (!G.visited[v]) { // If the vertex has not been visited
                G.visited[v] = true; // Mark it as visited
                G.setTrace(v, u); // Set the current vertex's predecessor to u
                stack.push(v); // Push the vertex onto the stack for further exploration
            }
        }
    }
}


