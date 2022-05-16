//
// Created by Nguyen Van Khanh on 11/7/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    n /= 2;
    queue<string> q;
    q.push("0");
    q.push("1");
    while (1) {
        string tmp = q.front();
        if (tmp.length() > n) break;
        q.push(tmp + '0');
        q.push(tmp + '1');
        cout << tmp;
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
        cout << " ";
        q.pop();
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