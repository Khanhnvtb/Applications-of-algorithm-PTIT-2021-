//
// Created by khanh on 10/11/2021.
//

/*
SỐ KHỐI LẬP PHƯƠNG
Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3 của số Y (X= Y3). Cho số nguyên dương N, nhiệm vụ của bạn là tìm số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N. Ví dụ số 4125 ta có kết quả là 125 = 53.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Nếu không tìm được đáp án in ra -1.
Ví dụ:

Input

2
4125
976

Output

125
-1
*/

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
