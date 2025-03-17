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
        int u = min_heap.top().first;
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int w = edge.weight;
            if (!visited[v] && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                previous[v] = u;
                min_heap.push({v, distances[v]});
            
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    for (int d = destination; d != -1; d = previous[d]) {
        path.push_back(d);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total)
{
    for (int n : v) {
        cout << n << " ";
    }
    cout << "(Cost: " << total << ")" << endl;
}