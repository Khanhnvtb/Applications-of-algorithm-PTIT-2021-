//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, dp[100005];

void input() {
    scanf("%d", &n);
}

int firstDigit(int x) {
    while (x > 9) x /= 10;
    return x;
}

void Try(int i, int s, int pre) {
    dp[i] = max(dp[i], s);
    if (i == 100000) return;
    if (firstDigit(s + pre) == pre) Try(i + 1, s + pre, pre);
    int tmp = s + pre + 1;
    if (firstDigit(tmp) == pre + 1) Try(i + 1, tmp, pre + 1);
    if (pre == 9 && firstDigit(s + 1) == 1) Try(i + 1, s + 1, 1);
}

void solve() {
    for (int i = 0; i <= 100000; i++) dp[i] = 0;
    Try(1, 9, 9);
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        printf("%d\n", dp[n]);
    }
    return 0;
}