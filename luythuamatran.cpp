//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, m = 1e9 + 7;
long long a[10][10], repa[10][10];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
            repa[i][j] = a[i][j];
        }
}

void mul(long long b[][10], long long c[][10]) {
    long long tmp[10][10] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int z = 0; z < n; z++)
                tmp[i][j] += (b[i][z] % m * c[z][j] % m) % m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = tmp[i][j] % m;
}

void power(int x) {
    if (x == 1) return;
    power(x / 2);
    mul(a, a);
    if (x % 2 == 1) mul(a, repa);
}

void solve() {
    power(k);
    n--;
    long long res = 0;
    for (int i = 0; i <= n; i++) {
        res += a[i][n];
        res %= m;
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