//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, m, a[505][505], d[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = INT_MAX;
    d[0][0] = a[0][0];
    queue <pair <int, int> > q;
    q.push ({0, 0});
    while (!q.empty ()) {
        int i = q.front ().first;
        int j = q.front ().second;
        q.pop ();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (check (x, y) && d[i][j] + a[x][y] < d[x][y]) {
                d[x][y] = d[i][j] + a[x][y];
                q.push ({x, y});
            }
        }
    }
    cout << d[n - 1][m - 1] << endl;
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