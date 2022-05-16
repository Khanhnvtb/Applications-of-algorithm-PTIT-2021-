//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>
using namespace std;

string str;

int comp(char x) { //hàm so sánh mức độ ưu tiên của phần tử
    if (x == '(') return 1;
    else if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 3;
    else return 4;
}

void init() { //hàm khởi tạo
    cin >> str;
}

void solve() { //hàm xử lý
    stack <char> s; //ngăn xếp lưu chữ các phần tử
    for (int i = 0; i < str.length (); i++) {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) cout << str[i]; //gặp toán hạng in luôn
        else if (str[i] == '(') s.push (str[i]); //nếu gặp dấu ( đẩy vào stack
        else if (str[i] == ')') { //nếu gặp dấu ) tức là đã hết 1 biểu thức con
            while (!s.empty () && s.top () != '(') {
                cout << s.top (); //in ra toán tử tương ứng
                s.pop ();
            }
            s.pop (); //xoá dấu ( do đã in ra biểu thức con tương ứng rồi
        } else {
            while (!s.empty () && comp (s.top ()) >= comp (str[i])) { //kiểm tra mức độ ưu tiên
                cout << s.top (); //toán tử nào có độ ưu tiên cao hơn thì in trước
                s.pop ();
            }
            s.push (str[i]); //đẩy toán tử hiện tại vào stack
        }
    }
    while (!s.empty ()  && s.top () != '(') { //in ra nốt các toán tử còn lại
        cout << s.top ();
        s.pop ();
    }
    cout << endl;
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