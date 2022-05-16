//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[1005];
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

bool isTwoSideGraph(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (vs[tmp] == 0) {
                vs[tmp] = -vs[u];
                q.push(tmp);
            } else {
                if (vs[tmp] == vs[u]) return false;
            }
        }
    }
    return true;
}

void solve() {
    int state = 1;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++) {
        if (vs[i] == 0)
            if (!isTwoSideGraph(i)) {
                state = 0;
                break;
            }
    }
    if (state) printf("YES\n");
    else printf("NO\n");
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