//
// Created by khanh on 10/13/2021.
//

/*
BÀI 22. ĐƯỜNG ĐI NHỎ NHẤT

Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).
Output: 

Với mỗi test, in ra độ dài dãy con tăng dài nhất trên một dòng.
Ví dụ:

Input

1

3 3

1 2 3

4 8 2

1 5 3

Output

8
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a[1005][1005], dp[1005][1005];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
}

void solve() {
    for (int i = 0; i <= n; i++) dp[i][0] = INT_MAX;
    for (int j = 0; j <= m; j++) dp[0][j] = INT_MAX;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + a[i][j];
    printf("%d\n", dp[n][m]);
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
