//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m = 1e9 + 7;
long long dp[10][105];

void input() {
    scanf("%d", &n);
}

void print() {
    printf("%lld\n", dp[0][n]);
}

void solve() {
    for (int i = 0; i < 10; i++) dp[i][0] = 1;
    for (int i = 0; i <= 100; i++) dp[9][i] = 1;
    for (int i = 1; i <= 100; i++)
        for (int j = 8; j >= 0; j--)
            dp[j][i] = (dp[j][i - 1] + dp[j + 1][i]) % m;
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        print();
    }
    return 0;
}