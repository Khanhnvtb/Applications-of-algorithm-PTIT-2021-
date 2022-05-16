//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[20005];
vector<int> a[20005];

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
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) vs[j] = 0;
        vs[i] = 1;
        int cnt = 0;
        for (int j = 1; j <= v; j++) {
            if (!vs[j]) {
                cnt++;
                bfs(j);
            }
        }
        printf("%d\n", cnt);
    }
}

int main() {
    input();
    solve();
    return 0;
}
