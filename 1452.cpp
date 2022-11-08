//
// Created by khanh on 10/11/2021.
//

/*
DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU
Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X; dòng tiếp theo đưa vào ba xâu X, Y, Z.
T, X, Y, Z thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2

5 8 13

geeks geeksfor geeksforgeeks

7 6 5

abcd1e2 bc12ea bd1ea

Output

5

3
*/

#include <bits/stdc++.h>

using namespace std;

int dp[105][105][105];
int lena, lenb, lenc;
string a, b, c;

void input() {
    scanf("%d %d %d", &lena, &lenb, &lenc);
    cin >> a >> b >> c;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    dp[0][0][0] = 0;
    for (int i = 1; i <= lena; i++)
        for (int j = 1; j <= lenb; j++)
            for (int k = 1; k <= lenc; k++)
                if (a[i] == b[j] && b[j] == c[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
    printf("%d\n", dp[lena][lenb][lenc]);
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

