//
// Created by Nguyen Van Khanh on 10/26/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, k;
long  dp[1001][1001], m=1e9+7;

void init() {
    cin >> n >> k;
}

void solve() { //hàm xử lý
    //tìm tất cả các tổ hợp trong phạm vi
    for (int i = 1; i <= 1000; i++) dp[1][i] = i; //tổ hợp chập 1 của i luôn bằng i
    for (int i = 2; i <= 1000; i++)
        for (int j = 2; j <= i; j++)
            dp[j][i] = (dp[j][i - 1] + dp[j - 1][i - 1]) % m; //tính tổ hợp chập j của i dựa vào tính chất của tổ hợp
}

int main() {
    int t;
    cin >> t;
    solve ();
    while (t--) {
        init ();
        cout << dp[k][n] << endl; //đưa ra kết quả
    }
    return 0;
}