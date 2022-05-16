//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

long long a, b;
vector<long long> v;
long long res = 0;

void input() {
    scanf("%lld %lld", &a, &b);
}

long long toInt(string s) {
    long long val = 0;
    for (int i = 0; i < s.length(); i++)
        val = val * 10 + s[i] - '0';
    return val;
}

void createLuckyNumber() {
    queue<string> q;
    q.push("4");
    q.push("7");
    while (1) {
        string tmp = q.front();
        q.pop();
        if (tmp.length() == 10) break;
        v.push_back(toInt(tmp));
        q.push(tmp + '4');
        q.push(tmp + '7');
    }
}

void solve() {
    createLuckyNumber();
    long long pre = a;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= pre) {
            if (b <= v[i]) {
                res += (b - pre + 1) * v[i];
                break;
            } else res += (v[i] - pre + 1) * v[i];
            pre = v[i] + 1;
        }
    }
    printf("%lld", res);
}

int main() {
    input();
    solve();
    return 0;
}