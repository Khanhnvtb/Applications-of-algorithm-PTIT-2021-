//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long n;
string s;

void input() {
    scanf("%lld", &n);
    cin >> s;
}

void solve() {
    long long res = n * (n - 1) / 2;
    for (int x = 0; x < 2; x++) {
        int cur = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) cur += 1;
            else {
                res -= cur - x;
                cur = 1;
            }
        }
        reverse(s.begin(), s.end());
    }
    printf("%lld", res);
}

int main() {
    input();
    solve();
    return 0;
}