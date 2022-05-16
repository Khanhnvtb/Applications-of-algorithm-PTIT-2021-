//
// Created by khanh on 10/11/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

void input() {
    scanf("%d %lld", &n, &k);
}

long long find(int n, long long k) {
    if (k == pow(2, n - 1)) return n;
    if (k > pow(2, n - 1)) return find(n - 1, k - pow(2, n - 1));
    return find(n - 1, k);
}

void solve() {
    printf("%lld\n", find(n, k));
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