//
// Created by Nguyen Van Khanh on 10/31/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;

void input() {
    cin >> s;
}

void solve() {
    int n = s.length() - 1, cnt = 1, res = 0, rota = 0, inDex = 0;
    int a[n + 5] = {0};
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            if (cnt == 1) {
                if (s[i] == 'A') a[inDex++] = -1;
                else a[inDex++] = 1;
            } else {
                if (s[i] == 'A') a[inDex++] = -2;
                else a[inDex++] = 2;
            }
            cnt = 1;
        } else cnt++;
    }
    if (cnt == 1) {
        if (s[n] == 'A') a[inDex] = 1;
        else a[inDex] = -1;
    } else {
        if (s[n] == 'A') a[inDex] = 2;
        else a[inDex] = -2;
    }
    while (inDex >= 0) {
        if (abs(a[inDex]) == 1) {
            if (a[inDex] < 0) {
                res += 1;
                inDex -= 2;
                if (inDex >= 0 && rota % 2 == 1) a[inDex] = -a[inDex];
            } else {
                inDex--;
                if (inDex >= 0 && rota % 2 == 1) a[inDex] = -a[inDex];
            }
        } else {
            if (a[inDex] < 0) {
                res += 1;
                inDex -= 1;
                rota += 1;
                if (inDex >= 0 && rota % 2 == 1) a[inDex] = -a[inDex];
            } else {
                inDex--;
                if (inDex >= 0 && rota % 2 == 1) a[inDex] = -a[inDex];
            }
        }
    }
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}