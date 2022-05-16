//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, check, vs[1005];
vector<int> a[1005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
}

void dfs(int u, int pre) {
    if (check) return;
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (!vs[tmp]) dfs(tmp, u);
        else if (vs[tmp] && tmp != pre) {
            check = 1;
            return;
        }
    }
}

string isCycle() {
    check = 0;
    for (int i = 1; i <= v; i++) {
        memset(vs, 0, sizeof(vs));
        dfs(i, 0);
        if (check == 1) return "YES";
    }
    return "NO";
}

void solve() {
    cout << isCycle() << endl;
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