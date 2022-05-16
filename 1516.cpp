//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>
using namespace std;

string str1, str2;

string convert(string str) { //hàm chuyển đổi đã làm ở bài DSA07005	BIỂU THỨC TƯƠNG ĐƯƠNG
    stack <int> s;
    string tmp = "";
    for (int i = 0; i < str.length (); i++)
        if (str[i] == '(' && i > 0) s.push (i);
        else if (str[i] == ')' && s.size () > 0) {
            if (str[s.top () - 1] == '-') {
                for (int j = s.top (); j < i; j++) {
                    if (str[j] == '+') str[j] = '-';
                    else if (str[j] == '-') str[j] = '+';
                }
            }
            s.pop ();
        }
    for (int i = 0; i < str.length (); i++)
        if (str[i] != '(' && str[i] != ')') tmp += str[i];
    return tmp;
}

void init(){
    cin >> str1;
    cin >> str2;
}

void solve() { //hàm xử lý
    if (convert (str1) == convert (str2)) cout << "YES" << endl; //đưa ra kết quả
    else cout << "NO" << endl;
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