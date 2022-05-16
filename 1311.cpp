//
// Created by khanh on 10/10/2021.
//
#include <bits/stdc++.h>

using namespace std;

int n, a[1005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    int i;
    for (i = n; i > 1; i--) {
        if (a[i - 1] < a[i]) {
            for (int j = n; j >= i; j--) {
                if (a[j] > a[i - 1]) {
                    swap(a[i - 1], a[j]);
                    int l = i;
                    int r = n;
                    while (l < r) swap(a[l++], a[r--]);
                    break;
                }
            }
            break;
        }
    }
    if (i == 1) for (i = 1; i <= n; i++) printf("%d ", i);
    else for (i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
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
