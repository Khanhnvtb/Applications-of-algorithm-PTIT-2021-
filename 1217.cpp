//
// Created by Khanh Nguyen Van on 10/18/2021.
//

/*
DIJKSTRA.

Bài làm tốt nhất
Cho đồ thị có trọng số không âm G= được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.
Ví dụ:

Input:

1

9  12 1

1  2   4

1  8   8

2  3   8

2  8   11

3  4   7

3  6   4

3  9   2

4  5   9

4  6  14

5  6  10

6  7  2

6  9  6

Output:

0 4 12 19 21 11 9 8 14
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, s, d[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[1005];

void input() {
    scanf("%d %d %d", &v, &e, &s);
    int x, y, z;
    while (e--) {
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
}

void solve() {
    for (int i = 1; i <= v; i++) d[i] = INT_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[s].size(); i++) {
            int u = adj[s][i].second;
            int k = adj[s][i].first;
            if (d[u] > d[s] + k) {
                d[u] = d[s] + k;
                pq.push({d[u], u});
            }
        }
    }
    for (int i = 1; i <= v; i++) printf("%d ", d[i]);
    printf("\n");
    for (int i = 1; i <= v; i++) adj[i].clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}
