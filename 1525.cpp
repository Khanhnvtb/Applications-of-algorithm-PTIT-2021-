//
// Created by khanh on 10/14/2021.
//

/*
SỐ BDN
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K =  101 là số BDN, k=102 không phải là số BDN.

Số BDN của N là số P =M´N sao cho P là số BDN. Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.

Ví dụ. Với N=2, ta tìm được số BDN của N là P = 5´2=10. N = 17 ta tìm được số BDN của 17 là P = 653´17=11101.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
 
Input


3

2

12

17

Output

10

11100

11101

*/

#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    scanf("%d", &n);
}

bool check(string s) {
    long long tmp = 0;
    for (int i = 0; i < s.length (); i++) {
        tmp = tmp * 10 + (s[i] - 48);
        tmp %= n;
    }
    if (tmp == 0) return true;
    else return false;
}

void solve() {
    queue <string> s;
    s.push ("1");
    while (1) {
        string res = s.front ();
        s.pop ();
        if (check (res)) {
            cout << res << endl;
            break;
        }
        s.push (res + "0");
        s.push (res + "1");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input ();
        solve ();
    }
    return 0;
}
