#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int nv = G.size();
    vector<int> distances(nv, INF);
    vector<bool> visited(nv, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>> min_heap;
    min_heap.push({source, 0});
    while(!min_heap.empty()) {
        int u = min_heap.extractVertexWithMinimumWeight().first;
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int w = edge.second;
            if (!visited[v] && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                previous[v] = u;
                min_heap.push({v, distances[v]});
            
            }
        }
    }
    return distances;
}

// vector<int> extract_shortest_path(const vector<int>& /*distances*/, comst vector<int>& previous, int destination)
// {

// }

void print_path(const vector<int>& v, int total)
{
    for (int v : path) {
        cout << v << " ";
    }
    cout << "(Cost: " << total << ")" << endl;
}