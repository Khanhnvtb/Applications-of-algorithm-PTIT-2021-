//
// Created by khanh on 10/11/2021.
//

/*
DÃY CON LẶP LẠI DÀI NHẤT
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm độ dài dãy con lặp lại dài nhất trong S. Dãy con có thể chứa các phần tử không liên tiếp nhau.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu str; dòng tiếp theo đưa vào xâu S.
T, str thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(S) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
3
abc

5
axxxy

Output

0
2
*/

#include <bits/stdc++.h>

using namespace std;

int n, dp[105][105]; //mảng dp lưu trữ giá trị dãy con lặp lại dài nhất với độ dài 2 xâu con là i và j
string str;

void init() { //hàm khởi tạo
    scanf("%d", &n);
    cin >> str;
}

void solve() { //hàm xử lý
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0; //dãy lặp dài nhất của xâu rỗng là 0
            else if (str[i - 1] == str[j - 1] && i != j) dp[i][j] = dp[i - 1][j - 1] + 1; //cập nhật kết quả
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    printf("%d\n", dp[n][n]); //đưa ra kết quả
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
    }
    return 0;
}
