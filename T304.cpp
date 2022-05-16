//
// Created by Nguyen Van Khanh on 10/26/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, res = INT_MIN, a[1005], dp[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}