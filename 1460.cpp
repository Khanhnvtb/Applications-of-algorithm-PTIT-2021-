//
// Created by khanh on 10/12/2021.
//

/*
BÀI 11. XÂU ĐỐI XỨNG 1
Cho xâu ký tự str. Nhiệm vụ của bạn là tìm số phép chèn tối thiểu các ký tự vào str để str trở thành xâu đối xứng. Ví dụ: str =”ab” ta có số phép chèn tối thiểu là 1 để trở thành xâu đối xứng “aba” hoặc “bab”. Với xâu str=”aa” thì số phép chèn tối thiểu là 0. Với xâu str=”abcd” có số phép chèn tối thiểu là 3 để trở thành xâu “dcbabcd”

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự được viết trên một dòng
T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str)≤40.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

3
abcd
aba
geeks

Output

3
0

3
*/

#include <bits/stdc++.h>

using namespace std;

string str;
int dp[50][50];

void input() {
    cin >> str;
}

void solve() {
    int n = str.length() - 1;
    memset (dp, 0, sizeof (dp));
    for (int i = 1; i <= n; i++)
        for (int j = 0, k = i; k <= n; j++, k++) {
            if (str[j] == str[k]) dp[j][k] = dp[j + 1][k - 1];
            else dp[j][k] = min(dp[j + 1][k], dp[j][k - 1]) + 1;
        }
    printf("%d\n", dp[0][n]);
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
