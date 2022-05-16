//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[10];

void input() {
    scanf("%d", &n);
}

void print() {
    printf("%d", a[0]);
    for (int i = 1; i <= n; i++) {
        if (a[i] + a[i - 1] == 1)printf("1");
        else printf("0");
    }
    printf(" ");
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) print();
        else Try(i + 1);
    }

}

void solve() {
    n--;
    Try(0);
    printf("\n");
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