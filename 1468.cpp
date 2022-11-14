//
// Created by khanh on 10/13/2021.
//

/*
BÀI 19. GIẢI MÃ
Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
123
2563

Output

3
2
*/

#include <bits/stdc++.h>

using namespace std;

char s[45];
int dp[45];

void input() {
    scanf("%s", &s);
}

void solve() {
    if (s[0] == '0') printf("0\n");
    else {
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= strlen(s); i++) {
            dp[i] = 0;
            int prev = i - 2;
            int curr = i - 1;
            if (s[curr] > '0') dp[i] = dp[curr];
            if (s[prev] == '1' || (s[prev] == '2' && s[curr] < '7')) dp[i] += dp[prev];
        }
        printf("%d\n", dp[strlen(s)]);
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
