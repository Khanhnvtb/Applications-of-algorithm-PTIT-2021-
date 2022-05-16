//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    queue<string> q;
    q.push("4");
    q.push("5");
    int cnt = 0;
    while (1) {
        cnt++;
        string tmp = q.front();
        if (cnt > n) break;
        q.pop();
        q.push(tmp + '4');
        q.push(tmp + '5');
        cout << tmp;
        reverse(tmp.begin(), tmp.end());
        cout << tmp << " ";
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