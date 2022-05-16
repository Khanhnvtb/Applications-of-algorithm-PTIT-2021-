//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, s, state, a[100005];

void input() {
    s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
}

void Try(int i, int sum) {
    int tmp = 0;
    for (int j = i; j < n; j++) {
        tmp += a[j];
        if (tmp == sum) tmp = 0;
        else if (tmp > sum) return;
    }
    state = 1;
}

void solve() {
    int sum = 0;
    state = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (s % sum == 0) Try(i + 1, sum);
        if (state == 1) {
            printf("%d\n", sum);
            return;
        }
    }
    printf("%d\n", s);
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