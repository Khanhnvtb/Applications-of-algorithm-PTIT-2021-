//
// Created by Nguyen Van Khanh on 10/31/2021.
//

//
// Created by Nguyen Van Khanh on 10/31/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    int minVal[n + 1], maxVal[n + 1];
    int pre = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (a[i] > pre) {
            maxVal[i] = a[i];
            pre = a[i];
        } else maxVal[i] = pre;
    }
    pre = INT_MAX;
    for (int i = n; i >= 0; i--) {
        if (a[i] < pre) {
            minVal[i] = a[i];
            pre = a[i];
        } else minVal[i] = pre;
    }
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i < n; i++)
        if (maxVal[i] <= minVal[i + 1]) {
            cnt++;
            q.push(i);
        }
    if (cnt == 0) printf("%d", cnt);
    else {
        printf("%d\n", cnt);
        while (!q.empty()) {
            printf("%d ", q.front());
            q.pop();
        }
    }
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