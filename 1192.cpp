//
// Created by khanh on 10/9/2021.
//

/*
LIỆT KÊ ĐỈNH TRỤ

Bài làm tốt nhất
Cho đồ thị vô hướng liên thông G= được biểu diễn dưới dạng danh sách cạnh. Sử dụng thuật toán DFS hoặc BFS, hãy đưa ra tất cả các đỉnh trụ của đồ thị?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh trụ của mỗi test  theo từng dòng.
Ví dụ:

Input:

1

5 5

1 2 1 3 2 3 2 5 3 4

Output:

2 3
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, cnt, vs[1005];
vector<int> adj[1005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        u = q.front();
        cnt++;
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (!vs[tmp]) {
                vs[tmp] = 1;
                q.push(tmp);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) vs[j] = 0;
        vs[i] = 1;
        cnt = 1;
        if (i == 1) bfs(2);
        else bfs(1);
        if (cnt != v) printf("%d ", i);
    }
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
