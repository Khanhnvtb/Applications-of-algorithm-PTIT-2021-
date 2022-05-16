//
// Created by Nguyễn Văn Khánh on 11/28/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[20], s, ans;

void input() {
    s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
}

void Try(int i, int s1, int s2, int s3) {
    if (i == n) {
        if (s1 == s2 && s2 == s3) ans++;
        return;
    }
    if (s1 + a[i] <= s) Try(i + 1, s1 + a[i], s2, s3);
    if (s2 + a[i] <= s) Try(i + 1, s1, s2 + a[i], s3);
    if (s3 + a[i] <= s) Try(i + 1, s1, s2, s3 + a[i]);
}

void solve() {
    ans = 0;
    if (s % 3 == 0) {
        s /= 3;
        Try(0, 0, 0, 0);
    }
    cout << ans << endl;
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

