//
// Created by Nguyen Van Khanh on 10/29/2021.
//

/*
NHÀ KHÔNG KỀ NHAU
Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N là số lượng ngôi nhà; dòng tiếp theo đưa vào N số là tài sản tương ứng trong mỗi ngôi nhà; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
6
5 5 10 100 10 5
4
3 2 7 10

Output

110
13
*/

#include <bits/stdc++.h>

using namespace std;

int n, res, a[1000005], dp[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    res = INT_MIN;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3]) + a[i];
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
