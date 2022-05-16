//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>
using namespace std;

struct data { //kiểu dữ liệu data
    long long val;
    int cntSon;
};

int n, father[200005];
data a[200005];

void init() { //hàm khởi tạo
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> father[i];
}

void solve() { //hàm xử lý
    for (int i = 1; i <= n; i++) {
        a[i].cntSon = 1; //gán tất cả đều có 1 con
        a[i].val = 0; //gán giá trị dinh dưỡng hiện tại bằng 0
    }
    for (int i = n; i >= 1; i--) { //bắt đầu cập nhật kết quả
        a[i].val += a[i].cntSon; //giá trị dinh dưỡng được thêm bởi số con
        a[father[i]].cntSon += a[i].cntSon; //cập nhật số con
        a[father[i]].val += a[i].val; //giá trị dinh dưỡng bằng giá trị dinh dưỡng của các con gửi lên
    }
    for (int i = 1; i <= n; i++) cout << a[i].val << " "; //đưa ra kết quả
}

int main() {
    init ();
    solve ();
    return 0;
}