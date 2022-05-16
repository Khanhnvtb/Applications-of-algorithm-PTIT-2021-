//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, dp[10005];

void input() {
    scanf("%d", &n);
}

void solve() {
    for (int i = 1; i <= 10000; i++) {
        dp[i] = i;
        for (int j = 1; j <= sqrt(i); j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        printf("%d\n", dp[n]);
    }
    return 0;
}