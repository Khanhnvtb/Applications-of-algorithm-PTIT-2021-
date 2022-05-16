//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long m = 1e9 + 7, a[10][10], s[10][10];
int n, k;

void mul(long long a[][10], long long b[][10]) {
    long long ans[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                ans[i][j] += a[i][k] * b[k][j] % m;
                ans[i][j] %= m;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = ans[i][j];
}

void power(long long a[][10], int k) {
    if (k == 1) return;
    power(a, k / 2);
    mul(a, a);
    if (k % 2 == 1) mul(a, s);
}

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%lld", &s[i][j]);
            a[i][j] = s[i][j];
        }
}

void solve() {
    power(a, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
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