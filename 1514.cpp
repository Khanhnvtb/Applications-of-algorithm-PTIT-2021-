//
// Created by khanh on 10/13/2021.
//

/*
SỬA LẠI DÃY NGOẶC

Bài làm tốt nhất
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input:

4

))((

((((

(((())

)(())(((

Output

2

2

1

3
*/

#include <bits/stdc++.h>

using namespace std;

string str;

void input() {
    cin >> str;
}

void solve() {
    stack<char> s1;
    stack<char> s2;
    for (int i = 0; i < str.length(); i++) {
        if (s1.empty() && str[i] == ')') {
            s2.push(')');
            s1.push('(');
        } else if (!s1.empty() && str[i] == ')') s1.pop();
        else s1.push('(');
    }
    printf("%d\n", s2.size() + s1.size() / 2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}
