#include <bits/stdc++.h>
#include <queue>
 
struct Programers {
    int64_t num;
    int64_t a;
};
 
struct comporator {
    bool operator()(const Programers &left, const Programers &right) {
        return left.a < right.a;
    }
 
};
 
struct asyn_comporator {
    bool operator()(const Programers &left, const Programers &right) {
        return left.a > right.a;
    }
};
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int64_t n;
    int64_t a;
    std::cin >> n >> a;
 
    int64_t vec_a[n];
    int64_t vec_b[n];
 
    std::priority_queue<Programers, std::vector<Programers>, asyn_comporator> good;
    std::priority_queue<Programers, std::vector<Programers>, asyn_comporator> tmp_good;
    std::priority_queue<Programers, std::vector<Programers>, comporator> bad;
    std::priority_queue<Programers, std::vector<Programers>, comporator> tmp_bad;
 
    std::pair<int64_t, int64_t> size_1;
    size_1 = std::make_pair(0, 0);
    std::pair<int64_t, int64_t> size_2;
    size_2 = std::make_pair(0, 0);
 
    for (int64_t i = 1; i <= n; ++i) {
        std::cin >> vec_a[i] >> vec_b[i];
        if (vec_b[i] < 0) {
            bad.push({i, vec_a[i] + vec_b[i]});
            size_1.first += 1;
        }
        else {
            good.push({i, vec_a[i]});
            size_1.second += 1;
        }
    }
 
    int64_t number = 0;
    std::vector<int64_t> result;
    result.reserve(n);
 
    for (int64_t i = 0; i < size_1.second; ++i) {
        Programers programer = good.top();
 
        if (programer.a <= a) {
            a += vec_b[programer.num];
            number += 1;
            result.push_back(programer.num);
        }
 
        good.pop();
    }
 
    for (int64_t i = 0; i < size_1.first; ++i) {
        Programers programer = bad.top();
        bad.pop();
        if (vec_a[programer.num] <= a) {
            a += vec_b[programer.num];
            tmp_good.push({programer.num, vec_b[programer.num]});
            size_2.first += 1;
        }
        else if (!tmp_good.empty() && a - vec_b[tmp_good.top().num] >= vec_a[programer.num] && vec_b[tmp_good.top().num] < vec_b[programer.num]) {
            Programers second_programer = tmp_good.top();
            tmp_good.pop();
            a = a - vec_b[second_programer.num] + vec_b[programer.num];
            tmp_good.push({programer.num, vec_b[programer.num]});
        }
    }
 
    std::cout << number + (int64_t)tmp_good.size() << std::endl;
 
    for (int64_t i = 0; i < size_2.first; ++i) {
        Programers programer = tmp_good.top();
        tmp_good.pop();
 
        tmp_bad.push({programer.num, vec_a[programer.num] + vec_b[programer.num]});
        size_2.second += 1;
    }
 
 
    for (const auto &i : result) {
        std::cout << i << " ";
    }
 
    for (int64_t i = 0; i < size_2.second; ++i) {
        Programers programer = tmp_bad.top();
        tmp_bad.pop();
 
        std::cout << programer.num << " ";
    }
    return 0;
}
}