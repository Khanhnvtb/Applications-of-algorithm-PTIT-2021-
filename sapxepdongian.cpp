//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    int maxIncre = 1;
    int cnt[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        if (cnt[a[i] - 1] == 0) cnt[a[i]] = 1;
        else cnt[a[i]] = cnt[a[i] - 1] + 1;
        maxIncre = max(maxIncre, cnt[a[i]]);
    }
    printf("%d", n - maxIncre);
}

int main() {
    input();
    solve();
}