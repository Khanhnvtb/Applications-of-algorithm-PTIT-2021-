//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

string n, m;
int len_n, len_m, dp[1005][1005];

void input() {
    cin >> n >> m;
}

void solve() {
    n = " " + n;
    m = " " + m;
    len_n = n.length();
    len_m = m.length();
    for (int i = 1; i < len_n; i++) dp[i][0] = 0;
    for (int i = 1; i < len_m; i++) dp[0][i] = 0;
    for (int i = 1; i < len_n; i++)
        for (int j = 1; j < len_m; j++)
            if (n[i] == m[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    printf("%d\n", dp[len_n - 1][len_m - 1]);
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