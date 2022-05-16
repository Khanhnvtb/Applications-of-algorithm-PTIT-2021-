//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, a[20];
vector<int> v;

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void print() {
    for (int i: v) printf("%d ", i);
    printf("\n");
}

void Try(int i, int size) {
    if (size == k) {
        print();
        return;
    }
    if (i == n) return;
    v.push_back(a[i]);
    Try(i + 1, size + 1);
    v.pop_back();
    Try(i + 1, size);
}

void solve() {
    sort(a, a + n);
    Try(0, 0);
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