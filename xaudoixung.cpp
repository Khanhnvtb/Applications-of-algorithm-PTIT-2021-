//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;
int dp[50][50];

void input() {
    cin >> s;
}

void solve() {
    string revS = s;
    reverse(revS.begin(), revS.end());
    memset(dp, 0, sizeof(dp));
    int n = s.length();
    for (int i = 0; i < n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == revS[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    printf("%d\n", n - dp[n][n]);
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