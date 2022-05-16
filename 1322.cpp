//
// Created by khanh on 10/10/2021.
//

#include <bits/stdc++.h>

using namespace std;

priority_queue<long long , vector<long long>, greater<long long>> pq;
int n;

void input() {
    scanf("%d", &n);
    long long x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
}

void solve() {
    long long res = 0;
    while (pq.size() > 1) {
        long long tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        res += tmp;
        pq.push(tmp);
    }
    pq.pop();
    printf("%lld\n", res);
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