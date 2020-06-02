#include <bits/stdc++.h>
#include <stack>
 
std::pair<int, int> cycle = std::make_pair(0, 0);
 
void dfs(const int v, const std::vector<std::vector<int>>& graph, int visited[], int ptr[]) {
    visited[v] = 1;
    for(size_t j = 0; j < graph[v].size(); ++j) {
        if(visited[graph[v][j]] == 1) {
            cycle.first = graph[v][j];
            cycle.second = v;
        }
        if(!visited[graph[v][j]]) {
            ptr[graph[v][j]] = v;
            dfs(graph[v][j], graph, visited, ptr);
        }
    }
    visited[v] = 2;
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
 
    int *ptr = new int[n];
    int *visited = new int[n];
 
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, ptr);
        }
    }
    if (cycle.first == 0 and cycle.second == 0) {
        std::cout << "NO";
        return 0;
    }
 
    std::stack<int> my_stack;
    std::cout << "YES" << std::endl;
    int i = cycle.second;
    while(i != cycle.first) {
        my_stack.push(i + 1);
        i = ptr[i];
    }
    my_stack.push(i + 1);
 
    while (!my_stack.empty()) {
        std::cout << my_stack.top() << " ";
        my_stack.pop();
    }
 
    delete[](visited);
    delete[](ptr);
 
    return 0;
}