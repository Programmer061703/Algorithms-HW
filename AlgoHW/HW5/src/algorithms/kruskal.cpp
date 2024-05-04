#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>


std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges();
    std::vector<Edge> mst;
    
    // Step 1: Sort the edges in non-decreasing order of their weights
    std::sort(edges.begin(), edges.end());

    // Step 2: Initialize Disjoint Set
    DisjointSet djs(G.n);

    // Step 3: Iterate through sorted edges
    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Check if adding the edge creates a cycle
        if (djs.isOnSameSet(u, v) == 0) {
            // Add the edge to the MST
            mst.push_back(edge);
            // Merge the sets of its endpoints
            djs.join(u, v);
        }
    }

    return mst;
}

