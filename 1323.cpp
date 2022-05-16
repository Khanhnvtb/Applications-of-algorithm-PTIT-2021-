//
// Created by khanh on 10/11/2021.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> a; //tạo 1 vector a lưu các chữ số của n
long long res;
string str;

void Try(int i, long long sum) { //hàm quay lui
    for (int j = 1; j >= 0; j--) {
        if (j == 1) {
            sum = sum * 10 + a[i];  //số mới tạo thành khi sử dụng a[i]
            float x = cbrt(sum);  //kiểm tra xem số tạo thành có phải số khối lập phương không
            long long y = x / 1;
            //nếu số khối lập phương lớn hơn kết quả hiện tại thì gán kết quả bằng số đó
            if (x - y == 0 && sum > res) res = sum;
            if (i < a.size() - 1) Try(i + 1, sum); //nếu chưa duyệt hết vector a thì ta tiếp tục thử
            sum /= 10; //trả lại số ban đầu khi chưa sử dụng a[i]
        } else {
            if (i < a.size() - 1) Try(i + 1, sum); //nếu chưa duyệt hết vector a thì ta tiếp tục thử
        }
    }
}

void input() {
    cin >> str;
}

void solve() {
    a.clear();  //làm trống vector a
    res = -1; //khởi tạo kết quả
    for (int i = 0; i < str.length(); i++) a.push_back(str[i] - 48); //đưa các chữ số của n vào vector a
    Try(0, 0); //gọi hàm quay lui
    printf("%lld\n", res); //đưa ra kết quả
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}