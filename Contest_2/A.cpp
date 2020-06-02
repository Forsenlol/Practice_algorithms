#include<bits/stdc++.h>
#include <iomanip>
 
#define MN 1<<22
 
int dp[MN], go[MN];
void find(int a, int en, int n)
{
    for (int j = 0; j < n; ++j) {
        if ((dp[a] & (1<<j)) && (go[1<<j] & (1<<en)))
        {
            find(a ^ (1<<j), j, n);
            break;
        }
    }
    std::cout << en + 1 << " ";
}
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to;
        std::cin >> from >> to;
        from -= 1;
        to -= 1;
        if (from == to) {
            continue;
        }
        go[1<<from] |= (1<<to);
    }
    for (int i = 0; i < n; ++i) {
        dp[1<<i] |= (1<<i);
    }
    int answer = 0;
    int value = 0;
    for (int i = 0; i < (1<<n); ++i) {
        int mask = dp[i];
        int one = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) {
                one++;
            }
            else {
                go[i | (1<<j)] |= go[i];
                if(go[mask] & (1<<j)) {
                    dp[i | (1<<j)] |= (1<<j);
                }
            }
        }
        if (dp[i]) {
            if (value < one) {
                value = one;
                answer = i;
            }
        }
    }
    std::cout << value - 1 << std::endl;
    for (int j = 0; j < n; ++j) {
        if (dp[answer] & (1<<j)) {
            find(answer ^ (1<<j), j, n);
            break;
        }
    }
}