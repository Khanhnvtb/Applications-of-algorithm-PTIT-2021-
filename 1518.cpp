//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    cin >> str;
}

void solve() {
    stack<int> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y + x);
        } else if (str[i] == '-') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y - x);
        } else if (str[i] == '*') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x * y);
        } else if (str[i] == '/') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y / x);
        } else s.push(str[i] - '0');
    }
    printf("%d\n", s.top());
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        input();
        solve();
    }
    return 0;
}