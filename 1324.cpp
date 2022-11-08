//
// Created by khanh on 10/10/2021.
//

/*
PHÂN SỐ ĐƠN VỊ
Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi tử số P và mẫu số Q của phân số nguyên dương được viết trên một dòng.
T, P, Q thỏa mãn ràng buộc: 1≤T≤100;  1≤P, Q≤100.
Output:

Đưa ra đáp án tìm được trên 1 dòng, theo dạng “1/a + 1/b + …”
Ví dụ:

Input

2

2 3

1 3

Output

1/2 + 1/6 

1/3
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
#include<bits/stdc++.h>

using namespace std;

long long p, q;

void init() { //hàm khởi tạo
    scanf("%lld %lld", &p, &q);
}

void solve() { //hàm xử lý
    while (1) {
        if (q % p == 0) { //nếu là phân số tối giản
            printf("1/%lld", q / p);
            break;
        } else { //nếu chưa tối giản
            long long n = q / p + 1; //đưa ra phân số đơn vị tiếp theo
            printf("1/%lld + ", n);;
            p = p * n - q; //cập nhật p và q mới bằng cách trừ quy đồng
            q *= n;
        }
    }
    printf("\n");
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
