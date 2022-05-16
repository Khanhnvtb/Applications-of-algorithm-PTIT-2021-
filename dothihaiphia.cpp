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

void dfs(int u) {
    if (!check) return;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (vs[tmp] == 0) {
            vs[tmp] = -vs[u];
            dfs(tmp);
        } else if (vs[tmp] == vs[u]) {
            check = 0;
            return;
        }
    }
}

string isTwoSide() {
    check = 1;
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) {
            vs[i] = 1;
            dfs(i);
        }
        if (check == 0) return "NO";
    }
    return "YES";
}

void solve() {
    memset(vs, 0, sizeof(vs));
    cout << isTwoSide() << endl;
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