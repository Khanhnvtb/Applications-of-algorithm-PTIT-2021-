//
// Created by khanh on 10/13/2021.
//
#include <bits/stdc++.h>

using namespace std;

string s1, s2;

void input() {
    s1 = "", s2 = "";
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        s1 += c;
    }
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        s2 += c;
    }
}

int bfs() {
    if (s1 == s2) return 0;
    queue<pair<string, int> > q;
    q.push({s1, 0});
    while (1) {
        s1 = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        string tmp = "";
        tmp += s1[3];
        tmp += s1[0];
        tmp += s1[2];
        tmp += s1[4];
        tmp += s1[1];
        tmp += s1[5];
        if (tmp == s2) return cnt;
        else q.push({tmp, cnt});
        tmp = "";
        tmp += s1[0];
        tmp += s1[4];
        tmp += s1[1];
        tmp += s1[3];
        tmp += s1[5];
        tmp += s1[2];
        if (tmp == s2) return cnt;
        else q.push({tmp, cnt});
    }
}

void solve() {
    printf("%d\n", bfs());
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
