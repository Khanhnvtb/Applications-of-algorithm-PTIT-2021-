//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k;
long dp[1005][1005], m = 1e9 + 7;

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    for (int i = 1; i <= 1000; i++) dp[1][i] = i;
    for (int i = 2; i <= 1000; i++)
        for (int j = 2; j <= i; j++)
            dp[j][i] = (dp[j][i - 1] + dp[j - 1][i - 1]) % m;
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        printf("%ld\n", dp[k][n]);
    }
    return 0;
}