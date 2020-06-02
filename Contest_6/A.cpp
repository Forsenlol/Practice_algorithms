//https://clck.ru/N8ZqM
#include<bits/stdc++.h>
 
struct Edge {
    Edge(int to, int maxcapacity, int revindex)
            : to(to), maxcapacity(maxcapacity), flow(0), revindex(revindex) {}
 
    int get_capacity() const {
        return maxcapacity - flow;
    }
 
    int flow;
    const int to, maxcapacity, revindex;
};
 
struct Graph {
 
    Graph(int n, int m) : n(n), m(m), start(0), finish(n - 1) {
        edges.resize(n);
    }
 
    void add_connection(int from, int to, int maxc) {
        order.emplace_back(from, edges[from].size());
        insert(from, to, maxc);
        insert(to, from, maxc);
    }
 
    Edge& get_reverse(int from, int index) {
        Edge e = edges[from][index];
        return edges[e.to][e.revindex];
    }
 
    const int n, m, start, finish;
    std::vector<std::vector<Edge>> edges;
    std::list<std::pair<int, int>> order;
 
private:
    void insert(int from, int to, int maxc) {
        edges[from].push_back(Edge(to, maxc, edges[to].size()));
        edges[to].push_back(Edge(from, 0, int(edges[from].size()) - 1));
    }
};
 
 
std::pair<bool, std::vector<int>> bfs(int capacity, Graph& graph) {
    std::vector<int> level(graph.n, std::numeric_limits<int>::max());
    level[graph.start] = 0;
 
    std::queue<int> q;
    q.push(graph.start);
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (auto& e: graph.edges[v]) {
            if (level[e.to] == std::numeric_limits<int>::max() && e.get_capacity() >= capacity) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
 
    return {level[graph.finish] != std::numeric_limits<int>::max(), std::move(level)};
}
 
int dfs(int v, Graph& graph, std::vector<int>& block, std::vector<int>& level,
        int mincapacity = std::numeric_limits<int>::max()) {
    if (v == graph.finish) {
        return mincapacity;
    }
    if (mincapacity == 0) {
        return 0;
    }
 
    for (size_t i = block[v]; i < graph.edges[v].size(); ++i) {
        Edge& e = graph.edges[v][i];
 
        if (level[e.to] != level[v] + 1) {
            continue;
        }
 
        int flow_get;
        flow_get = dfs(e.to, graph, block, level, std::min(e.get_capacity(), mincapacity));
        if (flow_get) {
            e.flow += flow_get;
            graph.get_reverse(v, i).flow -= flow_get;
 
            return flow_get;
        }
        ++block[v];
    }
 
    return 0;
}
 
 
double dinic_iter(int capacity, Graph& graph) {
    double result = 0;
    auto [keep_going, level] = bfs(capacity, graph);
    while (keep_going) {
        std::vector<int> block(graph.n, 0);
 
        double flow;
        flow = dfs(graph.start, graph, block, level);
        while (flow != 0) {
            for (int i = 0; i < graph.n; ++i) {
            }
            result += flow;
            flow = dfs(graph.start, graph, block, level);
        }
        auto pr = bfs(capacity, graph);
        keep_going = pr.first;
        level = pr.second;
    }
    return result;
}
 
double dinic(Graph& graph) {
    int maxcap = std::numeric_limits<int>::max();
    double answer = 0;
    while (maxcap) {
        answer += dinic_iter(maxcap, graph);
        maxcap /= 2;
    }
 
    return answer;
}
 
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Graph graph(n, m);
 
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph.add_connection(--a, --b, c);
    }
 
    double answer = dinic(graph);
    std::cout << std::setprecision(8) << answer << '\n';
    for (auto num: graph.order) {
        int curflow = graph.edges[num.first][num.second].flow;
        if (curflow == 0) {
            curflow = graph.edges[num.first][num.second + 1].flow;
        }
        std::cout << std::setprecision(8) << curflow << '\n';
    }
 
    return 0;
}