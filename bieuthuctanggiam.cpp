//
// Created by Nguyen Van Khanh on 11/6/2021.
//

/*
Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

A[] = “I”               : số tăng nhỏ nhất là 12.
A[] = “D”              : số giảm nhỏ nhất là 21
A[] =”DD”            : số giảm nhỏ nhất là 321
A[] = “DDIDDIID”: số thỏa mãn 321654798
Input: Dòng đầu tiên đưa vào số lượng bộ test T.  Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu S. T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .

Output: Đưa ra thứ tự bộ test và kết quả mỗi test theo từng dòng.

Ví dụ:

Input:

4

I

D

DD
DDIDDIID

Output:

Test 1: 12

Test 2: 21

Test 3: 321

Test 4: 321654798
*/

#include <bits/stdc++.h>

using namespace std;

string s;

void input() {
    cin >> s;
}

void solve(int t) {
    stack<int> st;
    printf("Test %d: ", t);
    for (int i = 0; i <= s.length(); i++) {
        st.push(i + 1);
        if (s[i] == 'I' || i == s.length()) {
            while (!st.empty()) {
                printf("%d", st.top());
                st.pop();
            }
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
