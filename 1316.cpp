//
// Created by khanh on 10/10/2021.
//

/*
LIỆT KÊ TẬP CON
Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự tăng dần của các xâu ký tự.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

1
3

Output

abc

a ab abc ac b bc c
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;

void input() {
    scanf("%d", &n);
    cin >> s;
}

void Try(int i, string str) {
    if (i == n) {
        v.push_back(str);
        return;
    }
    Try(i + 1, str);
    Try(i + 1, str + s[i]);
}

void solve() {
    string str = "";
    Try(0, str);
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
    printf("\n");
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
