#include <bits/stdc++.h>
#define MAX 70001
 
struct city{
  int people, num;
  explicit city(int people = 0, int num = 0) {
      this->people = people;
      this->num = num;
  }
} abc[MAX];
 
int equalityFunction(city, city);
int inquiries(int, int, int, int);
 
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> abc[i].people;
        abc[i].num = i + 1;
    }
    std::sort(abc, abc + n, equalityFunction);
    int q = 0;
    std::cin >> q;
    int in_q[3];
    while(q--){
        std::cin >> in_q[0] >> in_q[1] >> in_q[2];
        std::cout << inquiries(in_q[0], in_q[1], in_q[2], n);
    }
    return 0;
}
 
int equalityFunction(city first, city second){
    if(first.people == second.people){
        return first.num < second.num;
    }
    return first.people < second.people;
}
 
int inquiries(int l, int r, int x, int n){
    int Left = std::lower_bound(abc, abc + n, city(x, l), equalityFunction) - abc;
    int Right = std::upper_bound(abc, abc + n, city(x, r), equalityFunction) - abc;
    return Left < Right;
}