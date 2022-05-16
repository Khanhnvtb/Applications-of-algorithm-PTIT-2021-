//
// Created by khanh on 10/14/2021.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, a[505][505], d[505][505];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
}

void solve() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 0) {
                if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j]) {
                    d[i][j] = min (d[i - 1][j - 1], d[i - 1][j]);
                    d[i][j] = min (d[i][j], d[i][j - 1]) + 1;
                }
                res = max (res, d[i][j]);
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
