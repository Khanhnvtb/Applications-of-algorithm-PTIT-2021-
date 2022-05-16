//
// Created by Nguyen Van Khanh on 10/26/2021.
//

#include <bits/stdc++.h>

using namespace std;

string a;
int n, dp[1005][1005];

void input() {
    scanf("%d", &n);
    cin >> a;
}

void solve() {
    a = ' ' + a;
    n = a.length() - 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == a[j] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[n][n]);
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