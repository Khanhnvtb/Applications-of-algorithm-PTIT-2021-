//
// Created by Khanh Nguyen Van on 10/16/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, a[100005], res[100005];

void init() { //hàm khởi tạo
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve() { //hàm xử lý
    stack <int> s; //ngăn xếp lưu giá chứng khoán
    stack <int> cnt; //ngăn xếp lưu nhịp chứng khoán tương ứng
    res[0] = 1; //ngày đầu tiên luôn có nhịp chứng khoán là 1
    for (long i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) { //nếu ngày hiện tại có giá chứng khoán nhỏ hơn ngày hôm trước
            res[i] = 1; //nhịp chứng khoán hiện tại là 1
            s.push (a[i - 1]); //đưa giá chứng khoán ngày hôm trước vào ngăn xếp
            cnt.push (res[i - 1]); //đưa nhịp chứng khoán ngày hôm trước vào ngăn xếp
        } else { //nếu ngày hiện tại có giá chứng khoán không nhỏ hơn ngày hôm trước
            res[i] = res[i - 1] + 1; //nhịp chứng khoán bằng nhịp chứng khoán của ngày hôm trước cộng 1
            while (!s.empty () && a[i] >= s.top ()) { //so sánh giá chứng khoán của những ngày khác trên ngăn xếp
                res[i] += cnt.top (); //nếu giá chứng khoán lớn hơn cập nhật kết quả
                cnt.pop (); //xoá nhịp chứng khoán ngày vừa duyệt qua
                s.pop (); //xoá giá chứng khoán ngày vừa duyệt qua
            }
        }
    }
    for (long i = 0; i < n; i++) cout << res[i] << " "; //đưa ra kết quả
    cout << endl;
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