//
// Created by khanh on 10/11/2021.
//

/*
DÃY CON LẶP LẠI DÀI NHẤT
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm độ dài dãy con lặp lại dài nhất trong S. Dãy con có thể chứa các phần tử không liên tiếp nhau.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu str; dòng tiếp theo đưa vào xâu S.
T, str thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(S) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
3
abc

5
axxxy

Output

0
2
*/

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005][1005];
string a;

void input() {
    scanf("%d", &n);
    cin >> a >> b >> c;
}

void solve() {
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    for (int i = 0; i <a.length(); i++) dp[i][0][0] = 0;
    for (int i = 0; i <b.length(); i++) dp[0][i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i] == a[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
        }
    printf("%d\n", res);
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
