#include<bits/stdc++.h>
 
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    std::cin >> n;
    int adjacency_matrix[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> adjacency_matrix[i][j];
        }
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(adjacency_matrix[i][j] > adjacency_matrix[i][k] + adjacency_matrix[k][j]) {
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) {
            std::cout << adjacency_matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}