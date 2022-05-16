//
// Created by khanh on 10/10/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, k, a[1005];

void init() { //hàm khởi tạo
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
}

void solve() {
    int check = 0;
    for (int i = k; i > 1; i--)
        if (a[i] > a[i - 1] + 1) { //nếu phần tử hiện tại lớn hơn phần tử trước nó + 1
            a[i]--; //giảm phần tử hiện tại
            check = 1; //đánh dấu tìm được cấu hình
            for (int j = i + 1; j <= k; j++) a[j] = n - k + j; //gán các phần tử sau nó đến trần
            break;
        }
    if (check == 0) { //nếu không tìm được phần tử thoả mãn
        if (a[1] == 1) { //nếu là cấu hình đầu tiên
            for (int i = 1; i <= k; i++) printf("%d ", n - k + i); //đưa ra cấu hình cuối cùng
            printf("\n");
        } else { //nếu không phải cấu hình đầu tiên
            a[1]--; //giảm phần tử đầu tiên đi 1
            printf("%d ", a[1]);
            for (int i = 2; i <= k; i++) printf("%d ", n - k + i); //gán các phần tử sau đến trần
            printf("\n");
        }
    } else {
        for (int i = 1; i <= k; i++) printf("%d ", a[i]); //đưa ra kết quả
        printf("\n");
    }
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