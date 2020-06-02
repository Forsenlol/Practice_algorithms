#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
 
int const N = 100000;
std::vector<int> graph[N];
bool visited[N];
std::stack<int> topSort;
 
void dfs(const int &v)
{
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    int size = graph[v].size();
    for (int i = 0; i < size; ++i) {
        dfs(graph[v].at(i));
    }
    topSort.push(v);
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < m; ++i) {
        int from = 0;
        int to = 0;
        std::cin >> from >> to;
        from -= 1;
        to -= 1;
        graph[from].push_back(to);
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    bool isUnique = true;
    int uniTopSort[n];
    int v = 0;
    while (!topSort.empty()) {
        int curV = topSort.top();
        uniTopSort[v] = curV;
        v++;
        topSort.pop();
    }
    for (int i = 1; i < n; ++i) {
        int from = uniTopSort[i - 1];
        int to = uniTopSort[i];
        if (find(graph[from].begin(), graph[from].end(), to) == graph[from].end()) {
            isUnique = false;
            break;
        }
    }
    if (!isUnique) {
        std::cout << "NO";
    }
    else {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << uniTopSort[i] + 1 << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}