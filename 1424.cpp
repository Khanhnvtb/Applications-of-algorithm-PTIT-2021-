//
// Created by Nguyen Van Khanh on 10/29/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int res = 1;
    for (int i = 1; i < n; i++)
        if (a[i] <= a[i - 1]) {
            res = 0;
            break;
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