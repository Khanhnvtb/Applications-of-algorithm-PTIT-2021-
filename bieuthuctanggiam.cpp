//
// Created by Nguyen Van Khanh on 11/6/2021.
//
#include <bits/stdc++.h>

using namespace std;

string s;

void input() {
    cin >> s;
}

void solve(int t) {
    stack<int> st;
    printf("Test %d: ", t);
    for (int i = 0; i <= s.length(); i++) {
        st.push(i + 1);
        if (s[i] == 'I' || i == s.length()) {
            while (!st.empty()) {
                printf("%d", st.top());
                st.pop();
            }
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
