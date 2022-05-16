//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

struct straightLine {
    int start, end;
};

int n;
straightLine a[100005];

int cmp(straightLine x, straightLine y) {
    if (x.end < y.end) return 1;
    if (x.end == y.end && x.start < y.start) return 1;
    return 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].start, &a[i].end);
}

void solve() {
    sort(a, a + n, cmp);
    int ans = 1, prev = a[0].end;
    for (int i = 1; i < n; i++) {
        if (a[i].start >= prev) {
            ans++;
            prev = a[i].end;
        }
    }
    printf("%d\n", ans);
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