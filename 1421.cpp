//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b, c;
        char d;
        scanf("%d %d %c", &b, &c, &d);
        s.insert(b);
        s.insert(c);
    }
}

void solve() {
    for (int i: s) printf("%d ", i);
    printf("\n");
    s.clear();
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