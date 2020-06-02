#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
 
struct schoolboys {
    int64_t h{}, l{}, n{};
    bool survived = true;
    bool operator < (schoolboys const& other) {
        return this->h + this->l > other.h + other.l;
    }
};
struct test_for_swap {
    bool operator() (const schoolboys* left,  const schoolboys* right) {
        return left->h < right->h;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int64_t n = 0;
    int64_t H = 0;
    int64_t schoolboys_H = 0;
    std::cin >> n;
    std::vector<schoolboys> sums(n);
    for (int64_t i = 0; i < n; ++i) {
        std::cin >> sums[i].h >> sums[i].l;
        sums[i].n = i + 1;
        schoolboys_H += sums[i].h;
    }
 
    std::cin >> H;
    sort(sums.begin(), sums.end());
    int64_t dont_it = 0;
    std::priority_queue<schoolboys*, std::vector<schoolboys*>, test_for_swap> do_it;
    for (auto v = sums.rbegin(); v != sums.rend(); ++v) {
        do_it.push(&*v);
        schoolboys_H -= v->h;
        while (v->survived && schoolboys_H + v->h + v->l < H) {
            auto schoolboy = do_it.top();
            do_it.pop();
            schoolboy->survived = false;
            schoolboys_H += schoolboy->h;
            ++dont_it;
        }
    }
    std::cout << sums.size() - dont_it << '\n';
    for (auto schoolboy = sums.rbegin(); schoolboy != sums.rend(); ++schoolboy) {
        if (schoolboy->survived) {
            std::cout << schoolboy->n << ' ';
        }
    }
    return 0 ;
}