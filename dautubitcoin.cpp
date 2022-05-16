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
    deque<int> dq;
    dq.push_back(a[0]);
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (dq.front() < a[i]) {
            if (dq.size() == 2) res = max(res, dq.front() - dq.back());
            dq.clear();
            dq.push_back(a[i]);
        } else if (dq.size() == 1 && dq.back() > a[i]) dq.push_back(a[i]);
        else if (dq.size() == 2 && dq.back() > a[i]) {
            dq.pop_back();
            dq.push_back(a[i]);
        }
    }
    if (dq.size() == 2) res = max(res, dq.front() - dq.back());
    if (res != 0) printf("%d", res);
    else printf("Lo nang roi!");
}

int main() {
    input();
    solve();
    return 0;
}