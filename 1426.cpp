//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, pre[1005];

void init() { //hàm khởi tạo
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
}

void solve() { //hàm xử lý
    int res = n - 1; //khởi tạo kết quả, do phần tử cuối cùng là lá nên lấy bắt đầu bằng n-1
    stack <int> s;
    for (int i = 0, j = 1; j < n; i++, j++) { //đếm số lá
        if (pre[i] > pre[j]) s.push (pre[i]);
        else {
            bool found = false;
            while (!s.empty ()) {
                if (pre[j] > s.top ()) {
                    found = true;
                    s.pop ();
                } else break;
            }
            if (found) res--; //cập nhật kết quả
        }
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