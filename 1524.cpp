//
// Created by khanh on 10/14/2021.
//

/*
GIÁ TRỊ NHỎ NHẤT CỦA XÂU
Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất hiện mỗi ký tự trong xâu. Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 32 + 22 + 12 + 12 = 15. Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại số K. Dòng thứ 2 ghi lại xâu ký tự S[] có độ dài không vượt quá 10^6.
Output:

Đưa ra giá trị nhỏ nhất của mỗi test theo từng dòng.
Input

2

0

ABCC

1

ABCC

Output

6

3
*/

#include <bits/stdc++.h>
using namespace std;

int k, cnt[30];
string str;
priority_queue <int> q;


void init() { //hàm khởi tạo
    cin >> k;
    cin >> str;
}

void solve() { //hàm xử lý
    memset (cnt, 0, sizeof (cnt)); //làm mới mảng đếm
    long long res = 0;
    for (int i = 0; i < str.length (); i++) cnt[str[i] - 'A']++; //đếm số lần xuất hiện của các phần tử
    for (int i = 0; i < 26; i++)
        if (cnt[i]) q.push (cnt[i]); //đẩy số lần xuất hiện của các phần tử vào hàng đợi
    while (k--) {
        int tmp = q.top () - 1; //thực hiện trừ
        q.pop ();
        q.push (tmp);
    }
    while (!q.empty ()) {
        res += pow (q.top (), 2); //cập nhật kết quả
        q.pop ();
    }
    cout << res << endl; //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
