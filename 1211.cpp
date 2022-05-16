//
// Created by khanh on 10/9/2021.
//

#include<bits/stdc++.h>

using namespace std;

int v, e, vs[100005];
long cntEdge;
vector<int> adj[100005];

void input() {
    cin >> v >> e;
    int i, j;
    for (int k = 0; k < e; k++) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
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
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (!vs[tmp]) {
                cnt++;
                vs[tmp] = 1;
                q.push(tmp);
            }
        }
    }
    cntEdge += cnt * (cnt - 1) / 2;
}

void solve() {
    cntEdge = 0;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++)
        if (!vs[i]) bfs(i);
    if (cntEdge != e) printf("NO\n");
    else printf("YES\n");
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