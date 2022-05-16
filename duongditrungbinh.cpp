//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[105], used[105];
vector<int> edge[105];
vector<int> a;

void init() {
    cin >> v >> e;
    int i, j;
    while (e--) {
        cin >> i >> j;
        edge[i].push_back(j);
    }
}

float minPath() {
    float cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i != j) {
                memset(used, 0, sizeof(used));
                queue<int> q;
                q.push(a[i]);
                used[a[i]] = 1;
                while (!q.empty()) {
                    int u = q.front();
                    for (int k = 0; k < edge[u].size(); k++) {
                        int tmp = edge[u][k];
                        if (!used[tmp]) {
                            used[tmp] = used[u] + 1;
                            q.push(tmp);
                        }
                    }
                    if (used[a[j]] != 0) {
                        cnt += used[a[j]] - 1;
                        break;
                    }
                    q.pop();
                }
            }
        }
    }
    return cnt / (a.size() * (a.size() - 1));
}

void solve() {
    float res = 32767;
    for (int i = 1; i <= v; i++) {
        vs[i] = 0;
    }
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) {
            vs[i] = 1;
            a.clear();
            a.push_back(i);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < edge[u].size(); j++) {
                    int tmp = edge[u][j];
                    if (!vs[tmp]) {
                        vs[tmp] = 1;
                        q.push(tmp);
                        a.push_back(tmp);
                    }
                }
            }
            if (a.size() > 1) {
                float f = minPath();
                if (f < res) res = f;
            }
        }
    }
    cout << setprecision(2) << fixed << res << endl;
    for (int i = 1; i <= v; i++) edge[i].clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}