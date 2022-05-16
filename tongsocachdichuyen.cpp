//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, m = 1e9 + 7;
long dp[100005];

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++) {
            if (j <= i) dp[i] += dp[i - j];
            dp[i] %= m;
        }
    }
    printf("%ld\n", dp[n]);
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