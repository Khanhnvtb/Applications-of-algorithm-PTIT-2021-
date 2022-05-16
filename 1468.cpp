//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

char s[45];
int dp[45];

void input() {
    scanf("%s", &s);
}

void solve() {
    if (s[0] == '0') printf("0\n");
    else {
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= strlen(s); i++) {
            dp[i] = 0;
            int prev = i - 2;
            int curr = i - 1;
            if (s[curr] > '0') dp[i] = dp[curr];
            if (s[prev] == '1' || (s[prev] == '2' && s[curr] < '7')) dp[i] += dp[prev];
        }
        printf("%d\n", dp[strlen(s)]);
    }
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