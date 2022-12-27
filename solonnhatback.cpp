//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Cho hai số nguyên N và K, trong đó N không quá 107, K không quá 10. 

Số lớn nhất bậc K của N được định nghĩa là giá trị lớn nhất có thể sau khi thực hiện nhiều nhất K lần các chữ số của N. Ví dụ K =3 và N = “1234567” ta số lớn nhất bậc K của N là “7654321”.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T≤100; 0≤K≤10; 1≤lengh(S)≤7.
Output:

Đưa ra số lớn nhất bậc K của N trên một dòng.
Ví dụ:

Input

3
4
1234567
3
3435335
2
1034

Output

7654321
5543333
4301
*/

#include <bits/stdc++.h>
using namespace std;

int k;
string str;

void init() {
    cin >> k;
    cin >> str;
}

void solve() {
    for (int i = 0; i < str.length (); i++) {
        int max = str[str.length () - 1], pos = str.length () - 1;
        for (int j = str.length () - 1; j > i; j--) {
            if (str[j] > max) {
                max = str[j];
                pos = j;
            }
        }
        if (max > str[i] && k > 0) {
            swap (str[i], str[pos]);
            k--;
        }
    }
    cout << str << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
