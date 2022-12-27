//
// Created by Nguyen Van Khanh on 10/31/2021.
//

/*
Trong lập trình cơ bản, một từ được hiểu là một dãy ký tự liên tiếp không chứa khoảng trống, dấu tab hoặc dấu xuống dòng.


Hãy xác định tập hợp các từ khác nhau trong một xâu ký tự, sau khi đã chuyển hết về dạng chữ thường. Sau đó nhập hai dòng ký tự và hiển thị hợp và giao của hai tập từ tương ứng.

Input

Chỉ có 2 dòng, mỗi dòng có độ dài không quá 1000 ký tự.

Output

Dòng 1 ghi hợp của 2 tập từ theo thứ tự từ điển

Dòng 2 ghi giao của 2 tập từ theo thứ tự từ điển.

Ví dụ

Input

Lap trinh huong doi tuong

Ngon ngu lap trinh C++

Output

c++ doi huong lap ngon ngu trinh tuong

lap trinh
*/

#include <bits/stdc++.h>

using namespace std;

string s1, s2;

void input() {
    getline(cin, s1);
    getline(cin, s2);
}

vector<string> split(string s) {
    vector<string> v;
    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(tmp);
            tmp = "";
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            tmp += s[i];
        }
    }
    v.push_back(tmp);
    return v;
}

void solve() {
    vector<string> w1 = split(s1);
    vector<string> w2 = split(s2);
    set<string> uni;
    set<string> inter;
    for (string s: w1) uni.insert(s);
    for (string s: w2)
        if (uni.find(s) != uni.end()) inter.insert(s);
    for (string s: w2) uni.insert(s);
    for (string s: uni) cout << s << " ";
    cout << endl;
    for (string s: inter) cout << s << " ";
}

int main() {
    input();
    solve();
    return 0;
}
