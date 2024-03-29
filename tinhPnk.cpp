//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
P(n, k) là số phép biểu diễn các tập con có thứ tự gồm k phần tử của tập gồm n phần tử. Số P(n, k) được định nghĩa theo công thức sau:
data:image/png;base64,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

Cho số hai số n, k. Hãy tìm P(n,k) theo modulo 109+7.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số n, k được viết trên một dòng.
T, n, k thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ n,k ≤ 1000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
5 2
4 2

Output

20
12
 
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, m = 1e9 + 7;

void input() {
    scanf("%d %d", &n, &k);
}

void solve() {
    if (k > n) printf("0\n");
    else {
        long res = 1;
        for (int i = n - k + 1; i <= n; i++) {
            res *= i;
            res %= m;
        }
        printf("%ld\n", res);
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
