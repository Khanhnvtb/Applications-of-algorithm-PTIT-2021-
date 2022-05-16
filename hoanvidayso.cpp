//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[10], used[10] = {0}, res[10];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void print() {
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
}

void Try(int i) {
    if (i == n) print();
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            res[i] = a[j];
            Try(i + 1);
            used[j] = 0;
        }
    }
}

void solve() {
    sort(a, a + n);
    Try(0);
}

int main() {
    input();
    solve();
    return 0;
}