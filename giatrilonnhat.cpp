//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0) res += a[i];
    }
    printf("%lld", res * 2);
    return 0;
}