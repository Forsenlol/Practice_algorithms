#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
 
const int64_t N = 1e6 + 100;
 
int64_t value[N], weight[N];
int64_t n, k;
long double tmp[N];
std::vector<std::pair<long double, int64_t>> answers;
 
bool check_price(long double first) {
    for (size_t i = 0; i < n; i++) {
        tmp[i] = value[i] - first * weight[i];
    }
 
    std::sort(tmp, tmp + n);
 
    long double sum = 0;
    for (size_t i = n - k; i < n; i++) {
        sum += tmp[i];
    }
 
    return (sum >= 0);
}
 
int main() {
    scanf("%d%d", &n, &k);
    int64_t sum_res = 0;
 
    for (size_t i = 0; i < n; i++) {
        scanf("%d%d", &value[i], &weight[i]);
        sum_res += value[i];
    }
 
    long double left = 0;
    auto right = (long double)sum_res;
 
    for (int i = 0; i < 50; i++) {
        long double middle = (left + right) / 2;
        if (check_price(middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }
 
    answers.resize(n);
    for (size_t i = 0; i < n; i++) {
        answers[i] = {value[i] - left * weight[i], i};
    }
 
    sort(answers.begin(), answers.end());
    std::vector<int64_t> tmp_answers;
 
    for (int64_t i = n - k; i < n; i++) {
        tmp_answers.push_back(answers[i].second + 1);
    }
 
    sort(tmp_answers.begin(), tmp_answers.end());
 
    for (long long i : tmp_answers) {
        printf("%d ", i);
    }
    return 0;
}