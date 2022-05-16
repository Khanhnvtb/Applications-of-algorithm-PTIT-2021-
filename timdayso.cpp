//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1005], b[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int check;
    res = 0;
    for (int i = 1; i <= a[n - 1] / 2 + 1; i++) {
        check = 1;
        int x = a[n - 1] / i;
        b[n - 1] = i;
        for (int j = n - 2; j >= 0; j--) {
            int tmp = a[j] / x;
            if (tmp == 0 || a[j] / tmp > x) {
                check = 0;
                break;
            } else {
                while (tmp > 1 && a[j] / (tmp - 1) == x) tmp--;
                b[j] = tmp;
            }
        }
        if (check == 1) break;
    }
    for (int i = 0; i < n; i++) res += b[i];
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}