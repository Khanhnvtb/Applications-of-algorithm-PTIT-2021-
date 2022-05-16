//
// Created by Nguyen Van Khanh on 10/31/2021.
//

#include <bits/stdc++.h>

using namespace std;

string s1, s2;

void input() {
    getline(cin, s1);
    getline(cin, s2);
}

vector<string> split(string s) {
    vector<string> v;
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(tmp);
            tmp = "";
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            tmp += s[i];
        }
    }
    v.push_back(tmp);
    return v;
}

void solve() {
    vector<string> w1 = split(s1);
    vector<string> w2 = split(s2);
    set<string> uni;
    set<string> inter;
    for (string s: w1) uni.insert(s);
    for (string s: w2)
        if (uni.find(s) != uni.end()) inter.insert(s);
    for (string s: w2) uni.insert(s);
    for (string s: uni) cout << s << " ";
    cout << endl;
    for (string s: inter) cout << s << " ";
}

int main() {
    input();
    solve();
    return 0;
}