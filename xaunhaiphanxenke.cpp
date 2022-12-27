//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Một xâu nhị phân được gọi là xen kẽ nếu giá trị 0 ở ngay bên cạnh giá trị 1 và không có hai giá trị nào bằng nhau ở cạnh nhau. Hãy viết chương trình liệt kê các xâu nhị phân xen kẽ có độ dài N.

Input

Chỉ có một dòng ghi số N (2 ≤ N ≤ 1000)

Output

Ghi ra các xâu nhị phân xen kẽ, mỗi xâu trên một dòng.

Ví dụ

Input

3

Output

0 1 0

1 0 1
*/

#include <bits/stdc++.h>

using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) printf("0 ");
        else printf("1 ");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) printf("1 ");
        else printf("0 ");
    }
}

int main() {
    input();
    solve();
    return 0;
}
