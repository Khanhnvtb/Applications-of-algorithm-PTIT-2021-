//
// Created by khanh on 10/8/2021.
//

/*
KIỂM TRA CHU TRÌNH

Bài làm tốt nhất
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Sử dụng thuật toán DFS hoặc BFS, hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.
Ví dụ:

Input:

1

6  9

1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

Output:

YES
*/

#include <bits/stdc++.h>
using namespace std;

int v, e, state, previos[1005];
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
    previos[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (previos[tmp] == 0) {
                previos[tmp] = u;
                q.push(tmp);
            } else {
                if (previos[u] != tmp) {
                    state = 1;
                    return;
                }
            }
        }
    }
}

void solve() {
    state = 0;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) previos[j] = 0;
        bfs(i);
        if (state) break;
    }
    if (state) printf("YES\n");
    else printf("NO\n");
    for (int i = 1; i <= v; i++)
        adj[i].clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}

