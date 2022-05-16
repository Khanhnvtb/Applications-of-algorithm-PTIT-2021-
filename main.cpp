#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

void input() {
    cin >> s;
}

void solve() {
    string reps = s;
    reverse(reps.begin(), reps.end());
    int cnt = 1, n = s.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i < s.length(); i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (reps[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
    for (int i = 1; i < n; i++)
//        if (dp[n][i] == dp[n][n]) cnt++;
        cout << dp[n][i]<< endl;
    cout << dp[n][n] << " " << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}