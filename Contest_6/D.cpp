//https://izilearn.ru/index.php?r=acmp%2Fview&id=171
#include<bits/stdc++.h>
 
std::vector<int> tree;
 
int find_vertex(int v){
    if (v == tree[v]) {
        return v;
    }
    else {
        return tree[v] = find_vertex(tree[v]);
    }
}
 
void check_vertexes(int v, int u){
    v = find_vertex(v);
    u = find_vertex(u);
    if(v == u){
        return;
    }
    std::swap(v, u);
    tree[v] = u;
}
 
void prim() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    int64_t result = 0;
    tree.resize(n + 1);
    for(int k = 1; k<= n; ++k){
        tree[k]=k;
    }
    int b = 0; int e = 0; int w = 0;
    std::pair<int, std::pair<int, int>> graph[m];
    for(int k = 0; k < m; ++k) {
        std::cin >> b >> e >> w;
        graph[k] = std::make_pair(w, std::make_pair(b, e));
    }
    sort(graph, graph + m);
    int s = 0;
    for(int k = 0; k < m && s < n - 1; ++k){
        int i = find_vertex(graph[k].second.first);
        int j = find_vertex(graph[k].second.second);
        if (i != j){
            result += graph[k].first;
            s += 1;
            check_vertexes(i, j);
        }
    }
    std::cout << result;
}
 
int main(){
    prim();
    return 0;
}