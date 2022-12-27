//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Số lượng máy tính ở các phòng thực hành nhà A3 tăng lên nhanh chóng. Để gán mã cho các máy tính của PTIT người ta sử dụng mã gồm 2*N ký tự, trong đó:

N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A.
N ký tự tiếp theo là các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau).
Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

Input

Chỉ có duy nhất số N (1 < N < 6)

Output

Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng

Ví dụ

Input

2

Output

AB11

AB12

AB21

AB22

BA11

BA12

BA21

BA22
*/

#include <bits/stdc++.h>

using namespace std;

int n, used[100] = {0};
vector<string> v;
char a[10], c[10];

void print() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < n; j++) cout << c[j];
        cout << v[i] << endl;
    }
}

void TryA(int i) {
    for (int j = '1'; j <= n + 48; j++) {
        a[i] = j;
        if (i == n - 1) {
            string s = "";
            for (int k = 0; k < n; k++)
                s += a[k];
            v.push_back(s);
        } else TryA(i + 1);
    }
}

void TryC(int i) {
    for (int j = 'A'; j < n + 65; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            c[i] = j;
            if (i == n - 1) {
                print();
            } else TryC(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    TryA(0);
    TryC(0);
    return 0;
}
