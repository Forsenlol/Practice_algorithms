#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include<bits/stdc++.h>
#include <iomanip>
 
#define MN 300100
const int INF = INT_MAX;
 
std::vector<std::pair<int, int> > graph[MN];
int value[MN];
int holf[MN];
std::pair<int, int> tmp_fr[MN];
bool used[MN];
 
void dfs(int index, int n) {
	used[index] = true;
    for (int i = 0; i < (int)graph[index].size(); ++i) {
        int to = graph[index][i].second;
		if (!used[to] && value[to] == value[index] - 1) {
            dfs(to, n);
		}
	}
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0, m = 0;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        value[i] = INF;
		holf[i] = INF;
        tmp_fr[i] = std::make_pair(-1, -1);
	}
    for (int i = 0; i < m; ++i) {
        int x1, x2, x3;
        std::cin >> x1 >> x2 >> x3;
		x1 -= 1;
		x2 -= 1;
        graph[x1].emplace_back(x3, x2);
        graph[x2].emplace_back(x3, x1);
	}
    for (int i = 0; i < n; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}
    value[0] = 0;
    std::queue<int> que;
    que.push(0);
	while (!que.empty()) {
        int index = que.front();
        que.pop();
        for (int i = 0; i < (int)graph[index].size(); ++i) {
            int to = graph[index][i].second;
			if (value[to] > value[index] + 1) {
                value[to] = value[index] + 1;
                que.push(to);
			}
		}
	}
 
	dfs(n - 1, n);
	holf[0] = 0;
    std::vector<int> vertex;
    vertex.push_back(0);
	if (value[n - 1] == INF) {
		return 0;
	}
    for (int l = 0; l < value[n - 1]; ++l) {
        std::map<int, std::vector<int>> excelent;
        for (int index : vertex) {
            for (int j = 0; j < (int)graph[index].size(); ++j) {
                int color = graph[index][j].first;
                int to = graph[index][j].second;
				if (value[to] == value[index] + 1 && holf[to] > color) {
                    excelent[color].push_back(to);
					holf[to] = color;
                    tmp_fr[to] = std::make_pair(index, color);
				}
			}
		}
		for (auto & it : excelent) {
			bool hehe = false;
            for (int to : it.second) {
                	if(used[to]) {
                        hehe = true;
				}
			}
			if (hehe) {
                vertex = it.second;
				break;
			}
		}
	}
    std::vector<int> for_out;
    int presently = n - 1;
	while (presently != -1) {
        for_out.push_back(tmp_fr[presently].second);
        presently = tmp_fr[presently].first;
	}
    for_out.pop_back();
	reverse(for_out.begin(), for_out.end());
    std::cout << for_out.size() << std::endl;
    for (int i : for_out) {
        std::cout << i << " ";
	}
}