//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.

Input

Dòng đầu ghi số N (1 < N < 9)

Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

Output

Ghi mỗi hoán vị của dãy số trên một dòng

Ví dụ

Input

3

88 77 99

Output

77 88 99

77 99 88

88 77 99

88 99 77

99 77 88

99 88 77
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[10], used[10] = {0}, res[10];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void print() {
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
}

void Try(int i) {
    if (i == n) print();
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            res[i] = a[j];
            Try(i + 1);
            used[j] = 0;
        }
    }
}

void solve() {
    sort(a, a + n);
    Try(0);
}

int main() {
    input();
    solve();
    return 0;
}
