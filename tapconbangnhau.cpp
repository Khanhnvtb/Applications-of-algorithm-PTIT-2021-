//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[105], s;
string res;

void input() {
    s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
}

void Try(int i, int sum) {
    if (res == "YES") return;
    if (i == n) return;
    if (sum == s) {
        res = "YES";
        return;
    }
    if (sum > s) return;
    Try(i + 1, sum + a[i]);
    Try(i + 1, sum);
}

void solve() {
    res = "NO";
    if (s % 2 == 0) {
        s /= 2;
        Try(0, 0);
    }
    cout << res << endl;
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