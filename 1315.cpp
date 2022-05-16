//
// Created by khanh on 10/8/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[15], used[15];

void print() {
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    printf(" ");
}

void Try(int i) {
    for (int j = n; j > 0; j--) {
        if (!used[j]) {
            a[i] = j;
            used[j] = 1;
            if (i == n) print();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}

void input() {
    scanf("%d", &n);
}

void solve() {
    Try(1);
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