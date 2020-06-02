#include <bits/stdc++.h>
 
int64_t A[100001] = {};
int64_t B[100001] = {};
int64_t C[100001] = {};
int64_t Num[100001] = {};
 
void my_function(int64_t L, int64_t R) {
    if (L >= R) {
        return;
    }
    int64_t x = C[L];
    int64_t i = L - 1;
    int64_t j = R + 1;
    while (i < j) {
        do {
            i += 1;
        } while ((C[i] > x));
        do {
            j -= 1;
        } while (C[j] < x);
        if (i < j) {
            std::swap(C[i], C[j]);
            std::swap(A[i], A[j]);
            std::swap(B[i], B[j]);
            std::swap(Num[i], Num[j]);
        }
    }
    my_function(L, j);
    my_function(j + 1, R);
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    size_t n = 0;
    std::cin >> n;
    for (size_t i = 1; i <= n; ++i) {
        std::cin >> A[i];
        C[i] = A[i];
        Num[i] = i;
    }
    for (size_t i = 1; i <= n; ++i) {
        std::cin >> B[i];
        C[i] += B[i];
    }
    my_function(1, n);
    int64_t i = 1;
    while ((i <= n-1) and (B[i] > A[i + 1])) {
        i += 1;
    }
    if (i > n-1) {
        for (size_t j = 1; j <= n; ++j) {
            std::cout << Num[j] << " ";
        }
    }
    else {
        std::cout << -1;
    }
    return 0;
}
