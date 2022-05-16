//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include<bits/stdc++.h>

using namespace std;

int n, k;

void input() {
    scanf("%d %d", &n, &k);
}

char find(int n, int k) {
    int tmp = pow(2, n - 1);
    if (k == tmp) return n + 64;
    else if (k > tmp) return find(n - 1, k - tmp);
    else return find(n - 1, k);
}

void solve() {
    printf("%c\n", find(n, k));
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