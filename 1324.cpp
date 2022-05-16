//
// Created by khanh on 10/10/2021.
//

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