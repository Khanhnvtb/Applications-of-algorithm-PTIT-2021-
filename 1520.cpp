//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>
using namespace std;

int comp( char x ) { //hàm so sánh độ ưu tiên của các toán tử, độ ưu tiên cao thực hiện trước
    if (x == '(') return 1;
    else if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 3;
    else return 4;
}

bool isOperator( char x ) { //hàm kiểm tra toán tử
    if (x == '+' || x == '-' || x == '*' || x == '/') return true;
    return false;
}

string str;

void init() { //hàm khởi tạo
    cin >> str;
}

void solve() { //hàm xử lý
    stack <char> stk;
    string s = "";
    for (int i = 0; i < str.length (); i++) {
        if (isdigit (str[i])) { //nếu là 1 chữ số
            s += str[i]; //thêm nó vào biểu thức hiện tại
            if (i == str.length () - 1 || !isdigit (str[i + 1])) s += '.'; //hết 1 số thì thêm ký tự . để ngắt
        } else if (str[i] == '(') stk.push (str[i]); //thêm ngoặc trái vào ngăn xếp
        else if (str[i] == ')') { //nếu gặp ngoặc phải
            while (stk.size () > 0 && stk.top () != '(') { //kiểm tra xem trước nó có toán hạng không
                s += stk.top (); //thêm các toán hạng vào biểu thức hiện tại
                stk.pop (); //xoá nó khỏi ngăn xếp
            }
            stk.pop (); //xoá dấu ngoặc trái khỏi ngăn xếp
        } else {
            while (stk.size () > 0 && comp (stk.top ()) >= comp (str[i])) { //kiểm tra độ ưu tiên của các toán tử
                s += stk.top (); //thêm toán tử vào biểu thức
                stk.pop ();
            }
            stk.push (str[i]); //thêm toán tử hiện tại vào ngăn xếp
        }
    }
    while (stk.size () > 0 && stk.top () != '(') { //đưa các toán tử còn lại vào biểu thức
        s += stk.top ();
        stk.pop ();
    }
    long val = 0; //tính toán giá trị biểu thức hậu tố
    stack <long> st;
    for (int i = 0; i < s.length (); i++) {
        if (isOperator (s[i])) {
            long x = st.top ();
            st.pop ();
            long y = st.top ();
            st.pop ();
            if (s[i] == '+') st.push (y + x);
            else if (s[i] == '-') st.push (y - x);
            else if (s[i] == '*') st.push (y * x);
            else st.push (y / x);
        } else if (s[i] == '.') {
            st.push (val);
            val = 0;
        } else val = val * 10 + (s[i] - 48);
    }
    cout << st.top () << endl; //đưa ra kết quả
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