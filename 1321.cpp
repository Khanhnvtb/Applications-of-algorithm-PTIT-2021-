//
// Created by khanh on 10/11/2021.
//
#include <bits/stdc++.h>

using namespace std;

struct data {
    int s, e;
};

int n;
data a[1005];

int cmp(data x, data y) {
    if (x.e < y.e) return 1;
    if (x.e == y.e && x.s < y.s) return 1;
    return 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].s, &a[i].e);
}

void solve() {
    sort(a, a + n, cmp);
    int res = 1, prev = a[0].e;
    for (int i = 1; i < n; i++)
        if (a[i].s >= prev) {
            res++;
            prev = a[i].e;
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
