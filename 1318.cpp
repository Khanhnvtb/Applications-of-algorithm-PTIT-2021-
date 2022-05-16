//
// Created by khanh on 10/10/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, state, a[10][10], vs[10][10];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            vs[i][j] = 0;
        }

}

void Try(int i, int j, string s) {
    if (i == n && j == n) {
        cout << s << " ";
        state = 1;
        return;
    }
    vs[i][j] = 1;
    int x = i + 1, y = j + 1, z = i - 1, t = j - 1;
    if (i < n && a[x][j] == 1 && vs[x][j] == 0) Try(x, j, s + 'D');
    if (j > 1 && a[i][t] == 1 && vs[i][t] == 0) Try(i, t, s + 'L');
    if (j < n && a[i][y] == 1 && vs[i][y] == 0) Try(i, y, s + 'R');
    if (i > 1 && a[z][j] == 1 && vs[z][j] == 0) Try(z, j, s + 'U');
    vs[i][j] = 0;
}

void solve() {
    state = 0;
    if (a[1][1] != 1 || a[n][n] != 1) printf("-1");
    else {
        Try(1, 1, "");
        if (state == 0) printf("-1");
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