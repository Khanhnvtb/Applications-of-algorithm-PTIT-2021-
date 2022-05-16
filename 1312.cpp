//
// Created by khanh on 10/8/2021.
//

#include <bits/stdc++.h>

using namespace std;

char s[1005];

void input() {
    scanf("%s", &s);
}

void solve() {
    int i, len = strlen(s);
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            s[i] = '0';
            for (int j = i + 1; j < len; j++) s[j] = '1';
            break;
        }
    }
    if (i == -1) {
        for (i = 0; i < len; i++) printf("%d", 1);
        printf("\n");
    } else printf("%s\n", s);
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