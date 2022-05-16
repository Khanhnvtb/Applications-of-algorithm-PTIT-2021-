//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k;
long long dp[100005], m = 1e9 + 7;

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= k; j++)
            if (i >= j) dp[i] += dp[i - j] % m;
    }
    printf("%lld\n", dp[n] % m);
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