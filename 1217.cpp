//
// Created by Khanh Nguyen Van on 10/18/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, s, d[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[1005];

void input() {
    scanf("%d %d %d", &v, &e, &s);
    int x, y, z;
    while (e--) {
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
}

void solve() {
    for (int i = 1; i <= v; i++) d[i] = INT_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[s].size(); i++) {
            int u = adj[s][i].second;
            int k = adj[s][i].first;
            if (d[u] > d[s] + k) {
                d[u] = d[s] + k;
                pq.push({d[u], u});
            }
        }
    }
    for (int i = 1; i <= v; i++) printf("%d ", d[i]);
    printf("\n");
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