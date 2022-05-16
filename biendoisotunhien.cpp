//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

int solve() {
    if (n == 1) return 0;
    set<int> s;
    s.insert(n);
    queue<pair<int, int> > q;
    q.push({n, 0});
    while (!q.empty()) {
        int val = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        for (int i = sqrt(val); i >= 2; i--) {
            if (val % i == 0 && s.find(val / i) == s.end()) {
                q.push({val / i, cnt});
                s.insert(val / i);
            }
        }
        if (val - 1 == 1) return cnt;
        else if (s.find(val - 1) == s.end()) {
            q.push({val - 1, cnt});
            s.insert(val - 1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        cout << solve() << endl;
    }
    return 0;
}