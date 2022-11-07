//
// Created by khanh on 10/8/2021.
//

/*
XÂU NHỊ PHÂN KẾ TIẾP
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[]. Ví dụ X[] =”010101” thì xâu nhị phân tiếp theo của X[] là “010110”.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

Output

2

010101

111111

010110

000000
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
        if (s[i] == '0') {
            s[i] = '1';
            for (int j = i + 1; j < len; j++) s[j] = '0';
            break;
        }
    }
    if (i == -1) {
        for (i = 0; i < len; i++) printf("%d", 0);
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
