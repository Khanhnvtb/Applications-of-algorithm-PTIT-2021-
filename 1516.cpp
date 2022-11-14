//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
SO SÁNH BIỂU THỨC
Cho P1, P2 là hai biểu thức đúng chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’ và các toán hạng in thường. Nhiệm vụ của bạn là định xem P1 và P2 có giống nhau hay không.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào P1, dòng tiếp theo đưa vào P2.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P) ≤100.
Ví dụ:

 

Input

2
-(a+b+c)
-a-b-c
a-b-(c-d)
a-b-c-d

Output

YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

string str1, str2;

string convert(string str) {
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
