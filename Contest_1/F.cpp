#include <bits/stdc++.h>
#include <algorithm>
 
#define LIM 100001
 
// (Функция minSubArr) https://e-maxx.ru/algo/stacks_for_minima#4
void minSubArr(int n, int L, int arr[], int tmp, int& tmp_val) {
 
    int LR[LIM];
    int RL[LIM];
    int* min_val = &tmp_val;
    for(int i = 0; i < n; i++){
        if(i % L == 1)
            LR[i] = arr[i];
        else
            LR[i] = std::min(LR[i - 1], arr[i]);
    }
 
    for(int i = n-1; i >= 0; i--){
        if(i == n-1)
            RL[i] = arr[i];
        else if(i % L == 0)
            RL[i] = arr[i];
        else
            RL[i] = std::min(RL[i+1], arr[i]);
    }
 
    for(int i = 0; i < tmp; i++)
        min_val[i] = std::min(RL[i], LR[i + L - 1]);
}
 
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int L = 0;
    std::cin >> n >> L;
    int matrix[n][n];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            std::cin >> matrix[i][j];
        }
    }
    if (n == L){
        int var_min = INT_MAX;
        for (int j = 0; j < n; ++j){
            for (int i = 0; i < n; ++i){
                var_min = std::min(var_min, matrix[j][i]);
            }
        }
        std::cout << var_min;
        return 0;
    }
 
    if (L == 1){
        for (int j = 0; j < n; ++j){
            for (int i = 0; i < n; ++i){
                std::cout << matrix[j][i] << " ";
            }
            std::cout << std::endl;
        }
        return 0;
    }
 
    int tmp = 1 + (n - L);
    int tmp_column_matrix[n][tmp];
    for (int j = 0; j < n; ++j){
        minSubArr(n, L, matrix[j], tmp, *tmp_column_matrix[j]);
    }
    int tmp_tmp[n];
    int tmp_line_matrix[tmp][tmp];
    for (int j = 0; j < tmp; ++j){
        for (int i = 0; i < n; ++i){
            tmp_tmp[i] = tmp_column_matrix[i][j];
        }
        minSubArr(n, L, tmp_tmp, tmp, *tmp_line_matrix[j]);
    }
 
    for (int j = 0; j < tmp; ++j){
        for (int i = 0; i < tmp; ++i){
            std::cout << tmp_line_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}