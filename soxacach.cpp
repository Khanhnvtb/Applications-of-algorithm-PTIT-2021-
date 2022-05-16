//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a[10];
int used[10] = {0};
int n, state = 0;

void printResult() {
    state = 1;
    for (int i = 0; i < n; i++) printf("%d", a[i]);
    printf("\n");
}

void Try(int i) {
    if (i == n) printResult();
    for (int j = 1; j <= n; j++) {
        if (i == 0 && used[j] == 0) {
            a[i] = j;
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
        } else if (i > 0 && used[j] == 0 && abs(j - a[i - 1]) != 1) {
            a[i] = j;
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d", &n);
        Try(0);
        if (state == 0) printf("\n");
    }
    return 0;
}