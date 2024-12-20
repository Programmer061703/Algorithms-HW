#include <graph.hpp>
#include <climits>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {
    std::vector<int> path;

    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> pq;
    std::vector<int> dist(G.n, INT_MAX); 
    std::vector<int> parent(G.n, -1);    

    dist[start] = 0;
    pq.push(Edge(start, start, 0)); 

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.v;
        int w = curr.w;

 
        if (w > dist[u])
            continue;

        for (const Edge &e : G.e[u]) {
            int v = e.v;
            int weight = e.w;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(Edge(v, v, dist[v]));
            }
        }
    }

    // Reconstruct path
    int current = destination;
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}
