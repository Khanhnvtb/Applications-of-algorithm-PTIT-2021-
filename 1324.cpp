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
