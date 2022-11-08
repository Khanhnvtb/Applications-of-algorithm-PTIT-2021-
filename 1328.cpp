//
// Created by khanh on 10/13/2021.
//

/*
LŨY THỪA MA TRẬN

Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) là kích thước của ma trận và số mũ.

Output: 

Với mỗi test, in ra kết quả của ma trận X.

Ví dụ:

Input:

2

2 5

1 1

1 0

3 1000000000

1 2 3

4 5 6

7 8 9

8 5

5 3

Output

597240088 35500972 473761863

781257150 154135232 527013321

965274212 272769492 580264779
*/

#include <bits/stdc++.h>

using namespace std;

long long m = 1e9 + 7, a[10][10], s[10][10];
int n, k;

void mul(long long a[][10], long long b[][10]) {
    long long ans[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                ans[i][j] += a[i][k] * b[k][j] % m;
                ans[i][j] %= m;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = ans[i][j];
}

void power(long long a[][10], int k) {
    if (k == 1) return;
    power(a, k / 2);
    mul(a, a);
    if (k % 2 == 1) mul(a, s);
}

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%lld", &s[i][j]);
            a[i][j] = s[i][j];
        }
}

void solve() {
    power(a, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
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
