#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
void outQueue(int person, int think){
    if (think - person < 0){
        cout << 0 << " ";
    }
    else {
        cout << think - person << " ";
    }
}
 
void stop_run(const queue<pair<int, int>>& q){
    for (size_t i = 0; i < q.size(); ++i){
        cout << "-1" << " ";
    }
}
 
int main() {
    queue<pair<int, int>> my_queue_persons;
    vector<pair<int, int>> my_queue_thinks;
    int queue_size = 0;
    cin >> queue_size;
    int in[3] = {0, 0, 0};
    for (int i = 0; i < queue_size; ++i) {
        cin >> in[0] >> in[1] >> in[2];
        if (in[0] == 1) {
            pair<int, int> v = make_pair(in[1], in[2]);
            my_queue_thinks.push_back(v);
 
        }
        else if (in[0] == 2) {
            pair <int, int> v = make_pair(in[1], in[2]);
            my_queue_persons.push(v);
        }
    }
 
    size_t len_size = my_queue_persons.size();
 
    if (my_queue_thinks.empty()){
        stop_run(my_queue_persons);
        return 0;
    }
 
    for (size_t i = 0; i < len_size; ++i) {
        if (my_queue_persons.front().second == my_queue_thinks.front().second) {
            outQueue(my_queue_persons.front().first, my_queue_thinks.front().first);
            my_queue_persons.pop();
            my_queue_thinks.erase(my_queue_thinks.begin());
        }
        else {
            for (size_t j = 0; j < my_queue_thinks.size(); ++j) {
                if (my_queue_persons.front().second == my_queue_thinks[j].second) {
                    for (size_t k = 0; k < j; ++k){
                        my_queue_thinks[k].first = my_queue_thinks[j].first;
                    }
                    outQueue(my_queue_persons.front().first, my_queue_thinks[j].first);
                    my_queue_persons.pop();
                    my_queue_thinks.erase(my_queue_thinks.begin() + j);
                    break;
                }
                else if (j == my_queue_thinks.size() - 1){
                    cout << -1 << " ";
                }
            }
        }
    }
 
    if (my_queue_thinks.empty()){
        stop_run(my_queue_persons);
        return 0;
    }
    return 0;
}