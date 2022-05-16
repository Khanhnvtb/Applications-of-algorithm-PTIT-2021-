//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
        if (a[i] + k < a[i + 1]) ans++;
    printf("%d", ans);
}

int main() {
    input();
    solve();
    return 0;
}