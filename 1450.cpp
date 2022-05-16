#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
string a, b;

void input() {
    cin >> a >> b;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    int lena = a.length() - 1;
    int lenb = b.length() - 1;
    for (int i = 0; i <= lena; i++) dp[i][0] = 0;
    for (int i = 0; i <= lenb; i++) dp[0][i] = 0;
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[lena][lenb]);
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