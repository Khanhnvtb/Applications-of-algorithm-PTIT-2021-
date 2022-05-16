//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;

void input() {
    cin >> s;
}

void solve() {
    int res = 1;
    int n = s.length() - 1;
    for (int i = 1; i < n; i++) {
        int l = i - 1, r = i + 1;
        int cnt = 1;
        while (l >= 0 && r <= n) {
            if (s[l] == s[r]) cnt += 2;
            else break;
            l--;
            r++;
        }
        res = max(res, cnt);
    }
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        int cnt = 0;
        while (l >= 0 && r <= n) {
            if (s[l] == s[r]) cnt += 2;
            else break;
            l--;
            r++;
        }
        res = max(res, cnt);
    }
    printf("%d\n", res);
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
