//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
BIỂU THỨC TƯƠNG ĐƯƠNG
Cho biểu thức đúng P chỉ bao gồm các phép toán +, -, các toán hạng cùng với các ký tự ‘(’, ‘)’. Hãy bỏ tất cả các ký tự ‘(’, ‘)’ trong P để nhận được biểu thức tương đương. Ví dụ với P = a – (b + c) ta có kết quả P = a – b – c .

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P)≤103.
Ví dụ:

Input

2
a–(b+c)
a-(b-c-(d+e))-f

Output

a-b-c
a-b+c+d+e-f
*/

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
