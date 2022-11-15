//
// Created by Nguyễn Văn Khánh on 11/27/2021.
//

/*
DÃY CON CÓ TỔNG BẰNG S

Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:

Input

2

5 6
1 2 4 3 5

10 15

2 2 2 2 2 2 2 2 2 2

Output

YES

NO
*/

#include <bits/stdc++.h>

using namespace std;

int n, s, a[205], dp[40005];

void input() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i <= s; i++) dp[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = s; j > a[i]; j--)
            dp[j] = dp[j - a[i]];
        if (dp[s] == 1) break;
    }
    if (dp[s]) printf("YES\n");
    else printf("NO\n");
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
