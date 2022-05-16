//
// Created by Nguyễn Văn Khánh on 11/27/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, s, a[205], dp[40005];

void input() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i <= s; i++) dp[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = s; j > a[i]; j--)
            dp[j] = dp[j - a[i]];
        if (dp[s] == 1) break;
    }
    if (dp[s]) printf("YES\n");
    else printf("NO\n");
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