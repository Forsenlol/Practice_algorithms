#include <iostream>
#include <deque>
#include <cmath>
 
int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::deque<int> myDeque(n);
    int n_minus = n - 1;
    int a_k = std::pow(2, 30);
    for(int i = 0; i < n; ++i) {
        std::cin >> myDeque[i];
    }
    for (int j = 0; j < k; ++j) {
        int x = myDeque[0];
        int y = myDeque[n_minus];
        if (myDeque[0] < myDeque[n_minus]) {
            myDeque.pop_front();
            myDeque.push_back((x + y) % a_k);
        }
        else if (myDeque[0] == myDeque[n_minus]) {
            myDeque.pop_back();
            myDeque.push_front(0);
        }
        else {
            myDeque.pop_back();
            myDeque.push_front(a_k + (y - x));
        }
    }
    for (int i = 0; i < n; ++i){
        std::cout << myDeque[i] << " ";
    }
    return 0;
}