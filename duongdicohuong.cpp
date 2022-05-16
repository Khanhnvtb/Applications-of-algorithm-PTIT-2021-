//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, f, l, pre[1005];
vector<int> a[1005];

void input() {
    scanf("%d %d %d %d", &v, &e, &f, &l);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    pre[u] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (pre[tmp] == 0) {
                pre[tmp] = u;
                q.push(tmp);
                if (tmp == l) return;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= v; i++) pre[i] = 0;
    bfs(f);
    vector<int> res;
    while (l != 0) {
        res.push_back(l);
        l = pre[l];
    }
    if (res.size() < 2) printf("-1\n");
    else {
        for (int i = res.size() - 1; i > 0; i--)
            printf("%d -> ", res[i]);
        printf("%d\n", res[0]);
    }
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
