//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;
int dp[50][50];

void input() {
    cin >> str;
}

void solve() {
    int n = str.length() - 1;
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= n; i++)
        for (int j = 0, k = i; k <= n; j++, k++) {
            if (str[j] == str[k]) dp[j][k] = dp[j + 1][k - 1];
            else dp[j][k] = min(dp[j + 1][k], dp[j][k - 1]) + 1;
        }
    printf("%d\n", dp[0][n]);
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