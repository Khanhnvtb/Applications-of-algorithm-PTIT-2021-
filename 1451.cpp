//
// Created by khanh on 10/11/2021.
//

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005][1005];
string a;

void input() {
    scanf("%d", &n);
    cin >> a >> b >> c;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    for (int i = 0; i <a.length(); i++) dp[i][0][0] = 0;
    for (int i = 0; i <b.length(); i++) dp[0][i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i] == a[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
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