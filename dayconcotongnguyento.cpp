//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[20];
vector<int> v;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void print() {
    if (v.size()) {
        for (int i: v) printf("%d ", i);
        printf("\n");
    }
}

void Try(int i, int s) {
    if (i == -1) {
        if (isPrime(s)) print();
        return;
    }
    Try(i - 1, s);
    v.push_back(a[i]);
    Try(i - 1, s + a[i]);
    v.pop_back();
}

void solve() {
    sort(a, a + n);
    Try(n - 1, 0);
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