//
// Created by Nguyen Van Khanh on 10/31/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> s;

void input() {
    cin >> str;
}

void solve() {
    char pre = str[str.length() - 1];
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] >= pre) {
            s.push(str[i]);
            pre = str[i];
        }
    }
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
}

int main() {
    input();
    solve();
    return 0;
}