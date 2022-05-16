//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[55];

void input() {
    scanf("%d", &n);
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        if (i > 0) dp[i] += dp[i - 1];
        if (i > 1) dp[i] += dp[i - 2];
        if (i > 2) dp[i] += dp[i - 3];
    }
    printf("%lld\n", dp[n]);
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