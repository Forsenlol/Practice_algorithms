#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
 
std::vector<std::pair<int64_t, int64_t>> graph[200001];
int64_t cites[100001];
std::vector<bool> used(200001, false);
std::vector<int64_t> tmp(200001);
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int64_t n, m;
    std::cin >> n >> m;
 
    for (int64_t i = 0; i < n; i++) {
        std::cin >> cites[i];
    }
 
    int adds = n;
    int64_t u = 0; 
    int64_t v = 0;
    for (int64_t i = 0; i < m; i++) {
        int64_t u, v;
        std::cin >> u >> v;
        u -= 1;
        v -= 1;
        if (cites[u] == cites[v]) {
            graph[u].emplace_back(v, 0);
            graph[v].emplace_back(u, 0);
        } 
        else {
            if ((u + 1) % 2 == 0) {
                graph[u].emplace_back(adds, 1);
                graph[adds].emplace_back(v, 1);
                adds++;
            } 
            else {
                graph[u].emplace_back(v, 1);
            }
            if ((v + 1) % 2 == 0) {
                graph[v].emplace_back(adds, 1);
                graph[adds].emplace_back(u, 1);
                adds++;
            } 
            else {
                graph[v].emplace_back(u, 1);
            }
        }
    }
 
    std::deque<int64_t> que;
    que.push_front(0);
    used[0] = true;
    tmp[0] = -1;
 
    while (!que.empty()) {
        int64_t v = que.front();
        que.pop_front();
        for (int64_t i = 0; i < graph[v].size(); ++i) {
            int64_t to = graph[v][i].first;
            if (!used[to]) {
                used[to] = true;
                if (graph[v][i].second == 0) {
                    que.push_front(to);
                }
                else {
                    que.push_back(to);
                }
                tmp[to] = v;
            }
        }
    }
 
    if (!used[n - 1]) {
        std::cout << "impossible\n";
    }
    else {
        std::vector<int64_t> path;
        for (int64_t v = n - 1; v != -1; v = tmp[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        int64_t count = 0;
        for (auto i:path) {
            if (i < n) {
                count += 1;
            }
        }
        int64_t weight = 0;
        for (int64_t i = 1; i < path.size(); i++) {
            bool flag = true;
            for (auto j : graph[path[i - 1]]) {
                if (j.first == path[i] && flag) {
                    weight += j.second;
                    flag = false;
                }
            }
        }
 
        std::cout << weight << " " << count << std::endl;
 
        for (int64_t i = 0; i < path.size(); ++i) {
            if (path[i] < n) {
                std::cout << path[i] + 1 << " ";
            }
        }
    }
}