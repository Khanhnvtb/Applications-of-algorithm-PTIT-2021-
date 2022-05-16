//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>
using namespace std;

long long v, e, s, dist[100005], path[100005];
vector <pair<long long, long long > > edge[100005];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
vector <int> previous[100005];

void init() {
    cin >> v >> e;
    long long i, j, k;
    while (e--) {
        cin >> i >> j >> k;
        edge[i].push_back ({k, j});
        edge[j].push_back ({k, i});
    }
}

void solve() {
    for (long long i = 2; i <= v; i++) {
        dist[i] = LONG_LONG_MAX;
        path[i] = 0;
        sort (edge[i].begin (), edge[i].end ());
    }
    dist[1] = 0;
    path[1] = 1;
    q.push ({0, 1});
    while (!q.empty ()) {
        s = q.top ().second;
        q.pop ();
        for (long long i = 0; i < edge[s].size (); i++) {
            long long x = edge[s][i].second;
            long long y = edge[s][i].first;
            if (dist[x] > dist[s] + y) {
                previous[x].clear ();
                previous[x].push_back (s);
                dist[x] = dist[s] + y;
                path[x] = path[s];
                q.push ({dist[x], x});
            } else if (dist[x] == dist[s] + y) {
                int check = 1;
                for (int j = 0; j < previous[x].size (); j++) {
                    if (previous[x][j] == s) {
                        check = 0;
                        break;
                    }
                }
                if (check) path[x] += path[s];
            }
        }
    }
}

void print() {
    cout << dist[v] << " " << path[v];
}

int main() {
    init ();
    solve ();
    print ();
    return 0;
}