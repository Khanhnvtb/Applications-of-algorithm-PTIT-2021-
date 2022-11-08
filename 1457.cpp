//
// Created by khanh on 10/12/2021.
//

/*
BÀI 8. TỔ HỢP C(n, k)

Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
Output: 

Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input

2

5 2

10 3

Output

10

120
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
long dp[1005][1005], m = 1e9 + 7;

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    for (int i = 1; i <= 1000; i++) dp[1][i] = i;
    for (int i = 2; i <= 1000; i++)
        for (int j = 2; j <= i; j++)
            dp[j][i] = (dp[j][i - 1] + dp[j - 1][i - 1]) % m;
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        printf("%ld\n", dp[k][n]);
    }
    return 0;
}
