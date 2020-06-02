#include<bits/stdc++.h>
#include<vector>
 
#define INF 101
 
void input(int& n, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& result) {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::vector<int> temp (n, 0);
        graph.push_back(temp);
        result.push_back(temp);
        for(int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }
}
 
void floyd(int n, std::vector<std::vector<int>>& graph) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                if ((graph[i][k] < INF) && (graph[k][j] < INF)) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                    if (graph[i][j] < -INF) {
                        graph[i][j] = -INF;
                    }
                }
            }
        }
    }
}
 
void check(int n, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                result[i][j] = 0;
            }
            else {
                result[i][j] = 1;
                for (int k = 0; k < n; k++) {
                    if (graph[k][k] < 0 && graph[i][k] < INF && graph[k][j] < INF) {
                        result[i][k] = 2;
                        result[i][j] = 2;
                        result[k][j] = 2;
                    }
                }
            }
        }
    }
}
 
void out_result(int n, std::vector<std::vector<int>>& result) {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    for (int i = 0; i < n; ++i) {
        std::cout << result[i][0];
        for (int j = 1; j < n; ++j) {
            std::cout << " " << result[i][j];
        }
        std::cout << std::endl;
    }
}
 
int main() {
    int n = 0;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> result;
 
    input(n, graph, result);
    floyd(n ,graph);
    check(n, graph, result);
    out_result(n, result);
 
    return 0;
}