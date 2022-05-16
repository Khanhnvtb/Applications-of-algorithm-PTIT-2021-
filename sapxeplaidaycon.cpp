//
// Created by Nguyen Van Khanh on 10/30/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int l = 0, r = n - 1;
    while (a[l] <= a[l + 1] && l < n - 1) l++;
    while (a[r] >= a[r - 1] && r > 0) r--;
    long min = a[l], max = a[l];
    for (long i = l + 1; i <= r; i++) {
        if (a[i] < min)min = a[i];
        if (a[i] > max) max = a[i];
    }
    for (long i = 0; i <= l; i++)
        if (a[i] > min) {
            l = i + 1;
            break;
        }
    for (long i = n - 1; i >= r; i--)
        if (a[i] < max) {
            r = i + 1;
            break;
        }
    cout << l << " " << r << endl;
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