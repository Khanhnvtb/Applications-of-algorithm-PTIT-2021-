//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

char c, a[15];
int k;

void input() {
    scanf("%c %d", &c, &k);
}

void print() {
    for (int i = 0; i <= k; i++) printf("%c", a[i]);
    printf("\n");
}

void Try(int i, char x) {
    for (int j = x; j <= c; j++) {
        a[i] = j;
        if (i == k) print();
        else Try(i + 1, j);
    }
}

void solve() {
    k--;
    Try(0, 'A');
}

int main() {
    input();
    solve();
    return 0;
}