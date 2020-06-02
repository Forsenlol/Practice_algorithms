//https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
#include<bits/stdc++.h>
#include<list>
 
int arr[50001];
int count = 1;
 
class Graph {
    int V;
    std::list<int> *adj;
    void dfs(int v, bool visited[]);
public:
    explicit Graph(int V);
    void addEdge(int v, int w);
    void connectedComponents();
};
 
void Graph::connectedComponents() {
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++) {
        visited[v] = false;
    }
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            dfs(v, visited);
            count += 1;
        }
    }
}
 
void Graph::dfs(int v, bool visited[]) {
    visited[v] = true;
    arr[v] = count;
    std::list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
        if(!visited[*i]) {
            dfs(*i, visited);
        }
    }
}
 
Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; ++i) {
        std::pair<int, int> tmp;
        std::cin >> tmp.first >> tmp.second;
        g.addEdge(tmp.first - 1, tmp.second - 1);
    }
    g.connectedComponents();
    std::cout << count - 1 << std::endl;
    for(int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}