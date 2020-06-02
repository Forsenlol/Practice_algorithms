#include <bits/stdc++.h>
#include <cmath>
#include <vector>
 
bool length(std::vector<int>& cords, int, int);
int searhing(std::vector<int>& cords, int);
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<int> cords;
    for(size_t i = 0; i < n; ++i) {
        int cord;
        std::cin >> cord;
        cords.push_back(cord);
    }
    std::cout << searhing(cords, k);
 
return 0;
}
 
bool test_length(std::vector<int>& cords, int middle, int k) {
    int count = 0;
    for (auto cord: cords) {
        if (count > k) {
            break;
        }
    count += cord / middle;
    }
    if (count >= k){
        return true;
    }
    return false;
}
 
int searhing(std::vector<int>& cords, int k) {
    int left = 1;
    int right = *std::max_element(cords.begin(), cords.end()) + 1;
    int result = 0;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (test_length(cords, middle , k)) {
            result = middle;
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }
    return result;
}