//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>
using namespace std;

int k;
string str;

void init() {
    cin >> k;
    cin >> str;
}

void solve() {
    for (int i = 0; i < str.length (); i++) {
        int max = str[str.length () - 1], pos = str.length () - 1;
        for (int j = str.length () - 1; j > i; j--) {
            if (str[j] > max) {
                max = str[j];
                pos = j;
            }
        }
        if (max > str[i] && k > 0) {
            swap (str[i], str[pos]);
            k--;
        }
    }
    cout << str << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}