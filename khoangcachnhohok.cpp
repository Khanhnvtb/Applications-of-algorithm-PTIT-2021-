//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

int a[100005];

int upper_bound(int n, int s) {
    int mid;
    int low = 0;
    int high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] > s) {
            if (mid == 0 || a[mid - 1] <= s) return mid;
            else high = mid - 1;
        } else {
            if (a[mid + 1] > s) return mid + 1;
            else low = mid + 1;
        }
    }
    return n;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        long long res = 0;
        for (int i = 1; i < n; i++)
            res += i - upper_bound(i, a[i] - k);
        printf("%lld\n", res);
    }
    return 0;
}