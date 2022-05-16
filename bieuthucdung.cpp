//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    cin >> str;
}

void solve() {
    int res = 0, cnt = 0;
    stack<int> s;
    int state = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(1);
            cnt++;
            res = max(cnt, res);
        } else if (str[i] == ')') {
            if (!s.empty()) {
                s.pop();
                cnt--;
            } else {
                state = -1;
                break;
            }
        }
    }
    if (!s.empty() || state == -1) printf("-1\n");
    else printf("%d\n", res);
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