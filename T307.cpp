//
// Created by Nguyen Van Khanh on 10/26/2021.
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
        for (int j = i - 3; j < i; j++) {
            if (j >= 0) dp[i] += dp[j];
        }
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