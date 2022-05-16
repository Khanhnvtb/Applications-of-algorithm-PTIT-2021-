//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[100005];
long long k;

void input() {
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    long long s = 0;
    int state = 0, inDex = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (k == 0 && a[i] == 0) {
            state = 1;
            break;
        }
        if (s > k) {
            while (s > k && inDex < i) s -= a[inDex++];
        }
        if (s == k) {
            state = 1;
            break;
        }
    }
    if (state == 1) printf("YES\n");
    else printf("NO\n");
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