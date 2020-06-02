#include<bits/stdc++.h>
#include<deque>
 
#define max_size 10000
#define bit_number 1000
 
int used[max_size];
int prev[max_size];
 
int shift_left(int number) {
    return (number % bit_number) * 10 + number / bit_number;
}
 
int shift_right(int number) {
    return (number % 10) * bit_number + number / 10;
}
 
int inc_first(int number) {
    return (number < 9000) ? (number + 1000) : number;
}
 
int decr_last(int number) {
    return (number % 10 != 1) ? (number - 1) : number;
}
 
void find_result(int start, int finish, std::deque<int>& deq) {
    deq.push_front(start); 
    used[start] = 1;
    while(!deq.empty()) {
        int u = deq.front(); 
        deq.pop_front();
        if (u == finish) {
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int v = 0;
            switch(i) {
                case 0:
                    v = inc_first(u);
                    break;
                case 1:
                    v = decr_last(u);
                    break;
                case 2:
                    v = shift_left(u);
                    break;
                case 3:
                    v = shift_right(u);
                    break;
            }
            if (!used[v]) {
                used[v] = 1;
                prev[v] = u;
                deq.push_back(v);
            }
        }
    }
}
 
void out_result(int number) {
    if (number == -1) {
        return;
    }
    out_result(prev[number]);
    std::cout << number << std::endl;
}
 
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int in = 0;
    int out = 0;
    std::cin >> in >> out;
    std::deque<int> deq;
    for(int i = 0; i < max_size; ++i) {
        prev[i] = -1;
    }
    find_result(in, out, deq);
    out_result(out);
    return 0;
}