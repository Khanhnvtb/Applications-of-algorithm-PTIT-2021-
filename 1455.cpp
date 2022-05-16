//
// Created by khanh on 10/11/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1005], dp[1005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    printf("%d\n", n - res);
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