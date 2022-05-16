//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000005], b[1000005];

void input() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = m - a[i];
    }
}

long long findMaxArea(int arr[]) {
    long long res = 0, x, y, mul;
    int i = 0;
    stack<int> s;
    while (i < n) {
        if (s.size() == 0 || arr[s.top()] <= arr[i]) {
            s.push(i);
            i++;
        } else {
            x = s.top();
            s.pop();
            if (s.size() > 0) y = s.top();
            mul = arr[x] * (s.empty() ? i : i - y - 1);
            res = max(res, mul);
        }
    }
    while (s.size() > 0) {
        x = s.top();
        s.pop();
        if (s.size() > 0) y = s.top();
        mul = arr[x] * (s.empty() ? i : i - y - 1);
        res = max(res, mul);
    }
    return res;
}

void solve() {
    printf("%lld", max(findMaxArea(a), findMaxArea(b)));
}

int main() {
    input();
    solve();
    return 0;
}