//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input

Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output

Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.

Ví dụ

Input

D 2

Output

AA

AB

AC

AD

BB

BC

BD

CC

CD

DD
*/

#include <bits/stdc++.h>

using namespace std;

char c, a[15];
int k;

void input() {
    scanf("%c %d", &c, &k);
}

void print() {
    for (int i = 0; i <= k; i++) printf("%c", a[i]);
    printf("\n");
}

void Try(int i, char x) {
    for (int j = x; j <= c; j++) {
        a[i] = j;
        if (i == k) print();
        else Try(i + 1, j);
    }
}

void solve() {
    k--;
    Try(0, 'A');
}

int main() {
    input();
    solve();
    return 0;
}
