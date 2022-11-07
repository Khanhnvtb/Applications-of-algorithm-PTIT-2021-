//
// Created by khanh on 10/10/2021.
//

/*
ĐỔI CHỖ CÁC CHỮ SỐ
Cho số tự nhiên K và xâu ký tự các chữ số S.  Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. Ví dụ K =3 và S = “1234567” ta được “7654321”.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
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
    scanf("%d", &k);
    cin >> str;
}

void solve() {
    for (int i = 0; i < str.length(); i++) { //bắt đầu đổi chỗ từ phần tử đầu
        //khởi tạo giá trị và vị trí lớn nhất hiện tại là phần tử cuối cùng
        int max = str[str.length() - 1], pos = str.length() - 1;
        for (int j = str.length() - 1; j > i; j--) {
            if (str[j] > max) {  //tìm được giá trị lớn hơn thì cập nhật giá trị và vị trí
                max = str[j];
                pos = j;
            }
        }
        //nếu giá trị đó lớn hơn giá trị đang chờ đổi chỗ và k > 0 thì thực hiện đổi chỗ và giảm k
        if (max > str[i] && k > 0) {
            swap(str[i], str[pos]);
            k--;
        }
    }
    cout << str << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
