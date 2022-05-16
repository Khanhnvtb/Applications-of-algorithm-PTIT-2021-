//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, res, dp[505];
float a[505], b[505];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%f %f", &a[i], &b[i]);
}

void solve() {
    res = INT_MIN;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && b[i] < b[j]) dp[i] = max(dp[i], dp[j] + 1);
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