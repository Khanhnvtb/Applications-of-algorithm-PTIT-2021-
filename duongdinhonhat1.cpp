//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include<bits/stdc++.h>

using namespace std;

int n, m, a[1005][1005], dp[1005][1005];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
}

void solve() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = INT_MAX;
            else {
                if (i == 1 && j == 1) dp[i][j] = a[i][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + a[i][j];
                }
            }
        }
    printf("%d\n", dp[n][m]);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}