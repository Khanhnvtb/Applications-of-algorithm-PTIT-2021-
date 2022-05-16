//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) printf("0 ");
        else printf("1 ");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) printf("1 ");
        else printf("0 ");
    }
}

int main() {
    input();
    solve();
    return 0;
}