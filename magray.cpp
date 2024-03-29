//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100. Hãy viết chương trình liệt kê các mã Gray có độ dài n.

Input: Dòng đầu tiên là số lượng test T. T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một số tự nhiên n. T, n thỏa mãn ràng buộc: 1≤T, n≤10.

Output: Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input:

2

3

4

Output:

000 001 011 010 110 111 101 100

0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[10];

void input() {
    scanf("%d", &n);
}

void print() {
    printf("%d", a[0]);
    for (int i = 1; i <= n; i++) {
        if (a[i] + a[i - 1] == 1)printf("1");
        else printf("0");
    }
    printf(" ");
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) print();
        else Try(i + 1);
    }

}

void solve() {
    n--;
    Try(0);
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
