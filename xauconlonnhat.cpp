//
// Created by Nguyen Van Khanh on 10/31/2021.
//

/*
Xâu con của một xâu ký tự S được tạo ra bằng cách lấy một hoặc nhiều ký tự trong S và giữ nguyên thứ tự ban đầu.

Cho xâu S chỉ bao gồm các chữ cái viết thường. Hãy in ra xâu con có thứ tự từ điển là lớn nhất.

Input

Chỉ có xâu ký tự S, độ dài không quá 100000. Không có khoảng trống.

Output

Ghi ra xâu con có thứ tự từ điển lớn nhất.

Ví dụ

Input

ababba

abbcbccacbbcbaaba

Output

bbba

cccccbba
*/

#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> s;

void input() {
    cin >> str;
}

void solve() {
    char pre = str[str.length() - 1];
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] >= pre) {
            s.push(str[i]);
            pre = str[i];
        }
    }
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
}

int main() {
    input();
    solve();
    return 0;
}
