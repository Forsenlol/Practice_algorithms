#include<bits/stdc++.h>
 
int n_global;
std::vector<int> graph[3000];
int capacity[3000][3000];
int flood[3000][3000];
int p[3000];
int distance[3000];
bool visited[3000];
std::pair<int, int> tasks[3000];
 
bool flow_optimization(int s, int t) {
    std::queue<int> q;
    int x = 0;
    int to = 0;
    for(int i = 1; i <= n_global; ++i) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[s] = 0;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        x  =q.front();
        q.pop();
        visited[x] = false;
        for(size_t i = 0; i < graph[x].size(); ++i) {
            to = graph[x][i];
            if((capacity[x][to] > 0) && (distance[to] > distance[x] + flood[x][to])) {
                distance[to] = distance[x] + flood[x][to];
                p[to] = x;
                if(visited[to]==0) {
                    q.push(to);
                    visited[to] = true;
                }
            }
        }
    }
    return distance[t] < INT_MAX;
}
int cost_flow(int s,int t) {
    int result = 0;
    int flow = 0;
    int x = 0;
    while(flow_optimization(s, t)) {
        flow = INT_MAX;
        for(x = t; x != s; x = p[x]) {
            flow = std::min(flow ,capacity[p[x]][x]);
        }
        for(x = t; x!=s; x=p[x]){
            capacity[x][p[x]] += flow;
            capacity[p[x]][x] -= flow;
            result += flow * flood[p[x]][x];
        }
 
    }
    return result;
}
void new_challenge(int x, int y, int c, int f) {
    graph[x].push_back(y);
    graph[y].push_back(x);
    capacity[x][y] = c;
    flood[x][y] = f;
    capacity[y][x] = 0;
    flood[y][x] = -f;
}
 
void input_param(int& n, int& k, int& t, int& s) {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> n >> k;
    n_global = 2 * n + 3;
    s = n_global - 2;
    t = n_global;
    new_challenge(s,s + 1, k,0);
    int a = 0;
    int b = 0;
    int c = 0;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a >> b >> c;
        tasks[i] = std::make_pair(a,a + b);
        new_challenge(i, i + n, 1, -1 * c);
        new_challenge(s + 1, i, 1, 0);
        new_challenge(i + n, t, 1, 0);
    }
}
 
void output_result(const int& n, std::string& result){
    std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr);
    for(int i = 1; i <= n; ++i)
        if(capacity[i][i + n] == 0){
            result += "1 ";
        }
        else {
            result += "0 ";
        }
    std::cout << result;
}
 
void get_progress(const int& n) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(tasks[i].second <= tasks[j].first) {
                new_challenge(i + n, j, 1, 0);
            }
        }
    }
}
 
int main() {
    int n = 0; int k = 0; int t = 0; int s = 0;
    input_param(n, k, t, s);
    get_progress(n);
    cost_flow(s, t);
    std::string result;
    output_result(n, result);
    return 0;
}