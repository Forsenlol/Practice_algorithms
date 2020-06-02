#include <bits/stdc++.h>
#include <stack>
 
int cycle = 0;
 
void dfs(const int v, const std::vector<std::vector<int>>& graph, int visited[], std::stack<int> &result) {
    visited[v] = 1;
    for(size_t j = 0; j < graph[v].size(); ++j) {
        if(visited[graph[v][j]] == 1) {
            cycle = 1;
        }
        if(!visited[graph[v][j]]) {
            dfs(graph[v][j], graph, visited, result);
        }
    }
    visited[v] = 2;
    result.push(v);
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<int> temp;
    std::vector<std::vector<int>> graph;
    graph.reserve(n);
    for(int i = 0; i < n; ++i) {
        graph.push_back(temp);
    }
    for(int i = 0; i < m; ++i) {
        std::pair<int, int> tmp;
        std::cin >> tmp.first >> tmp.second;
        graph[tmp.first - 1].push_back(tmp.second - 1);
    }
 
    std::stack<int> result;
    int *visited = new int[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }
    if (cycle == 1) {
        std::cout << "-1";
        return 0;
    }
 
    while (!result.empty()) {
        std::cout << result.top() + 1 << " ";
        result.pop();
    }
    
    delete[](visited);
 
    return 0;
}