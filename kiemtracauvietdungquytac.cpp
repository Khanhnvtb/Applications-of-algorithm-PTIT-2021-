//
// Created by Nguyen Van Khanh on 11/7/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    getline(cin, str);
}

int check(char c) {
    if (c == '[') return 1;
    else if (c == '(') return 2;
    else if (c == ')') return -2;
    else if (c == ']') return -1;
    return 0;
}

void solve() {
    stack<int> s;
    int state = 1;
    for (int i = 0; i < str.length(); i++) {
        int x = check(str[i]);
        if (x > 0) s.push(x);
        else if (x < 0) {
            if (s.empty() || s.top() + x != 0) {
                state = 0;
                break;
            } else s.pop();
        }
    }
    if (s.empty() && state) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--) {
        input();
        solve();
    }
    return 0;
}