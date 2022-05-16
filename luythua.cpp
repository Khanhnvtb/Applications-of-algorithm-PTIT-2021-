//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int m = 1e9 + 7;

long long luythua(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long  tmp = luythua(a, b / 2);
    if (b % 2 == 0) return (tmp % m * tmp % m) % m;
    else return ((tmp % m * tmp % m) * a % m) % m;
}

int main() {
    long long a, b;
    while (1) {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0) break;
        printf("%lld\n", luythua(a, b));
    }
    return 0;
}