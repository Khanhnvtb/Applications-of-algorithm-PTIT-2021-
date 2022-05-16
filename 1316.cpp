//
// Created by khanh on 10/10/2021.
//
#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;

void input() {
    scanf("%d", &n);
    cin >> s;
}

void Try(int i, string str) {
    if (i == n) {
        v.push_back(str);
        return;
    }
    Try(i + 1, str);
    Try(i + 1, str + s[i]);
}

void solve() {
    string str = "";
    Try(0, str);
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
    printf("\n");
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
