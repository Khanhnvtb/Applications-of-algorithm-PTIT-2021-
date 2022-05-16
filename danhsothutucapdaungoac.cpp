//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s;

void input() {
    getline(cin, s);
}

void solve() {
    stack<int> st;
    int cnt = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            printf("%d ", cnt);
            st.push(cnt++);
        } else if (s[i] == ')') {
            printf("%d ", st.top());
            st.pop();
        }
    }
    printf("\n");
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