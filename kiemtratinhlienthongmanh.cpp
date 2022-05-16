//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[1005];
vector<int> a[1005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
    }
}

int bfs(int u) {
    int cnt = 1;
    vs[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (!vs[tmp]) {
                q.push(tmp);
                cnt++;
                vs[tmp] = 1;
            }
        }
    }
    return cnt;
}

string isStrongConnection() {
    for (int i = 1; i <= v; i++) {
        memset(vs, 0, sizeof(vs));
        if (bfs(i) != v) return "NO";
    }
    return "YES";
}

void solve() {
    cout << isStrongConnection() << endl;
    for (int i = 1; i <= v; i++) a[i].clear();
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