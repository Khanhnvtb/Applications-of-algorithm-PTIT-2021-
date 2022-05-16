//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

struct data {
    int w, c;
};

int n;
float w;
data a[105];

int cmp(data x, data y) {
    return ((float) x.c / x.w > (float) y.c / y.w);
}

void input() {
    scanf("%d %f", &n, &w);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].c, &a[i].w);
}

void solve() {
    sort(a, a + n, cmp);
    float ans = 0;
    for (int i = 0; i < n; i++) {
        if (w >= a[i].w) {
            ans += a[i].c;
            w -= a[i].w;
        } else {
            ans += a[i].c * w / a[i].w;
            break;
        }
    }
    printf("%.2f\n", ans);
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