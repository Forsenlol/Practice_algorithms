#include <bits/stdc++.h>
 
int64_t a[1000], b[1000];
 
bool bin_search(int64_t num, int64_t n, int64_t c, int64_t p, int64_t t)
{
    int64_t i, j;
    for(i = 1; i <= n; i++) {
        if (b[i] >= num) {
            break;
        }
    }
    int64_t level = i;
    int64_t peoples = num - b[i - 1];
    int64_t all = 0;
    for(i = level; i >= 1;)
    {
        if (peoples % c == 0) {
            all += (peoples / c * 2 * p * i);
        }
        else {
            all += ((peoples / c + 1) * 2 * p * i);
        }
        if (all > t) {
            return false;
        }
        int64_t tmp_t = peoples % c;
        if (tmp_t == 0) {
            i = i - 1;
            peoples = a[i];
            continue;
        }
        for (j = i - 1; j >= 1; --j) {
            if (a[j] + tmp_t >= c) {
                break;
            }
            else {
                tmp_t += a[j];
            }
        }
        peoples = a[j] - (c - tmp_t);
        i = j;
    }
    return all <= t;
}
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int64_t n = 0;
    int64_t c = 0;
    int64_t p = 0;
    int64_t t = 0;
    std::cin >> n >> c >> p >> t;
    b[0] = 0;
    a[0] = 0;
    for (int64_t i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for(int64_t i = 1; i <= n ; ++i) {
        b[i] = b[i - 1] + a[i];
    }
    int64_t left = 0;
    int64_t right = b[n];
    int64_t answer = 0;
    while(left <= right)
    {
        int64_t middle = (left + right) / 2;
        if (bin_search(middle, n, c, p, t))
        {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    std::cout << answer;
 
    return 0;
}