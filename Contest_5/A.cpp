#include<bits/stdc++.h>
#include<vector>
#include<deque>
#define max_len 10001
 
int used[max_len];
int prev[max_len];
 
void bfs(std::vector<std::vector<int>> graph, int vertex, std::deque<int>& deq) {
    deq.push_front(vertex);
    used[vertex] = 1;
    while(!deq.empty()) {
        int u = deq.front();
        deq.pop_front();
        for(int v : graph[u]) {
            if(!used[v]) {
                used[v] = 1;
                prev[v] = prev[u] + 1;
                deq.push_back(v);
            }
        }
    }
}
 
void out_result(int n) {
    for(int i = 0; i < n; ++i) {
        std::cout << prev[i] << " ";
    }
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int start = 0;
    std::cin >> n >> start;
 
    std::vector<std::vector<int>> graph;
    std::deque<int> deq;
 
    for(int i = 0; i < n; ++i) {
        used[i] = 0;
        prev[i] = -1;
        std::vector<int> line;
        for(int j = 0; j < n; ++j) {
            int temp = 0;
            std::cin >> temp;
            if (temp == 1) {
                line.push_back(j);
            }
        }
        graph.push_back(line);
    }
 
    prev[start - 1] = 0;
    bfs(graph, start - 1,  deq);
    out_result(n);
    
    return 0;
}
}