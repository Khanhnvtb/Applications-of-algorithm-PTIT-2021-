//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}


void solve() {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i < n; i++) {
        printf("%d ", a[dq.front()]);
        if (dq.front() == i - k) dq.pop_front();
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    printf("%d\n", a[dq.front()]);
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