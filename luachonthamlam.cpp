//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
Cho hai số nguyên dương N và S. Hãy lựa chọn các chữ số phù hợp để tạo ra số nhỏ nhất và số lớn nhất có N chữ số sao cho tổng chữ số đúng bằng S.

Input

Chỉ có một dòng ghi hai số N và S. (0 < N <= 100; 0 <= S <= 900)

Output

Ghi ra hai số nhỏ nhất và lớn nhất tìm được, cách nhau một khoảng trống.

Nếu không thể tìm được thì ghi ra “-1 -1”

Ví dụ

Input

3 20

299 992

2 900

Output

-1 -1

3 0

-1 -1
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int s, m;
    cin >> s >> m;
    if (m / 9 > s) cout << "-1 -1" << "\n";
    else if (m / 9 == s) {
        if (m % 9 == 0) {
            for (int i = 1; i <= s; i++) cout << "9";
            cout << " ";
            for (int i = 1; i <= s; i++) cout << "9";
        } else cout << "-1 -1" << "\n";
    } else if (m / 9 < s && m != 0) {
        if (m % 9 == 0) {
            cout << "1";
            for (int i = 1; i < s - m / 9; i++) cout << "0";
            cout << "8";
            for (int i = 1; i < m / 9; i++) cout << "9";
            cout << " ";
            for (int i = 0; i < m / 9; i++) cout << "9";
            for (int i = 0; i < s - m / 9; i++) cout << "0";
        } else {
            if (s - m / 9 == 1) {
                cout << m % 9;
                for (int i = 0; i < m / 9; i++) cout << "9";
                cout << " ";
                for (int i = 0; i < m / 9; i++) cout << "9";
                cout << m % 9;
            } else {
                cout << "1";
                for (int i = 1; i < s - m / 9 - 1; i++) cout << "0";
                cout << m % 9 - 1;
                for (int i = 1; i <= m / 9; i++) cout << "9";
                cout << " ";
                for (int i = 0; i <= m / 9 - 1; i++) cout << "9";
                cout << m % 9;
                for (int i = 1; i < s - m / 9; i++) cout << "0";
            }
        }
    } else if (m == 0 && m / 9 < s) cout << "-1 -1" << "\n";
    return 0;
}
