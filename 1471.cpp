//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, a[1005][1005], dp[1005][1005];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
}

void solve() {
    for (int i = 0; i <= n; i++) dp[i][0] = INT_MAX;
    for (int j = 0; j <= m; j++) dp[0][j] = INT_MAX;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + a[i][j];
    printf("%d\n", dp[n][m]);
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