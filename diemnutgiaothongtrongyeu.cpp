#include <bits/stdc++.h>

using namespace std;
int v, e, res, vs[1005];
vector<int> a[1005];
vector<int> ans;

void reset() {
    for (int i = 1; i <= v; i++) {
        vs[i] = 0;
    }
    vs[res] = 1;
}

void dfs(int u) {
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (!vs[tmp]) {
            dfs(tmp);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        while (e--) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
        for (res = 1; res <= v; res++) {
            reset();
            int cnt = 1;
            if (res == 1) {
                dfs(2);
            } else {
                dfs(1);
            }
            for (int i = 1; i <= v; i++) {
                if (!vs[i]) {
                    ans.push_back(res);
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for (int i: ans) cout << i << " ";
        for (int i = 1; i <= v; i++) {
            a[i].clear();
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}