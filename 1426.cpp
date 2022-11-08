//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
NODE TRUNG GIAN CỦA CÂY NHỊ PHÂN TÌM KIẾM

Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một cây nhị phân tìm kiếm. Hãy đưa ra số các node trung gian của cây ?

Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả là 5 bao gồm các node: 30, 20, 25, 40, 35.                     

     Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số là phép duyệt theo thứ tự trước của cây BST.
     Output:

Đưa ra kết quả mỗi test theo từng dòng.
    Ví dụ:

Input:

Output

2

6

10 5 1 7 40 50

11

30 20 15 25 23 28 40 35 33 38 45

3

5
*/

#include <bits/stdc++.h>

using namespace std;

int n, pre[1005];

void init() { //hàm khởi tạo
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
}

void solve() { //hàm xử lý
    int res = n - 1; //khởi tạo kết quả, do phần tử cuối cùng là lá nên lấy bắt đầu bằng n-1
    stack<int> s;
    for (int i = 0, j = 1; j < n; i++, j++) { //đếm số lá
        if (pre[i] > pre[j]) s.push(pre[i]);
        else {
            bool found = false;
            while (!s.empty()) {
                if (pre[j] > s.top()) {
                    found = true;
                    s.pop();
                } else break;
            }
            if (found) res--; //cập nhật kết quả
        }
    }
    printf("%d\n", res); //đưa ra kết quả
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
    }
    return 0;
}
