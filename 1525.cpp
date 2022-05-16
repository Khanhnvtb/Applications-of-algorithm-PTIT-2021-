//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

bool check(string s) {
    long long tmp = 0;
    for (int i = 0; i < s.length (); i++) {
        tmp = tmp * 10 + (s[i] - 48);
        tmp %= n;
    }
    if (tmp == 0) return true;
    else return false;
}

void solve() {
    queue <string> s;
    s.push ("1");
    while (1) {
        string res = s.front ();
        s.pop ();
        if (check (res)) {
            cout << res << endl;
            break;
        }
        s.push (res + "0");
        s.push (res + "1");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input ();
        solve ();
    }
    return 0;
}