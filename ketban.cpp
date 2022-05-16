//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[100005];
vector<int> a[100005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
}

int bfs(int u) {
    int cnt = 1;
    vs[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                q.push(tmp);
                cnt++;
                vs[tmp] = 1;
            }
        }
    }
    return cnt;
}

void solve() {
    int res = INT_MIN;
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) res = max(res, bfs(i));
    }
    printf("%d\n", res);
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