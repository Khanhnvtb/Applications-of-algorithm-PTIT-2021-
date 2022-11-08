//
// Created by Nguyen Van Khanh on 11/2/2021.
//

/*
BÀI 1. XÂU CON CHUNG DÀI NHẤT

Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

Ví dụ:

Input

2

AGGTAB

GXTXAYB

AA

BB

Output

4

0

Giải thích test 1: Dãy con chung là G, T, A, B.
*/

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
string a, b;

void input() {
    cin >> a >> b;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    int lena = a.length() - 1;
    int lenb = b.length() - 1;
    for (int i = 0; i <= lena; i++) dp[i][0] = 0;
    for (int i = 0; i <= lenb; i++) dp[0][i] = 0;
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[lena][lenb]);
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
