//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;
long res;

void input() {
    cin >> s;
}

long long toInt(string n) {
    long long val = 0;
    for (int i = 0; i < n.length(); i++)
        val = val * 10 + n[i] - 48;
    return val;
}

void solve() {
    res = 0;
    for (int i = 1; i <= s.length(); i++)
        for (int j = 0; j <= s.length() - i; j++) {
            string n = "";
            for (int k = j; k < j + i; k++)
                n += s[k];
            res += toInt(n);
        }
    printf("%lld\n", res);
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