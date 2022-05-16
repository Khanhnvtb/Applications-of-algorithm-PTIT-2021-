//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, a[35];
vector<string> res;
vector<string> v;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void Try(int i, int pre) {
    if (i == n) {
        if (v.size() > 1) {
            string tmp = "";
            for (int i = 0; i < v.size() - 1; i++) tmp += v[i] + " ";
            tmp += v[v.size() - 1];
            res.push_back(tmp);
        }
        return;
    }
    if (a[i] >= pre) {
        v.push_back(to_string(a[i]));
        Try(i + 1, a[i]);
        v.pop_back();
    }
    Try(i + 1, pre);
}

void solve() {
    Try(0, INT_MIN);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        printf("\n");
    }
}

int main() {
    input();
    solve();
    return 0;
}