//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, edge, vs[100005];
vector<int> a[100005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    for (int k = 0; k < e; k++) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    int cnt = 1;
    vs[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                vs[tmp] = 1;
                q.push(tmp);
                cnt++;
            }
        }
    }
    edge += cnt * (cnt - 1) / 2;
}

void solve() {
    edge = 0;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) bfs(i);
    }
    if (edge != e) printf("NO\n");
    else printf("YES\n");
    for (int i = 1; i <= v; i++) a[i].clear();
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