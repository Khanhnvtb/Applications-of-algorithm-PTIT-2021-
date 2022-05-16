//
// Created by Nguyễn Văn Khánh on 11/28/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long p;

void input() {
    cin >> p;
}

void solve() {
    vector<int> a;
    while (p > 9) {
        int i = 9;
        while (p % i != 0) i--;
        if (i == 1) break;
        p /= i;
        a.push_back(i);
    }
    if (p > 9) cout << -1 << endl;
    else {
        a.push_back(p);
        for (int i = a.size() - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}