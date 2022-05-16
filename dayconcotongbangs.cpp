//
// Created by Khanh Nguyen Van on 10/18/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long n, s, a[35];
int res;

void input() {
    scanf("%lld %lld", &n, &s);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
}

void Try(int i, long long sum, int cnt) {
    if (sum == s) {
        res = min(res, cnt);
        return;
    }
    if (sum > s) return;
    if (cnt == res) return;
    if (i == n) return;
    Try(i + 1, sum + a[i], cnt + 1);
    Try(i + 1, sum, cnt);
}

void solve() {
    res = INT_MAX;
    Try(0, 0, 0);
    if (res == INT_MAX) res = -1;
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}