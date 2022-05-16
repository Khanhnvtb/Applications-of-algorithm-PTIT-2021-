//
// Created by Nguyễn Văn Khánh on 11/28/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;

bool check(char c2, char c1) {
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '(' && c2 == ')') return true;
    return false;
}

void input() {
    getline(cin, str);
}

void solve() {
    int n = str.length();
    int res[n];
    memset(res, 0, sizeof(res));
    int ans = 0;
    stack<int> s1;
    stack<char> s2;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '[' || str[i] == '(') {
            s2.push(str[i]);
            s1.push(i);
        } else {
            if (s2.empty() || check(str[i], s2.top()) == false) {
                while (!s1.empty()) s1.pop();
                while (!s2.empty()) s2.pop();
            } else {
                int cnt = 0;
                for (int j = s1.top(); j <= i; j++) {
                    if (str[j] == '[') cnt++;
                }
                int tmp = s1.top();
                if (tmp > 0 && res[tmp - 1] != 0) cnt += res[tmp - 1];
                ans = max(ans, cnt);
                res[i] = cnt;
                s1.pop();
                s2.pop();
            }
        }
    }
    cout << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}