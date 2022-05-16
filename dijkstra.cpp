//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, s;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<pair<int, int> > a[1005];
long long d[1005];

void input() {
    scanf("%d %d %d", &v, &e, &s);
    int i, j, k;
    while (e--) {
        scanf("%d %d %d", &i, &j, &k);
        a[i].push_back({k, j});
        a[j].push_back({k, i});
    }
}

void solve() {
    for (int i = 1; i <= v; i++) d[i] = INT_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        long long k = pq.top().first;
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < a[s].size(); i++) {
            int u = a[s][i].second;
            int dist = a[s][i].first;
            if (d[s] + dist < d[u]) {
                d[u] = d[s] + dist;
                pq.push({d[u], u});
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        printf("%lld ", d[i]);
        a[i].clear();
    }
    printf("\n");

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