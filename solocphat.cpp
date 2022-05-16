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
    stack<string> s;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (1) {
        string tmp = q.front();
        if (tmp.length() > n) break;
        s.push(tmp);
        q.pop();
        q.push(tmp + '6');
        q.push(tmp + '8');
    }
    printf("%d\n", s.size());
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        printf(" ");
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