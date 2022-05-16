//
// Created by khanh on 10/8/2021.
//
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

