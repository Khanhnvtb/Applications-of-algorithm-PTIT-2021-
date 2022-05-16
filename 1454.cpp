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
    res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
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