#include <iostream>
#include <cmath>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
    int64_t max_left = - pow(10,9);
    int64_t min_top = pow(10,9);
    int64_t min_right = pow(10,9);
    int64_t max_bott = - pow(10,9);
    
    int64_t right = 0;
    int64_t top = 0;
    int64_t left = 0;
    int64_t bott = 0;
    int N = 0;
    
    cin >> N;
    
    for (int i = 0; i < N; ++i){
        cin >> left >> bott >> right >> top;
        max_left = max(max_left, left);
        min_top = min(min_top, top);
        min_right = min(min_right, right);
        max_bott = max(max_bott, bott);
    }
    
    int64_t res = 0;
    
    if (max_left <= min_right && max_bott <= min_top){
        res = (min_right - max_left) * (min_top - max_bott);
    }
    
    cout << res;
    
    return 0;
}