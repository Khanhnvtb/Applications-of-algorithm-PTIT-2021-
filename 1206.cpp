//
// Created by khanh on 10/8/2021.
//

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
