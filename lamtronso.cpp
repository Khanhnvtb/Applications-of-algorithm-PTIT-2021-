//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>

using namespace std;

char s[10];

void input() {
    scanf("%s", &s);
}

void solve() {
    int len = strlen(s) - 1;
    char state = s[len];
    for (int i = len - 1; i >= 0; i--) {
        if (state >= '5') {
            state = s[i] + 1;
            if (state == 58) {
                state = '0';
                if (i == 0) printf("1");
                else s[i - 1]++;
            }
        } else state = s[i];
    }
    printf("%c", state);
    for (int i = 0; i < len; i++) printf("0");
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
