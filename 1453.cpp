//
// Created by khanh on 10/11/2021.
//

/*
BÀI 4. DÃY CON TĂNG DÀI NHẤT

Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. 

Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]

thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].

Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 

Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 

Output: Ghi ra độ dài của dãy con tăng dài nhất.

Ví dụ:

Input

6

1 2 5 4 6 2

Output

4
*/

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1005], dp[1005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}

int main() {
    input();
    solve();
    return 0;
}
