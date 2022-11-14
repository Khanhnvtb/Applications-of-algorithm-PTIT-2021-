//
// Created by khanh on 10/12/2021.
//

/*
BÀI 13. XEM PHIM

John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input:

Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách
Dòng 2..N+1:   Ghi lần lượt các số nguyên: w[i]
Output:

Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
Ví dụ:

Input

259 5

81

58

42

33

61

Output

242

*/

#include <bits/stdc++.h>

using namespace std;

int c, n, a[105], dp[105][25005];

void input() {
    scanf("%d %d", &c, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i] < j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    printf("%d", dp[n][c]);
}

int main() {
    input();
    solve();
    return 0;
}
