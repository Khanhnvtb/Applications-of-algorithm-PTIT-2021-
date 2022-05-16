//
// Created by khanh on 10/11/2021.
//

#include <bits/stdc++.h>
using namespace std;
int state, n, x, a[20];

void print(vector<int> res) {
    printf("[");
    for (int k = 0; k < res.size() - 1; k++) printf("%d ", res[k]);
    printf("%d]", res[res.size() - 1]);
}

void Try(int i, int sum, vector <int> res) { //hàm quay lui
    for (int j = 1; j >= 0; j--) {
        if (j == 1) {
            res.push_back (a[i]);  //sử dụng thì đẩy vào mảng kết quả và tăng tổng
            sum += a[i];
            //nếu tổng bằng x đánh dấu đã đúng và in ra kết quả tổng lớn hơn x thì dừng lại và nhỏ hơn x thì thử tiếp
            if (sum == x) {
                state = 1;
                print(res);
                return;
            } else if (sum > x) return; //nếu tổng lớn hơn x thì dừng nhánh
            else Try (i, sum, res); //nếu chưa bằng x thì tiếp tục quay lui
            //trả lại sum và mảng kết quả trước đó để chuyển sang trường hợp không sử dụng
            sum -= a[i];
            res.pop_back ();
        } else {
            if (i < n - 1) Try (i + 1, sum, res); //không sử dụng thì thử tiếp với trường hợp i+1
        }
    }
}

void init() { //hàm khởi tạo
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() { //hàm xử lý
    state = 0;
    vector<int> res;
    Try(0, 0, res);
    if (!state) printf("-1");
    printf("\n");
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