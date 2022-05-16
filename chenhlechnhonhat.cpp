//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, hoanVi[10], used[10] = {0};
vector<string> v;
vector<string> num;
int res = INT_MAX;

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        num.push_back(s);
    }
}

int toInt(char c[]) {
    int val = 0;
    for (int i = 0; i <= k; i++)
        val = val * 10 + (c[i] - '0');
    return val;
}

void Try(int i) {
    for (int j = 0; j <= k; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            hoanVi[i] = j;
            if (i == k) {
                string tmp = "";
                for (int c = 0; c <= k; c++)
                    tmp += (hoanVi[c] + '0');
                v.push_back(tmp);
            } else Try(i + 1);
            used[j] = 0;
        }
    }
}

void solve() {
    k--;
    Try(0);
    for (int i = 0; i < v.size(); i++) {
        string s = v[i];
        vector<int> a;
        for (int j = 0; j < n; j++) {
            char val[10];
            for (int c = 0; c <= k; c++)
                val[c] = num[j][s[c] - '0'];
            a.push_back(toInt(val));
        }
        sort(a.begin(), a.end());
        res = min(res, a[a.size() - 1] - a[0]);
    }
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}