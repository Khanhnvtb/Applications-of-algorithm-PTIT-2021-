//
// Created by khanh on 10/13/2021.
//

/*
BÀI 20. TỔNG BÌNH PHƯƠNG
Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52. Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test là một số tự nhiên N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

3
100
6
25

Output

1
3
1
*/

#include <bits/stdc++.h>

using namespace std;

int n, dp[10005];

void input() {
    scanf("%d", &n);
}

void solve() {
    for (int i = 1; i <= 10000; i++) {
        dp[i] = i;
        for (int j = 1; j <= sqrt(i); j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    solve();
    while (t--) {
        input();
        printf("%d\n", dp[n]);
    }
    return 0;
}
