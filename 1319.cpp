//
// Created by khanh on 10/10/2021.
//
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
