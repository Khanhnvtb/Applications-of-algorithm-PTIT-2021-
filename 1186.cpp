//
// Created by khanh on 10/8/2021.
//
#include <bits/stdc++.h>

using namespace std;

int v, e, start, dist, vs[1005], previous[1005];
vector<int> adj[1005];

void input() {
    scanf("%d %d %d %d", &v, &e, &start, &dist);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (!vs[tmp]) {
                previous[tmp] = u;
                vs[tmp] = 1;
                if (tmp == dist) return;
                q.push(tmp);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= v; i++) {
        previous[i] = 0;
        vs[i] = 0;
    }
    bfs(start);
    if (previous[dist]) {
        stack<int> s;
        while (dist != 0) {
            s.push(dist);
            dist = previous[dist];
        }
        while (!s.empty()) {
            printf("%d ", s.top());
            s.pop();
        }
    } else
        printf("-1");
    printf("\n");
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
