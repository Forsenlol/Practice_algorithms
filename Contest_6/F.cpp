#include<bits/stdc++.h>
 
#define LL long long
 
const int max_m = 20000;
const int max_n = 500;
const LL INF = LONG_LONG_MAX;
std::vector<int> best;
std::vector<int> start(max_n, -1);
bool used[max_n];
int idx;
int dist[max_n];
int s, t;
int quick[max_n];
int ptr[max_n];
 
struct Edge {
    int v;
    int u;
    int capacity;
    LL flow;
};
 
Edge graph[max_m];
 
void bfs(const int& n) {
    int pred = 0, prev = 1;
    for (int i = 0; i < n; ++i) {
        dist[i] = n + 1;
    }
    quick[0] = s, dist[s] = 0;
    while (pred < prev) {
        int u = quick[pred++];
        for (int j = start[u]; j != -1; j = graph[j].u) {
            if ((dist[graph[j].v] > dist[u] + 1) && (graph[j].capacity - graph[j].flow > 0)) {
                dist[graph[j].v] = dist[u] + 1, quick[prev++] = graph[j].v;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ptr[i] = start[i];
    }
}
 
LL dfs(int v, LL m) {
    if ((v == t) || (m == 0)) {
        return m;
    }
    LL res = 0;
    for ( ; (m > 0) && (ptr[v] != -1); ptr[v] = graph[ptr[v]].u) {
        if (dist[graph[ptr[v]].v] != dist[v] + 1) {
            continue;
        }
        LL tmp = dfs(graph[ptr[v]].v, std::min(m, 0ll + graph[ptr[v]].capacity - graph[ptr[v]].flow));
        if (tmp > 0) {
            graph[ptr[v]].flow += tmp;
            graph[ptr[v] ^ 1].flow -= tmp;
            m -= tmp;
            res += tmp;
            if (m == 0) {
                return res;
            }
        }
    }
    return res;
}
 
void many_dfs(int v) {
    if (used[v]) {
        return;
    }
    best.push_back(v);
    used[v] = true;
    for (int j = start[v]; j != -1; j = graph[j].u) {
        if (graph[j].capacity - graph[j].flow > 0) {
            many_dfs(graph[j].v);
        }
    }
}
 
void input(int& n){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> n;
    std::string in;
    for (int i = 0; i < n; ++i) {
        std::cin >> in;
        for (int j = 0; j < n; ++j) {
            if (in[j] == '1') {
                graph[idx].v = j;
                graph[idx].u = start[i];
                graph[idx].capacity = 1;
                graph[idx].flow = 0;
                start[i] = idx;
                idx += 1;
                graph[idx].v = i;
                graph[idx].u = start[j];
                graph[idx].capacity = 0;
                graph[idx].flow = 0;
                start[j] = idx;
                idx += 1;
            }
        }
    }
}
 
void output(const int& n) {
    std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr);
    for (int i : best) {
        std::cout << i + 1 << " ";
        used[i] = true;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            std::cout << i + 1 << " ";
        }
    }
}
 
void algo(const int& n) {
    s = 0;
    LL min_flow = INF;
    for (t = 1; t < n; ++t) {
        for (int i = 0; i < idx; ++i) {
            graph[i].flow = 0;
        }
        LL flow = 0;
        for (int i = 0; i < n; ++i) {
            bfs(n);
            flow += dfs(s, INF);
        }
        if (flow < min_flow) {
            best.clear();
            memset(used, 0, sizeof(used));
            many_dfs(0);
            min_flow = flow;
        }
    }
    memset(used, 0, sizeof(used));
}
 
int main() {
    int n = 0;
    input(n);
    algo(n);
    output(n);
    return 0;
}