//
// Created by Khanh Nguyen Van on 10/16/2021.
//

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