//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;
long k, m = 1e9 + 7, a[1005], dp[1005];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % m;
    printf("%ld\n", dp[k]);
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