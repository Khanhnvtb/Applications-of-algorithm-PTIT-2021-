//
// Created by khanh on 10/14/2021.
//

/*
TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ
Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức hậu tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
Output:

Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
Ví dụ:

Input

2

231*+9–

875*+9-

Output

-4

34
*/

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    cin >> str;
}

void solve() {
    stack<int> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y + x);
        } else if (str[i] == '-') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y - x);
        } else if (str[i] == '*') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(x * y);
        } else if (str[i] == '/') {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(y / x);
        } else s.push(str[i] - '0');
    }
    printf("%d\n", s.top());
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        input();
        solve();
    }
    return 0;
}
