//
// Created by khanh on 10/8/2021.
//

#include<bits/stdc++.h>

using namespace std;

int v, e, first, vs[1005];
vector<int> adj[1005];

void input() {
    cin >> v >> e >> first;
    int i, j;
    while (e--) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void dfs(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int tmp = adj[u][i];
        if (!vs[tmp]) dfs(tmp);
    }
}

void solve() {
    for (int i = 1; i <= v; i++) vs[i] = 0;
    dfs(first);
    cout << endl;
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