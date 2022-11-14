//
// Created by khanh on 10/13/2021.
//

/*
BÀI 18. TỔNG BẰNG K
Cho một mảng A[] gồm N số nguyên và số K. Tính số cách lấy tổng các phần tử của A[] để bằng K. Phép lấy lặp các phần tử hoặc sắp đặt lại các phần tử được chấp thuận. Ví dụ với mảng A[] = {1, 5, 6}, K = 7 ta có 6 cách sau:

7 = 1 + 1 + 1+1 + 1 + 1+1 (lặp số 1 7 lần)

7 = 1 + 1 + 5 (lặp số 1)

7 = 1 + 5 + 1 (lặp và sắp đặt lại số 1)

7 = 1 + 6

7 = 6 + 1

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào N và K; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1000; 1≤A[i]≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Khi kết quả quá lớn đưa ra kết quả dưới dạng modulo với 109+7.
Ví dụ:

Input

2
3 7
1 5 6
4 14
12 3 1 9

Output

6
150
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long k, m = 1e9 + 7, a[1005], dp[1005];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i >= a[j]) dp[i] = (dp[i] + dp[i - a[j]]) % m;
    printf("%ld\n", dp[k]);
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
