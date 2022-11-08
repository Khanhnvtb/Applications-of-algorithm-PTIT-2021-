//
// Created by khanh on 10/12/2021.
//

/*
BÀI 7. CON ẾCH

Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.
T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
1
5

Output

1
13
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[55];

void input() {
    scanf("%d", &n);
}

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        if (i > 0) dp[i] += dp[i - 1];
        if (i > 1) dp[i] += dp[i - 2];
        if (i > 2) dp[i] += dp[i - 3];
    }
    printf("%lld\n", dp[n]);
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
