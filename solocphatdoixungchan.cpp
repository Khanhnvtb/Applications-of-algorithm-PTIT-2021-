//
// Created by Nguyen Van Khanh on 11/7/2021.
//

//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    int cnt = 0;
    string ans = "";
    queue<string> q;
    q.push("6");
    q.push("8");
    while (1) {
        cnt++;
        string tmp = q.front();
        if (cnt > n) break;
        q.pop();
        q.push(tmp + '6');
        q.push(tmp + '8');
        ans += tmp;
        reverse(tmp.begin(), tmp.end());
        ans += tmp + " ";
    }
    cout << ans << endl;
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