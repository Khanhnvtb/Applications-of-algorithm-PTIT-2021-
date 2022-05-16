//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

int c, n, a[105], dp[105][25005];

void input() {
    scanf("%d %d", &c, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i] < j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    printf("%d", dp[n][c]);
}

int main() {
    input();
    solve();
    return 0;
}