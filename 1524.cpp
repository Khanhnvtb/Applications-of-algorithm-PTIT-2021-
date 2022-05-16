//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>
using namespace std;

int k, cnt[30];
string str;
priority_queue <int> q;


void init() { //hàm khởi tạo
    cin >> k;
    cin >> str;
}

void solve() { //hàm xử lý
    memset (cnt, 0, sizeof (cnt)); //làm mới mảng đếm
    long long res = 0;
    for (int i = 0; i < str.length (); i++) cnt[str[i] - 'A']++; //đếm số lần xuất hiện của các phần tử
    for (int i = 0; i < 26; i++)
        if (cnt[i]) q.push (cnt[i]); //đẩy số lần xuất hiện của các phần tử vào hàng đợi
    while (k--) {
        int tmp = q.top () - 1; //thực hiện trừ
        q.pop ();
        q.push (tmp);
    }
    while (!q.empty ()) {
        res += pow (q.top (), 2); //cập nhật kết quả
        q.pop ();
    }
    cout << res << endl; //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}