//
// Created by Nguyen Van Khanh on 11/14/2021.
//

/*
Cho đồ thị vô hướng G có N đỉnh, M cạnh. 

Hãy liệt kê các đỉnh không cùng thành phần liên thông với đỉnh 1.

Input

Dòng đầu ghi 2 số N và M (0 < N < 300; 1 <= M <= N*(N-1)/2)).

Tiếp theo là M dòng, mỗi dòng ghi một cạnh của đồ thị. Các cạnh được liệt kê với thứ tự bất kỳ.

Output

Ghi ra các đỉnh không liên thông với đỉnh 1 theo thứ tự tăng dần, mỗi dòng ghi một đỉnh. Nếu không có đỉnh nào thì ghi ra số 0.

Ví dụ

Input

6 4

1 3

2 3

1 2

4 5

Output

4

5

6
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[305];
vector<int> a[305];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                vs[tmp] = 1;
                q.push(tmp);
            }
        }
    }
}

void solve() {
    int state = 0;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    bfs(1);
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) {
            printf("%d\n", i);
            state = 1;
        }
    }
    if (!state) printf("0\n");
}

int main() {
    input();
    solve();
    return 0;
}
