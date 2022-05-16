//
// Created by Nguyen Van Khanh on 10/31/2021.
//
#include <bits/stdc++.h>

using namespace std;

int m, n, a[505];
map<int, int> hm;
map<int, int>::iterator it;

int cmp(pair<int, int> x, pair<int, int> y) {
    if (x.first > y.first) return 1;
    else if (x.first == y.first && x.second < y.second) return 1;
    return 0;
}

void input() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        hm[a[i]]++;
    }
}

void solve() {
    vector<pair<int, int>> v;
    for (it = hm.begin(); it != hm.end(); it++)
        v.push_back({it->second, it->first});
    sort(v.begin(), v.end(), cmp);
    if (v.size() < 2) printf("NONE");
    else {
        if (v[v.size() - 1].first == v[0].first) printf("NONE");
        else
            for (int i = 1; i < v.size(); i++) {
                if (v[i].first != v[i - 1].first) {
                    printf("%d", v[i].second);
                    break;
                }
            }
    }
}

int main() {
    input();
    solve();
    return 0;
}
