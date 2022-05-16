//
// Created by Nguyen Van Khanh on 10/24/2021.
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
    dp[2] = min(ins, cop) + dp[1];
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i / 2] + cop, dp[i - 1] + ins);
        else dp[i] = min(dp[i - 1] + ins, min(dp[i / 2 + 1] + cop + del, dp[i / 2] + cop + ins));
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
