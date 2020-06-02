#include<bits/stdc++.h>
#include <vector>
 
typedef std::pair<int, int> iPair;
 
struct Graph
{
    int V, E;
    std::vector< std::pair<double, iPair> > edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
 
    void addEdge(int u, int v, double w)
    {
        edges.push_back({w, {u, v}});
    }
 
    void kruskalMST();
};
 
 
struct DisjointSets
{
    int *parent, *rnk;
    int n;
 
    explicit DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
 
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
 
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
 
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
 
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
 
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
 
void Graph::kruskalMST()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    double mst_wt = 0;
    std::vector<std::pair<int, int>> tmp_v;
    sort(edges.begin(), edges.end());
 
    DisjointSets ds(V);
 
    std::vector<std::pair<double, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
 
        int set_u = ds.find(u);
        int set_v = ds.find(v);
 
        if (set_u != set_v)
        {
            tmp_v.emplace_back(u + 1, v + 1);
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }
 
    std::cout << std::fixed << std::setprecision(6) << mst_wt << std::endl;
    std::cout << tmp_v.size() << std::endl;
    for (auto & i : tmp_v) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}
 
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    int x[n];
    int y[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    Graph g(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto tmp = (double)sqrt(std::pow((((double)x[i] - (double)x[j])), 2) + std::pow((((double)y[i] - (double)y[j])), 2));
            g.addEdge(i, j, tmp);
        }
    }
 
    g.kruskalMST();
 
    return 0;
}