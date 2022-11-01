//
// Created by khanh on 10/8/2021.
//

/*
BFS TRÊN ĐỒ THỊ VÔ HƯỚNG

Bài làm tốt nhất
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
     Ví dụ:

Input:

1

6 9 1

1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

Output:

1 2 3 5 4 

*/

#include <bits/stdc++.h>

using namespace std;

int v, e, first, vs[1005];
vector<int> adj[1005];

void input() {
    scanf("%d %d %d", &v, &e, &first);
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
        q.pop();
        printf("%d ", u);
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
    for (int i = 1; i <= v; i++) vs[i] = 0;
    bfs(first);
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
