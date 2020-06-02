#include<bits/stdc++.h>
#include<vector>
 
#define max_size 5001
#define INF 1000000000000001
 
struct Edge {
    int v;
    int64_t weight;
    Edge(int v, int64_t weight) : v(v), weight(weight) {};
};
 
void bellman_ford(int s, int n, std::vector<std::vector<Edge>>& graph, std::vector<int64_t>& dist) {
    dist[s] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (size_t k = 0; k < graph[j].size(); ++k) {
                int to = graph[j][k].v;
                int64_t temp_weight = graph[j][k].weight;
                if (dist[j] < INF && dist[to] > dist[j] + temp_weight) {
                    dist[to] = dist[j] + temp_weight;
                }
            }
}
 
void dfs(int v, std::vector<std::vector<Edge>>& graph, std::vector<int>& used) {
    used[v] = 1;
    for (auto & vertex : graph[v]) {
        int to = vertex.v;
        if (!used[to]) {
            dfs(to, graph, used);
        }
    }
}
 
void input(int& n, int& m, int& s, std::vector<std::vector<Edge>>& graph) {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::cin >> n >> m >> s;
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        int64_t weight = 0;
        std::cin >> u >> v >> weight;
        graph[u].push_back(Edge(v, weight));
    }
}
 
void check(int n, std::vector<int>& used, std::vector<int64_t>& dist, std::vector<std::vector<Edge>>& graph) {
    for (int i = 1; i <= n; ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            int to = graph[i][j].v;
            int64_t temp_weight = graph[i][j].weight;
            if (dist[i] < INF && dist[to] > dist[i] + temp_weight && !used[to]) {
                dfs(to, graph, used);
            }
        }
    }
}
 
void out_result(int n, std::vector<int64_t>& dist, std::vector<int>& used) {
    for(int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            std::cout << "*" << std::endl;
        }
        else if (used[i]) {
            std::cout << "-" << std::endl;
        }
        else {
            std::cout << dist[i] << std::endl;
        }
    }
}
 
int main() {
    int n = 0;
    int m = 0;
    int s = 0;
    std::vector<std::vector<Edge>> graph;
    std::vector<int64_t> dist (max_size, INF);
    std::vector<int> used (max_size, 0);
 
    input(n, m, s, graph);
    bellman_ford(s, n, graph, dist);
    check(n, used, dist, graph);
    out_result(n, dist, used);
 
    return 0;
}