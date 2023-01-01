//
// Created by Nguyen Van Khanh on 10/24/2021.
//
/*
Cho mảng A[] gồm N số nguyên. Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. Tại mỗi bước, bạn chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta số phép chèn ít nhất là 3 bằng cách lấy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, lấy số 6 chèn trước số 7 ta nhận được mảng được sắp.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1000; 1≤A[i] ≤1000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

1
7
2 3 5 1 4 7 6

Output

3
*/

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1005], dp[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = INT_MIN;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    printf("%d\n", n - res);
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
