#include <bits/stdc++.h>
#include <set>
 
struct vertex {
    int visited{};
    int komp{};
    std::vector<int> graph;
    std::vector<int> komp_graph;
};
 
std::vector<int> vertex_list;
std::vector<vertex> vec;
int komp = 0;
 
void dfs(int v) {
    vec[v].visited = 1;
    for (size_t i = 0; i < vec[v].graph.size(); ++i) {
        if (!vec[vec[v].graph[i]].visited) {
            dfs(vec[v].graph[i]);
        }
    }
    vertex_list.push_back(v);
}
 
void my_dfs(int v, int komp) {
    vec[v].visited = 2;
    vec[v].komp = komp;
    for (size_t i = 0; i < vec[v].komp_graph.size(); ++i) {
        if (vec[vec[v].komp_graph[i]].visited != 2) {
            my_dfs(vec[v].komp_graph[i], komp);
        }
    }
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < m; ++i) {
        std::pair<int, int> tmp;
        std::cin >> tmp.first >> tmp.second;
        vec[tmp.first - 1].graph.push_back(tmp.second - 1);
        vec[tmp.second - 1].komp_graph.push_back(tmp.first - 1);
    }
    for (int i = 0; i < n; i++) {
        vec[i].visited = 0;
    }
    for(int i = 0; i < n; i++) {
        if (!vec[i].visited) {
            dfs(i);
        }
    }
    for(int i = static_cast<int>(vertex_list.size() - 1); i >= 0; --i) {
        if (vec[vertex_list[i]].visited != 2) {
            my_dfs(vertex_list[i], komp++);
        }
    }
    std::set<int> new_graph[10000];
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < static_cast<int>(vec[i].graph.size()); j++) {
            if (vec[i].komp != vec[vec[i].graph[j]].komp) {
                new_graph[vec[i].komp].insert(vec[vec[i].graph[j]].komp);
            }
        }
    }
    int result = 0;
    for(auto & i : new_graph) {
        result += i.size();
    }
    std::cout << result;
    return 0;
}