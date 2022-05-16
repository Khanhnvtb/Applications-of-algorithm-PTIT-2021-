//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a, b, sumDiv[1000005];

void createSumOfDivisor(int n) {
    for (int i = 1; i <= n; i++) sumDiv[i] = 1;
    for (int i = 2; i <= n / 2; i++) {
        for (int j = i * 2; j <= n; j += i)
            sumDiv[j] += i;
    }
}

void input() {
    scanf("%d %d", &a, &b);
}

void solve() {
    int res = 0;
    createSumOfDivisor(b);
    for (int i = a; i <= b; i++)
        if (sumDiv[i] > i) res++;
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}