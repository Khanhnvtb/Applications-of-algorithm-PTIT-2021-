//
// Created by khanh on 10/10/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long Fibo[93];
int n;
long long k;

void createFiboNumbers() {
    Fibo[0] = 0;
    Fibo[1] = 1;
    for (int i = 2; i < 93; i++) Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
}

void input() {
    scanf("%d %lld", &n, &k);
}

char find(int n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= Fibo[n - 2]) return find(n - 2, k);
    else return find(n - 1, k - Fibo[n - 2]);
}

void solve() {
    printf("%c\n", find(n, k));
}

int main() {
    int t;
    scanf("%d", &t);
    createFiboNumbers();
    while (t--) {
        input();
        solve();
    }
    return 0;
}