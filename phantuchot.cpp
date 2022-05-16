//
// Created by Nguyen Van Khanh on 10/31/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    stack<int> s;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > tmp) {
            s.push(a[i]);
            tmp = a[i];
        } else {
            while (!s.empty() && a[i] < s.top()) s.pop();
        }
    }
    printf("%d\n", s.size());
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
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