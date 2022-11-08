//
// Created by khanh on 10/11/2021.
//

/*
BÀI 5. TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN

Cho dãy số A[] gồm N số. Nhiệm vụ của bạn là tìm tổng lớn nhất của dãy con được sắp theo thứ tự tăng dần của dãy A[]. Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có kết quả là 106 = 1 + 2 + 3 + 100. Với dãy A[] = {10, 7, 5} ta có kết quả là 10. Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤103; 0≤A[i] ≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

3

7

1 101 2 3 100 4 5

3

10 7 5

4

1 2 3 5

Output

106

10

11
*/

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1005], dp[1005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
        res = max(res, dp[i]);
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
