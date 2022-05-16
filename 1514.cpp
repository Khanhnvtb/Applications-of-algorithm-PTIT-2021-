//
// Created by khanh on 10/13/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    cin >> str;
}

void solve() {
    stack<char> s1;
    stack<char> s2;
    for (int i = 0; i < str.length(); i++) {
        if (s1.empty() && str[i] == ')') {
            s2.push(')');
            s1.push('(');
        } else if (!s1.empty() && str[i] == ')') s1.pop();
        else s1.push('(');
    }
    printf("%d\n", s2.size() + s1.size() / 2);
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