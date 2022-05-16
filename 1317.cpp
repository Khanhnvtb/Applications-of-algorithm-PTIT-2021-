//
// Created by khanh on 10/10/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, state, a[15][15];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void Try(int i, int j, string s) {
    if (i == n && j == n) {
        cout << s << " ";
        state = 1;
        return;
    }
    int x = i + 1, y = j + 1;
    if (i < n && a[x][j] == 1) Try(x, j, s + 'D');
    if (j < n && a[i][y] == 1) Try(i, y, s + 'R');
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