//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, ins, del, cop, dp[105];

void input() {
    scanf("%d", &n);
    scanf("%d %d %d", &ins, &del, &cop);
}

void solve() {
    dp[1] = ins;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i - 1] + ins, dp[i / 2] + cop);
        else dp[i] = min(dp[i - 1] + ins, dp[(i + 1) / 2] + cop + del);
    }
    printf("%d\n", dp[n]);
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