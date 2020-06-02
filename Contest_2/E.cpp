#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
 
void min_coins(std::vector<int32_t> coins, int32_t target, std::vector<int> &result)
{
    int32_t count = 0;
    result.clear();
    std::sort(coins.begin(), coins.end());
 
    for(auto coin = coins.rbegin(); coin != coins.rend() && target > 0; ++coin) {
        if(target >= *coin) {
            count += target / *coin;
            target = target % *coin;
            result.push_back(*coin);
        }
    }
}
 
std::vector<int32_t> get_best_coins(std::vector<int32_t>& coins, int32_t target) {
    std::vector<int32_t> ret;
    std::vector<int32_t> coins_used;
    min_coins(coins, target, coins_used);
    int32_t i = 0;
    while (target > 0) {
        ret.push_back(coins_used[i]);
        target -= coins_used[i];
        if (target < coins_used[i]) {
            i += 1;
        }
    }
    return ret;
}
 
int main() {
    int32_t n;
    int32_t w;
    std::cin >> n >> w;
 
    std::vector<int32_t> v;
    int32_t in;
    for (int i = 0; i < n; i++) {
        std::cin >> in;
        v.push_back(in);
    }
 
    std::vector<int32_t> result = get_best_coins(v, w);
    std::cout << result.size() << std::endl;
    for (int32_t & coin : result) {
        std::cout << coin << " ";
    }
 
    return 0;
}