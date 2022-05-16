//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, m = 1e9 + 7;

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    if (k > n) printf("0\n");
    else {
        long res = 1;
        for (int i = n - k + 1; i <= n; i++) {
            res *= i;
            res %= m;
        }
        printf("%ld\n", res);
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