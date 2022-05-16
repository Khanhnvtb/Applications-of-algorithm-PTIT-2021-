//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n);
    if (n % 2 == 1) printf("%d\n", a[n / 2]);
    else printf("%d\n", a[n / 2 - 1]);
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