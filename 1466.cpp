//
// Created by khanh on 10/13/2021.
//

/*
BÀI 17. TỔNG CÁC XÂU CON

Cho số nguyên dương N được biểu diễn như một xâu ký tự số. Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1012.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
1234
421

Output

1670
491
*/

#include <bits/stdc++.h>

using namespace std;

string s;
long res;

void input() {
    cin >> s;
}

long long toInt(string n) {
    long long val = 0;
    for (int i = 0; i < n.length(); i++)
        val = val * 10 + n[i] - 48;
    return val;
}

void solve() {
    res = 0;
    for (int i = 1; i <= s.length(); i++)
        for (int j = 0; j <= s.length() - i; j++) {
            string n = "";
            for (int k = j; k < j + i; k++)
                n += s[k];
            res += toInt(n);
        }
    printf("%lld\n", res);
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
