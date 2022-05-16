//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, n, a[1005], c[1005], dp[1005][105];

void input() {
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
}

void solve() {
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            if (a[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", dp[n][v]);
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