//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[1005];
vector<int> adj[1005];
vector<pair<int, int>> edge;
vector<int>::iterator i1, i2;

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
        edge.push_back({i, j});
    }
}

int bfs() {
    int u, cnt = 1;
    queue<int> q;
    q.push(1);
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
    return cnt;
}

void solve() {
    vs[1] = 1;
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i].first, y = edge[i].second;
        i1 = find(adj[x].begin(), adj[x].end(), y);
        i2 = find(adj[y].begin(), adj[y].end(), x);
        adj[x].erase(i1);
        adj[y].erase(i2);
        for (int j = 2; j <= v; j++) vs[j] = 0;
        if (bfs() != v) printf("%d %d ", x, y);
        adj[x].insert(i1, y);
        adj[y].insert(i2, x);
    }
    printf("\n");
    for (int i = 1; i <= v; i++) adj[i].clear();
    edge.clear();
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