//
// Created by khanh on 10/8/2021.
//

/*
XÂU NHỊ PHÂN TRƯỚC
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2

010101

111111

Output

010100

111110
*/

#include <bits/stdc++.h>

using namespace std;

char s[1005];

void input() {
    scanf("%s", &s);
}

void solve() {
    int i, len = strlen(s);
    for (i = len - 1; i >= 0; i--) {
        if (s[i] == '1') {
            s[i] = '0';
            for (int j = i + 1; j < len; j++) s[j] = '1';
            break;
        }
    }
    if (i == -1) {
        for (i = 0; i < len; i++) printf("%d", 1);
        printf("\n");
    } else printf("%s\n", s);
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
