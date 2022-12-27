//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

2
4
1 5 11 5
3
1 3 5 

Output

YES
NO

*/
#include <bits/stdc++.h>

using namespace std;

int n, a[105], s;
string res;

void input() {
    s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
}

void Try(int i, int sum) {
    if (res == "YES") return;
    if (i == n) return;
    if (sum == s) {
        res = "YES";
        return;
    }
    if (sum > s) return;
    Try(i + 1, sum + a[i]);
    Try(i + 1, sum);
}

void solve() {
    res = "NO";
    if (s % 2 == 0) {
        s /= 2;
        Try(0, 0);
    }
    cout << res << endl;
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
