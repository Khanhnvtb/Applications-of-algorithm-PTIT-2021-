//
// Created by khanh on 10/11/2021.
//

#include <bits/stdc++.h>

using namespace std;

int dp[105][105][105];
int lena, lenb, lenc;
string a, b, c;

void input() {
    scanf("%d %d %d", &lena, &lenb, &lenc);
    cin >> a >> b >> c;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    dp[0][0][0] = 0;
    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
            for (int k = 1; k <= lenc; k++)
                if (a[i] == b[j] && b[j] == c[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
    printf("%d\n", dp[lena][lenb][lenc]);
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

