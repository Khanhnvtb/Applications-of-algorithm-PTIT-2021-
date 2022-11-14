//
// Created by khanh on 10/13/2021.
//

/*
BÀI 16. KÝ TỰ GIỐNG NHAU
Giả sử bạn cần viết N ký tự giống nhau lên màn hình. Bạn chỉ được phép thực hiện ba thao tác dưới đây với chi phí thời gian khác nhau:

Thao tác insert: chèn một ký tự với thời gian là X.
Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.
Thao tác copying: copy và paste tất cả các ký tự đã viết để số ký tự được nhân đôi với thời gian là Z.
Hãy tìm thời gian ít nhất để có thể đưa ra màn hình N ký tự giống nhau. Ví dụ với N = 9, X =1, Y = 2, Z =1 ta có kết quả là 5 bằng cách thực hiện: insert, insert, copying, copying, insert.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số các ký tự giống nhau cần viết lên màn hình; dòng tiếp theo đưa vào bộ ba số X, Y, Z tương ứng với thời gian thực hiện ba thao tác; các số được viết cách nhau một vài khoảng trống.
T, N, X, Y, Z thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 1≤X, Y, Z ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
9
1 2 1
10
2 5 4

Output

5
14
*/

#include <bits/stdc++.h>

using namespace std;

int n, ins, del, cop, dp[105];

void input() {
    scanf("%d", &n);
    scanf("%d %d %d", &ins, &del, &cop);
}

void solve() {
    dp[1] = ins;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i - 1] + ins, dp[i / 2] + cop);
        else dp[i] = min(dp[i - 1] + ins, dp[(i + 1) / 2] + cop + del);
    }
    printf("%d\n", dp[n]);
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
