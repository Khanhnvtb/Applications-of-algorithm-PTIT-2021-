//
// Created by khanh on 10/12/2021.
//

/*
BÀI 14. CÁI TÚI

Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

Input

Dòng đầu ghi số bộ test T (T<10)
Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
Output

Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
Ví dụ

Input

1

15 10

5 2 1 3 5 2 5 8 9 6 3 1 4 7 8

1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

Output

15
*/

#include <bits/stdc++.h>

using namespace std;

int v, n, a[1005], c[1005], dp[1005][1005];

void input() {
    scanf("%d %d", &n, &v);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
}

void solve() {
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            if (a[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", dp[n][v]);
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
