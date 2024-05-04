#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};



std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> mst;

    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> pq;
    std::vector<bool> visited(G.n, false);
    std::vector<int> parent(G.n, -1); // parent vertex for each vertex in MST

    // Choose starting vertex
    int start = 0; 

    // Mark starting vertex as visited
    visited[start] = true;

    
    for (const Edge& e : G.e[start]) {
        pq.push(e);
    }

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.u;
        int v = curr.v;

        // Check if destination vertex is visited
        if (visited[v])
            continue;

        // Mark destination vertex as visited
        visited[v] = true;

        // Add edge to MST
        mst.push_back(curr);
        parent[v] = u;

        
        for (const Edge& e : G.e[v]) {
            if (!visited[e.v]) {
                pq.push(e);
            }
        }
    }

    return mst;
}


