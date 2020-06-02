#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <cstring>
 
std::vector<std::pair<int, int>> graph[100100];
std::vector<int> bridges_in_the_graph[100100];
int x1[100100], x2[100100], x3[100100], timer = 1;
 
void dfs(int index, int p) {
    x1[index]++;
    x2[index] = x3[index] = timer++;
    for (size_t i = 0; i < graph[index].size(); ++i) {
        int to = graph[index][i].first;
        int edge_id = graph[index][i].second;
        if(edge_id == p)
            continue;
        if(x1[to])
        {
            x3[index] = std::min(x3[index], x2[to]);
        }
        else
        {
            dfs(to, edge_id);
            x3[index] = std::min(x3[index], x3[to]);
            if(x2[index] < x3[to])
            {
                bridges_in_the_graph[index].push_back(to);
                bridges_in_the_graph[to].push_back(index);
            }
        }
    }
}
 
void delete_edges(int index) {
    sort(bridges_in_the_graph[index].begin(), bridges_in_the_graph[index].end());
    std::vector<std::pair<int, int>> tmp;
    for(int i = graph[index].size() - 1; i >= 0; --i) {
        if(!bridges_in_the_graph[index].empty() && bridges_in_the_graph[index].back() == graph[index][i].first) {
            bridges_in_the_graph[index].pop_back();
            continue;
        }
        tmp.push_back(graph[index][i]);
    }
    graph[index] = tmp;
}
 
void dfs2(int index, std::vector<int> &vis) {
    x1[index]++;
    vis.push_back(index);
 
    for (auto & i : graph[index]) {
        int to = i.first;
        if(!x1[to])
            dfs2(to, vis);
    }
}
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (size_t i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        if(a == b) {
            continue;
        }
        a -= 1;
        b -= 1;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }
    for (size_t i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    for (size_t i = 0; i < n; ++i) {
        if (!x1[i]) {
            dfs(i, -1);
        }
    }
    for (size_t i = 0; i < n; ++i) {
        delete_edges(i);
    }
    memset(x1, 0, sizeof x1);
    std::vector<std::vector<int>> ans;
    for (size_t i = 0; i < n; ++i) {
        if (!x1[i]) {
            std::vector<int> vis;
            dfs2(i, vis);
            sort(vis.begin(), vis.end());
            ans.push_back(vis);
        }
    }
    sort(ans.begin(), ans.end());
    std::cout<< ans.size() << std::endl;
    for (auto & an : ans) {
        for (int j : an) {
            std::cout << j + 1 << " ";
        }
        std::cout << std::endl;
    }
}