//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, d[1005][1005];

void input() { //hàm khởi tạo
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++) {
            if (i == j) d[i][j] = 0; //chi phí đi từ i đế chính nó bằng 0
            else d[i][j] = INT_MAX; //khởi tạo không có đường đi từ i đến j
        }
    int i, j, k;
    while (e--) {
        scanf("%d %d %d", &i, &j, &k);
        d[i][j] = k;
    }
}

int isNegativeCycle() {
    for (int k = 1; k <= v; k++) //sử dụng thuật toán Floyd tính đường đi nhỏ nhất giữa các đỉnh
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++) {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
                if (i == j && d[i][j] < 0) return 1;
            }
    return 0;
}

void solve() { //hàm xử lý
    printf("%d\n", isNegativeCycle()); //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}