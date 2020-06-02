#include <iostream>
 
int main() {
    //std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int k = 0;
    int m = 0;
    std::cin >> n >> k >> m;
    if (m == 0) {
        for (int j = 0; j < k; ++j) {
            std::cout << j << " ";
        }
        return 0;
    }
    int tmp[m][3];
    for (int i = 0; i < m; ++i) {
        std::cin >> tmp[i][0] >> tmp[i][1] >> tmp[i][2];
        tmp[i][1] -= 1;
    }
    int fence[n];
    for (int i = 0; i < n; ++i) {
        fence[i] = 0;
    }
    for (int j = 0; j < m; ++j) {
        for (int i = tmp[j][1]; i < tmp[j][2]; ++i) {
            fence[i] = tmp[j][0];
        }
    }
    int res[k+1];
    for (int i = 0; i <= k; ++i) {
        res[i] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (fence[j] >= 0 && fence[j] <= k) {
            ++res[fence[j]];
        }
    }
    for (int i = 1; i <= k; ++i) {
        std::cout << res[i] << " ";
    }
    return 0;
}