#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include<bits/stdc++.h>
 
int const desk_size = 8;
int const N = desk_size * desk_size;
bool visited[N];
int previous[N];
int const movesx[8] = {-1, 1, -2, -2, -1, 1, 2, 2};
int const movesy[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int const minV = 0;
int const maxV = 7;
 
std::vector<int> connected(const int &v)
{
    std::vector<int> result;
    int v_x = v % desk_size;
    int v_y = v / desk_size;
    for (int i = 0; i < desk_size; ++i) {
        int tmp_x = v_x + movesx[i];
        int tmp_y = v_y + movesy[i];
        if (tmp_x >= minV && tmp_x <= maxV
            && tmp_y >= minV && tmp_y <= maxV) {
            int curV = desk_size * tmp_y + tmp_x;
            result.push_back(curV);
        }
    }
    return result;
}
 
void bfs(const int &v)
{
    std::queue<int> vertices;
    vertices.push(v);
    visited[v] = true;
 
    while (!vertices.empty()) {
        int tmp = vertices.front();
        vertices.pop();
        std::vector<int> neibours = connected(tmp);
        int size = neibours.size();
        for (int i = 0; i < size; ++i) {
            int j = neibours.at(i);
            if (!visited[j]) {
                vertices.push(j);
                visited[j] = true;
                previous[j] = tmp;
            }
        }
    }
}
 
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    char start[3];
    char end[3];
    scanf("%s%s", start, end);
    int y1 = start[0] - 'a';
    int x1 = start[1] - '1';
 
    int y2 = end[0] - 'a';
    int x2 = end[1] - '1';
 
 
    int start_pos = desk_size * y1 + x1;
    int end_pos = desk_size * y2 + x2;
 
    bfs(start_pos);
    std::stack<int> path;
    int tmp = end_pos;
    while (tmp != start_pos) {
        path.push(tmp);
        tmp = previous[tmp];
    }
    path.push(start_pos);
 
    while (!path.empty()) {
        char c = 'a' + path.top() / desk_size;
        int pos = path.top() % desk_size + 1;
        printf("%c%d\n", c, pos);
        path.pop();
    }
    return 0;
}