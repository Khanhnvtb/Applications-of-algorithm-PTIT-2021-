//
// Created by Nguyen Van Khanh on 11/6/2021.
//

/*
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
Output:

Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.
 Ví dụ:

Input

2

2

3

Output

6

88 86 68 66 8 6

14

888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    stack<string> s;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (1) {
        string tmp = q.front();
        if (tmp.length() > n) break;
        s.push(tmp);
        q.pop();
        q.push(tmp + '6');
        q.push(tmp + '8');
    }
    printf("%d\n", s.size());
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        printf(" ");
    }
    printf("\n");
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
