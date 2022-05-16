//
// Created by Nguyen Van Khanh on 10/24/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int state = 0;
    //state = 1 tăng
    //state = 2 giảm
    //state = 0 chưa xác định
    int pre = a[0], inDex = 0, res = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (a[i] == pre) {
            res = max(res, i - inDex);
            inDex = i;
            state = 0;
        }
        if (state == 0) {
            if (a[i] > pre) state = 1;
            else if (a[i] < pre) state = 2;
        } else if (state == 1) {
            if (a[i] < pre) state = 2;
        } else if (state == 2) {
            if (a[i] > pre) {
                res = max(res, (i - inDex));
                inDex = i - 1;
                state = 1;
            }
        }
        pre = a[i];
    }
    res = max(res, n - inDex);
    printf("%d\n", res);
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