//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, res = INT_MAX, c1, c2, a[5000005], b[5000005];
map<int, int> hm;
map<int, int>::iterator it;

void input() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &c1, &c2);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
}

void solve() {
    int tmp = abs(c2 - c1);
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++) {
        int inDex = lower_bound(b, b + m, a[i]) - b;
        if (inDex == m) {
            hm[tmp + a[i] - b[inDex - 1]]++;
            continue;
        }
        if (b[inDex] == a[i]) hm[tmp]++;
        else {
            int y = b[inDex] - a[i];
            if (inDex > 0) {
                int x = a[i] - b[inDex - 1];
                if (x == y) hm[tmp + y] += 2;
                else if (x < y) hm[tmp + x] += 1;
                else hm[tmp + y] += 1;
            } else hm[tmp + y] += 1;
        }
    }
    for (it = hm.begin(); it != hm.end(); it++) {
        int d = it->first;
        res = min(res, d);
    }
    printf("%d %d", res, hm[res]);
}

int main() {
    input();
    solve();
    return 0;
}
