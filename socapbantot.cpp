//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> hm;
map<int, vector<int>>::iterator it;

int main() {
    int n, k;
    string s;
    scanf("%d %d", &n, &k);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        hm[s.length()].push_back(i);
    }
    for (it = hm.begin(); it != hm.end(); it++) {
        vector<int> v = it->second;
        for (int i = 1; i < v.size(); i++) {
            int inDex = i - (lower_bound(v.begin(), v.begin() + i, v[i] - k) - v.begin());
            res += inDex;
        }
    }
    printf("%lld\n", res);
    return 0;
}