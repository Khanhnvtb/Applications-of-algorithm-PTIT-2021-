//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

long n, res, m = 1e9 + 7;
priority_queue<long, vector<long>, greater<long> > q;

void input() {
    scanf("%ld", &n);
    long x;
    for (long i = 0; i < n; i++) {
        scanf("%ld", &x);
        q.push(x);
    }
}

void solve() {
    res = 0;
    while (q.size() > 1) {
        long x = q.top();
        q.pop();
        long y = q.top();
        q.pop();
        long z = x + y;
        q.push(z % m);
        res = (res + z) % m;
    }
    printf("%ld", res);
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