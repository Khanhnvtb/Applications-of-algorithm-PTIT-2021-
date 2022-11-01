//
// Created by khanh on 10/8/2021.
//

/*
ĐƯỜNG ĐI HAMILTON

Bài làm tốt nhất
Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần được gọi là đường đi Hamilton. Cho đồ thị vô hướng G = , hãy kiểm tra xem đồ thị có đường đi Hamilton hay không?

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh, số cạnh của đồ thị; phần thứ hai đưa vào các cạnh của đồ thị.
T, V, E thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤15.
Output:

Đưa ra 1 hoặc 0 tương ứng với test có hoặc không có đường đi Hamilton theo từng dòng.
Ví dụ:

Input

2
4 4
1 2 2 3 3 4 2 4
4 3
1 2 2 3 2 4

Output

1

0
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, state, vs[1005];
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

void dfs(int u, int cnt) {
    if (state) return;
    vs[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int tmp = adj[u][i];
        if (!vs[tmp]) {
            if (cnt == v) {
                state = 1;
                return;
            }
            dfs(tmp, cnt + 1);
            vs[tmp] = 0;
        }
    }
}

int isHamilton() {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) vs[j] = 0;
        dfs(i, 2);
        if (state) return 1;
    }
    return 0;
}

void solve() {
    state = 0;
    printf("%d\n", isHamilton());
    for (int i = 1; i <= v; i++) adj[i].clear();
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
