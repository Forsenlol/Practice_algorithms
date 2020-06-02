#include<bits/stdc++.h>
 
#include <bits/stdc++.h>
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    std::string str;
    int v = 0;
    std::cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        for (int j = 0; j < n; ++j) {
            v = (int)str[j] - 48;
            graph[i][j] = v;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] |= (graph[i][k] & graph[k][j]);
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graph[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}