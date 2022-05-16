//
// Created by khanh on 10/14/2021.
//

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