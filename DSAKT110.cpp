//
// Created by Nguyen Van Khanh on 10/29/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1000005], dp[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = INT_MIN;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + a[i];
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
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