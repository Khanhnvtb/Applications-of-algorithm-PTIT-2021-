//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;
long long res;

void input() {
    cin >> s;
}

void solve() {
    res = 0;
    for (int i = 1; i <= s.length(); i++)
        for (int j = 0; j < s.length() - i + 1; j++) {
            int val = 0;
            for (int k = j; k < j + i; k++)
                val = val * 10 + s[k] - '0';
            res += val;
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