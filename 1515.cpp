//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>
using namespace std;

string str;

void init(){
    cin >> str;
}

void solve() {
    stack <int> s;
    for (int i = 0; i < str.length (); i++)
        if (str[i] == '(' && i > 0) s.push (i); //thêm vào vị trí của dấu (, dấu ( ở đầu không có nghĩa
        else if (str[i] == ')' && !s.empty ()) { //nếu gặp dấu ) mà trước nó có dấu (
            if (str[s.top () - 1] == '-') { //kiểm tra xem trước dấu ( có phải dấu - không
                for (int j = s.top (); j < i; j++) { //nếu là dấu -
                    if (str[j] == '+') str[j] = '-'; //đổi dấu tất cả các dấu trong khoảng ngoặc
                    else if (str[j] == '-') str[j] = '+';
                }
            }
            s.pop (); //xoá đi dấu ngoặc đã xử lý rồi
        }
    for (int i = 0; i < str.length (); i++) //đưa ra kết quả
        if (str[i] != '(' && str[i] != ')') cout << str[i];
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore ();
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}