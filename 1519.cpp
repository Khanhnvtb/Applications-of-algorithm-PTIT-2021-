//
// Created by khanh on 10/14/2021.
//

/*
TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ

Hãy viết chương trình tính toán giá trị của biểu thức tiền tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
Output:

Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
Ví dụ:

Input

2

-+8/632

-+7*45+20

Output

8

25
*/

#include <bits/stdc++.h>
using namespace std;

string str;

void init() { //hàm khởi tạo
    cin >> str;
}

void solve() { //hàm xử lý
    stack <int> s;
    for (int i = str.length () - 1; i >= 0; i--) {
        //nếu gặp toán tử thực hiện phép toán tương ứng rồi thêm kết quả vào stack
        if (str[i] == '+') {
            int x = s.top ();
            s.pop ();
            int y = s.top ();
            s.pop ();
            s.push (x + y);
        } else if (str[i] == '-') {
            int x = s.top ();
            s.pop ();
            int y = s.top ();
            s.pop ();
            s.push (x - y);
        } else if (str[i] == '*') {
            int x = s.top ();
            s.pop ();
            int y = s.top ();
            s.pop ();
            s.push (x * y);
        } else if (str[i] == '/') {
            int x = s.top ();
            s.pop ();
            int y = s.top ();
            s.pop ();
            s.push (x / y);
        } else s.push ((int) (str[i] - '0')); //nếu gặp toán hạng thêm toán hạng vào stack
    }
    cout << s.top () << endl;
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
